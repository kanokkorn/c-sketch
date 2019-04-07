#include <stdio.h>

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}

void guessNumber(int guess) {
    if (guess == 555){
        printf("Correct. You guessed it!");
    } else if (guess > 555){
        printf("Your guess is too high.\n");
    } else if (guess < 555){
        printf("Your guess is too low.\n");
    }
}