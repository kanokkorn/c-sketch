#include <stdio.h>

int sum (int num) {
  static int x;
  x += num;
  return x;
}

int main(void) {
  printf("%d ",sum(55));
  printf("%d ",sum(45));
  printf("%d ",sum(50));
  return 0;
}

