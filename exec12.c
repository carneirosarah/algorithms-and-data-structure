#include "pilha.c"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int number = 3960;

    stack* prime_factors = new_stack();

    while (number != 1) {

        for (int i = 2; i <= number; i++) {

            if (number % i == 0) {

                number = number / i;
                prime_factors = push(prime_factors, i);
                break;
            }
        }
    }

    print(prime_factors);
}