#include "fila.c"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    FILE *file = fopen("in_exec13.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    int n = 0;
    int* values = NULL;
    queue* data = new_queue();

    while (fscanf(file, "%d", &n) != EOF) {

        values = (int*) calloc(n, sizeof(int));

        for (int i = 0; i < n; i++) {
            
            if (i == n - 1) {

                fscanf(file, "%d \n", &values[i]);

            } else {

                fscanf(file, "%d ", &values[i]);
            }
        }

        data = insert(data, values, n);
    }

    print(data);


    fclose(file);
    return 0;
}