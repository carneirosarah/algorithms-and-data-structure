#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Check if a matrix is a permutation matrix
*/
int isPermutationMatrix(int n, float ** matrix) {

    bool find_one = false;

    // Line Search: Garantes that matrix has only zeros and ones and one number 1 for each line
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 1) {
                // If matrix has more than one number 1 in line
                if (find_one) {
                    return 0;
                } else {
                    find_one = true;
                }
            // If matrix has a number different than 0 and 1                
            } else if (matrix[i][j] != 0) {
                return 0;
            }
        }
        
        if (find_one) {
            find_one = false;
        // If matrix has a line only with zeros, there's no number 1
        } else {
            return 0;
        }
    }

    // Column Search: Garantes that matrix has one number 1 for each column
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {

            if (matrix[i][j] == 1) {
                
                // If matrix has more than one number 1 in column
                if (find_one) {
                    return 0;
                } else {
                    find_one = true;
                }                
            }
        }
        if (find_one) {
            find_one = false;
        
        // If matrix has a column only with zeros, there's no number 1
        } else {
            return 0;
        }
    }

    return 1;
}

int main(void) {

    FILE *file = fopen("in_exec6.txt", "r");
    int n = 0; // matrix size
    int i, j = 0;

    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    // First line of the file corresponds to matrix size
    fscanf(file, "%d\n", &n);
    //printf("%d\n" , n);
    
    float * matrix[n];
    for (int index = 0; index < n; index++) {
        matrix[index] = (float*) calloc(n, sizeof(float));
    }
    

    while (fscanf(file, "%f\n", &(matrix[i][j])) != EOF) {
        
        //printf("matrix[%d][%d] = %f\n", i, j, matrix[i][j]);
        
        j++;

        if (j%n == 0) {
            j = 0;
            i++;
        }
    }
    
    fclose(file);

    bool isPermutation = isPermutationMatrix(n, matrix);

    if (isPermutation) {
        printf("É uma matriz de permutação\n");
    } else {
        printf("Não é uma matriz de permutação\n");
    }
    
    return 0;
}