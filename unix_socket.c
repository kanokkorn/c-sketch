#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

const char* quit = "exit";

int main() {
  // Create a socket.
  int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to a path.
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "/tmp/my_socket", sizeof(addr.sun_path) - 1);
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for connections.
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    exit(1);
  }

  // Accept connections and print the messages sent by the clients.
  while (1) {
    int clientfd = accept(sockfd, NULL, NULL);
    if (clientfd < 0) {
      perror("accept");
      exit(1);
    }

    char buffer[1024];
    ssize_t bytes_read = read(clientfd, buffer, sizeof(buffer)+1);
    if (bytes_read < 0) {
      perror("read");
      exit(1);
    }

    printf("Received message from client: %s\n", buffer);
    if (!strcmp(quit, buffer)) {
      printf("exit received. quiting...");
      exit(1);
    }

    close(clientfd);
  }

  return 0;
}

