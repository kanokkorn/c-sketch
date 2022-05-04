#define LEN 2
#define TOTAL LEN * 1000

#include <stdio.h>
#include <string.h>

int main(void) {
  char yes[LEN] = {'y', '\n'};
  char *buf = malloc(TOTAL);
  int used = 0;
  while (used < TOTAL) {
    memcpy(buf+used, yes, LEN);
    used += LEN;
  }
  while (write(1, buf, TOTAL));
  return 0;
}

