#include <stdio.h>

unsigned int factorial(unsigned int x){
    if (x == 1){
        return x;
    } else if (x > 1){
        return x * factorial(x-1);
    } else return 0;
}

int main() {
    
    printf("1! = %d\n", factorial(1));
    printf("3! = %d\n", factorial(3));
    printf("5! = %d\n", factorial(5));
}
