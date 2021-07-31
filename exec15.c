#include "deque.c"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    deque* data = new_deque(10);
    data = insert_left (data, 7);
    data = insert_rigth(data, 10);
    data = remove_left(data);
    data = remove_rigth(data);
    data = remove_left(data);

    printf("Start: %d \n", data -> start);
    printf("finish: %d \n", data -> finish);
    printf("len: %d \n", data -> len);

    data = insert_left (data, 7);
    data = insert_left (data, 3);
    data = insert_rigth (data, 4);
    data = insert_rigth (data, 6);
    data = insert_left (data, 2);
    data = insert_rigth (data, 1);
    data = insert_left (data, 8);
    data = insert_rigth (data, 5);
    data = insert_left (data, 9);
    data = insert_left (data, 1);
    data = insert_left (data, 2);

    printf("Start: %d \n", data -> start);
    printf("finish: %d \n", data -> finish);
    printf("len: %d \n", data -> len);


    print(data);
}