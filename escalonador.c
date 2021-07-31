#include "escalonador.h"
#include <stdio.h>
#include <stdlib.h>

scheduler* new_scheduler () {

    scheduler* new = (scheduler*) calloc(1, sizeof(scheduler));
    new -> start = NULL;
    new -> finish = NULL;
    return new;
}

scheduler* insert_process (scheduler* processes, int id) {

    process* p = (process*) calloc(1, sizeof(process));
    p -> id = id;
    p -> next = NULL;

    if (processes -> finish != NULL) {

        processes -> finish -> next = p;
        processes -> finish = p;

    } else {

        processes -> start = p;
        processes -> finish = p;
    }

    printf("\nProcesso %d inserido com sucesso.\n", id);

    return processes;
}

int is_empty (scheduler* s) {
    
    return (s -> start == NULL && s -> finish == NULL);
}

scheduler* remove_process(scheduler* processes) {

    if (is_empty(processes)) {

        printf("Fila Vazia. \n");
    }else {

        process* aux = processes -> start;

        processes -> start = aux -> next;

        if (processes -> start == NULL) {

            processes -> finish = NULL;
        }

        printf("\nProcesso %d removido com sucesso.\n", aux->id);

        free(aux);
    }

    return processes;
}

void print(scheduler* processes) {

    for(process* p = processes -> start; p != NULL; p = p -> next) {

        printf("process = %d\n", p->id);
    }
}