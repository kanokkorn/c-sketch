#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/* not a prime number */
#define HASH_SIZE 69

typedef struct {
  char* key;
  void* data;
  struct DataItem* next;
} DataItem;

DataItem* table[HASH_SIZE];

/* hash table */
int hashCode(char* key) {
  int sum = 0;
  while (*key) {
    sum += *key++;
  }
  return sum % HASH_SIZE;
}

void insert(char* key, void* value) {
  int idx = hashCode(key);
  DataItem* new_item = (DataItem*)malloc(sizeof(DataItem));
  new_item->key = strdup(key);
  new_item->data = value;
  new_item->next = NULL;

  if (table[idx]== NULL) {
    table[idx] = new_item;
  } else {
    DataItem* curr = table[idx];
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_item;
  }
}

void* search(char* key) {
  int idx = hashCode(key);
  DataItem* curr = table[idx];
  while (curr != NULL) {
    if (strcmp(curr->key, key) == 0) {
      return curr->data;
    }
    curr = curr->next;
  }
}


/* delete this */
void* delete(char* key) {
  /* not implement */
}

int main(int argc, char *argv[]) {
  insert("apple", "red");
  insert("banana", "yellow");
  char* value = (char*)search("apple");
  if (value != NULL) {
    printf("Value for 'apple': %s\n", value);
  } else {
    printf("Key not found \n");
  }
  return 0;
}
