#include "lista_duplamente_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

dl_list* new_node (void) {
    
    return NULL;
}

dl_list* insert(dl_list* node, int info) {

    dl_list* new = (dl_list*) calloc (1, sizeof(dl_list));
    new -> info = info;
    new -> next = node;
    new -> prev = NULL;

    if (node != NULL) {
        node -> prev = new;
    }

    return new;
}

dl_list* search (dl_list* node, int info) {

    for (dl_list* p = node; p != NULL; p = p -> next) {
        
        if(p -> info == info) {
            return p;
        }
    }

    return NULL;
}

dl_list* remove_node (dl_list* node, int info) {

    dl_list* p = search(node, info);

    if (p == NULL) {
        return node;
    }

    if (node == p) {
        
        node = p -> next;
    } else {

        p -> prev -> next = p -> next;
    }

    free(p);

    return node;
}

int length (dl_list* node) {
    
    int len = 0;

    for (dl_list* p = node; p != NULL; p = p -> next) {
        len++;    
    }

    return len;
}

dl_list* last_element (dl_list* node) {
    
    dl_list* p = NULL;
    
    for (p = node; p -> next != NULL; p = p -> next);

    return p;
}

dl_list* merge(dl_list* a, dl_list* b) {

    dl_list* concat = new_node();

    for (dl_list* p = last_element(b); p != NULL; p = p->prev)
    {
        concat = insert(concat, p->info);
    }
    
    for (dl_list* p = last_element(a); p != NULL; p = p->prev)
    {
        concat = insert(concat, p->info);
    }

    return concat;
}

dl_list** split (dl_list* nodes, int k){

    dl_list** pieces = (dl_list**) calloc (k, sizeof(dl_list*));
    dl_list* p = last_element(nodes);
    
    int len = length(nodes)/k;

    for (int i = 0; i < k; i++) {
        
        pieces[i] = new_node();

        if (i == k - 1) {

            len = len + (length(nodes)%k);
        }
        
        for (int j = 0; j < len; j++) {

            pieces[i] = insert(pieces[i], p->info);
            p = p -> prev;
        }
    }

    return pieces;
}

dl_list* copy(dl_list* nodes) {
    
    dl_list* new = new_node();

    for (dl_list* p = last_element(nodes); p != NULL; p = p -> prev) {
        new = insert(new, p -> info);
    }
    
    return new;
}

void print(dl_list* data) {

    dl_list* p;

    for(p = data; p!=NULL; p = p -> next) {
        printf("info = %d\n", p->info);
    }
    
    printf("\n");
}

// Implementação do Quicksort
dl_list* sort(dl_list* nodes, dl_list* start, dl_list* finish, int type) {

    //print(nodes);
    //print(start);
    //print(finish);

    if (nodes != NULL && start != NULL && finish != NULL) {

        printf("Dentro do if");

        dl_list* pivot = finish;
        dl_list* smaller = start;
        int aux = 0;

        printf("\n\nPivot = %d", pivot->info);
        printf("\nSmaller = %d", smaller->info);
        printf("\n\n ------------------\n\n");

        for (dl_list* p = start; p != finish->next; p = p -> next) {

            printf("\n\n P = %d", p->info);
            printf("\n Smaller = %d", smaller->info);
            printf("\n Pivot = %d", pivot->info);
            printf("\n*************\n");

            if (p -> info <= pivot -> info && p != smaller) {

                if (p->info < smaller->info) {

                    printf("\n\n TROCA \n\n");

                    aux = p -> info;
                    p -> info = smaller -> info;
                    smaller -> info = aux;
                }

                if ( p == pivot ) {
                    pivot = smaller;
                }

                smaller = smaller -> next;
            }
        }

        if (smaller -> info < pivot -> info) {

            aux = pivot -> info;
            pivot -> info = smaller -> info;
            smaller -> info = aux;

            pivot = smaller;  
        }      

        printf("\n\n FINAL PIVOT\n");
        print(pivot);
        printf("\n START\n");
        print(start);
        printf("\n FINISH\n");
        print(finish);
        printf("\nNodes\n");
        print(nodes);

        if (pivot != start) {
            sort(nodes, start, pivot, type);
        }

        if (pivot != finish) {
            sort(nodes, pivot -> next, finish, type);
        }

        // ordem crescente
        //if (type == 0) {

        return start;
    
        // ordem decrescente
        /*} else {
        
            return finish;
        } */
    }
}