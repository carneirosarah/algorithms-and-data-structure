#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

queue* new_queue () {

    queue* new = (queue*) calloc(1, sizeof(queue));
    new -> start = NULL;
    new -> finish = NULL;
    return new; 
}

queue* insert (queue* data, int* values, int size) {
    
    element* aux = (element*) calloc(1, sizeof(element));
    aux -> size = size;
    aux -> values = values;
    aux -> next = NULL;

    if (data -> finish != NULL) {
        
        data -> finish -> next = aux;
        data -> finish = aux;
    } else {

        data -> start = aux;
        data -> finish = aux;
    }

    return data;
}

queue* remove_element (queue* data) {
    
    if (is_empty(data)) {

        printf("Fila Vazia. \n");
    }else {

        element* aux = data -> start;

        data -> start = aux -> next;

        if (data -> start == NULL) {

            data -> finish = NULL;
        }

        free(aux);
    }

    return data;
}

int is_empty(queue* p) {
    
    return (p -> start == NULL && p -> finish == NULL);
}

void free_queue (queue* data) {

    for (element* p = data -> start; p != NULL; p = p -> next) {
        free(p);
    }
    
    free(data);
}

void print(queue* data) {

    for(element* p = data -> start; p!=NULL; p = p -> next) {

        for (int i = 0; i < p -> size; i++) {

            printf("info = %d\n", p->values[i]);
        }

        printf("\n");
    }
}