#include "lista_encadeada.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    list* a = new_node();

    a = insert(a, 5);
    a = insert(a, 6);
    a = insert(a, 9);
    a = insert(a, 1);

    print(a);
    printf("\nLista Invertida\n\n");
    print(reverse(a));
    return 0;
}