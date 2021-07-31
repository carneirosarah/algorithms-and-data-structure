#include <stdio.h>
#include <stdlib.h>

void calc_first_derivative (int n, int * coefficients) {
    
    coefficients[0] = 0;

    for (int i = 2; i <= n; i++) {
        coefficients[i] = coefficients[i] * i;
    }

}


int main(void) {
    
    FILE *file = fopen("in_exec7.txt", "r");
    int n = 0; // polynomial degree
    int i = 0;

    // First line of the file corresponds to polynomial degree
    fscanf(file, "%d\n", &n);

    int * coefficients = (int*) calloc(n+1, sizeof(int));

    while (fscanf(file, "%d\n", &(coefficients[i])) != EOF) {
        //printf("coefficients[%d] = %d", i, coefficients[i]);
        i++;
    }

    calc_first_derivative (n, coefficients);

    for (int i = 0; i <= n; i++) {
        printf("%d ", coefficients[i]);
    }

}