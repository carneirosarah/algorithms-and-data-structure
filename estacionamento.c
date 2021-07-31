#include "estacionamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

parking* new_praking () {

    parking* new = (parking*) calloc(1, sizeof(parking));
    new -> start = NULL;
    new -> finish = NULL;
    return new; 
}

parking* car_arrives (parking* p, char* plate) {

    if (length(p) < 10) {

        car* c = (car*) malloc(sizeof(car));
    
        strcpy(c -> license_plate, plate);
        c -> maneuvers = 0;
        c -> next = NULL;

        if ( p -> finish != NULL) {
        
            p -> finish -> next = c;
            p -> finish = c;
    
        } else {
        
            p -> start = c;
            p -> finish = c;
        }

        printf("O carro %s chegou. Há vaga diponível.\n", plate);
    } else {

        printf("O carro %s chegou. Mas, não há vagas diponíveis.\n", plate);
    }

    return p;
}

parking* car_leaves (parking* p, char* plate) {

    if (is_empty(p)) {
        
        printf("\nEstacionamento vazio\n");
    } else {

        car* prev = NULL;
        
        for (car* i = p -> start; i != NULL; i = i -> next) {
            
            if (strcmp(i -> license_plate, plate) == 0) {

                if (prev == NULL) {

                    p -> start = i -> next;
                
                } else if (i -> next == NULL){

                    p -> finish = prev;
                    prev -> next = NULL;

                } else {

                    prev -> next = i -> next;
                }
                
                printf("O carro %s saiu e realizou %d manobras\n", plate, i -> maneuvers);

                free(i);
                break;

            } else {
                i -> maneuvers = i -> maneuvers + 1;
                prev = i;
            }
        }
    }

    return p;
}

int is_empty(parking* p) {
    
    return (p -> start == NULL && p -> finish == NULL);
}

int length (parking* p) {
    
    int len = 0;

    for (car* c = p -> start; c != NULL; c = c -> next) {
        len++;    
    }

    return len;
}

void print(parking* data) {

    car* p;

    for(p = data -> start; p!=NULL; p = p -> next) {
        printf("info = %s\n", p->license_plate);
    }

    printf("\n");
}