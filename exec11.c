#include "estacionamento.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *file = fopen("in_exec11.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    char action;
    char plate[8];
    int parking_lots = 10;

    parking* p = new_praking();

    while (fscanf(file, "%c %s\n", &action, &plate) != EOF) {

        if (action == 'E') {

            p = car_arrives(p, plate);
            //print(p);

        } else {

            p = car_leaves(p, plate);
            //print(p);

        }
    }
    
    fclose(file);
    return 0;
}