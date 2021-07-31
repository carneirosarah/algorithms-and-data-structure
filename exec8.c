#include "lista_encadeada.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


list* get_union (list* a, list* b) {

    list* union_set = new_node();
    list* result = NULL;

    for (list* p = b; p != NULL; p = p->next) {
        union_set = insert(union_set, p->info);
    }
    
    for (list* p = a; p != NULL; p = p->next) {
        
        result = search(union_set, p->info);

        if (result == NULL) {
            
            union_set = insert(union_set, p->info);
        }
    }

    return union_set;
}

list* get_intersec(list* a, list* b) {

    list* p = a;
    list* intersec = new_node();
    list* result = NULL;

    while (p != NULL) {

        result = search(b, p->info);
        
        if (result != NULL) {
            intersec = insert(intersec, result->info);
        }
        p = p -> next;
    }

    return intersec;
}

list* get_complement(list* a, list* b) {

    list* p = a;
    list* complement = new_node();
    list* result = NULL;

    while (p != NULL) {

        result = search(b, p->info);
        
        if (result == NULL) {
            complement = insert(complement, p->info);
        }

        p = p -> next;
    }

    return complement;
}

bool membership(list* data, int value) {

    if (search(data, value) == NULL) {
        return false;
    }

    return true;
}

int main(void) {

    list* a = new_node();
    list* b = new_node();

    a = insert(a, 5);
    a = insert(a, 6);
    a = insert(a, 9);
    a = insert(a, 1);

    b = insert(b, 10);
    b = insert(b, 5);
    b = insert(b, 6);
    b = insert(b, 7);
    b = insert(b, 50);

    printf("\nUnião\n\n");
    list* result = get_union(a, b);
    print(result);

    free_list(result);

    printf("\nInterseção\n\n");
    result = get_intersec(a, b);
    print(result);

    free_list(result);

    printf("\nComplemento\n\n");
    result = get_complement(b, a);
    print(result);

    free_list(result);

    bool flag = membership(a, 0);

    if (flag){
        printf("O elemento %d é membro do conjunto: \n", 0);
        print(a);
    } else {
        printf("O elemento %d não é membro do conjunto: \n", 0);
        print(a);
    }


    return 0;
}