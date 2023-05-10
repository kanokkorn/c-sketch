#include <stdio.h>
#include <stdlib.h>

struct node {
  char* name;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void show_list(void) {
  struct node *point = head;
  while (point != NULL) {
    printf("%s\n", point->name);
    point = point->next;
  }
}

void add_list(char* name) {
  struct node *data = (struct node *) malloc(sizeof(struct node));
  data->name = name;
  data->next = head;
  head = data;
}

int main(void) {
  int x;
  for (x=0; x<1000; x++) {
    add_list("name name name name");
  }
  show_list();
  return 0;
}
