#include "lista_duplamente_encadeada.c"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    dl_list* a = new_node();
    a = insert(a, 64);
    a = insert(a, 1);
    a = insert(a, 56);
    a = insert(a, 100);
    a = insert(a, 4);
    a = insert(a, 12);
    a = insert(a, 10);
    a = insert(a, 500);

    //dl_list* finish = last_element(a);
    //sort(a, a, finish, 0);

    //dl_list* result = search(a, 500);

    /*if (result != NULL) {
        printf("\n Search = %d", result -> info);
    } else {
        printf("\n Elemento não encontrado");
    }*/

    dl_list* b = new_node();
    b = insert(b, 49);
    b = insert(b, 7);
    b = insert(b, 6);
    
    dl_list* result = merge(a, b);

    print(result);


    //dl_list** out = split(result, 3);

    /*for (int i = 0; i < 3; i++) {
        printf("\n *** %d ****\n", i);
        print(out[i]);
    }*/

    dl_list* out = copy(result);
    print(out);
    

    //print(result);
}