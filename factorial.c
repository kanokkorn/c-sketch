#include <stdio.h>

int main(void) {
  int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int factorial = 1;
  int i;

  for(i=0;i<10;i++){
    factorial *= array[i];
  }

  printf("10! is %d.\n", factorial);
  return 0;
}
