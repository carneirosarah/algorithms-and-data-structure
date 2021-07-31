#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

deque * new_deque (int capacity) {

    deque* new = (deque*) calloc (1, sizeof(deque));
    new -> capacity = capacity;
    new -> len = 0;
    new -> start = -1;
    new -> finish = 0;
    new -> vec = (int*) calloc (capacity, sizeof(int));

    return new;
}

deque* insert_left (deque* data, int value) {

    if (data -> len == data -> capacity) {
        
        printf("Capacidade do deque estorou!\n");
        return data;

    } else {
        
        data -> start++;
        data -> vec [data -> start] = value;
        data -> len++;
    }

    return data;
}

deque* insert_rigth (deque* data, int value) {

    if (data -> len == data -> capacity) {
        
        printf("Capacidade do deque estorou!\n");
        return data;
        
    } else {

        if (data -> finish == 0) {

            data -> finish = data -> capacity - 1;
        
        } else {

            data -> finish--;
        }

        data -> vec [data -> finish] = value;
        data -> len++;
    }

    return data;
}

deque* remove_left (deque* data) {

    if (data -> len == 0) {
        
        printf("Deque vazio!\n");
        return data;
    
    } else if (data -> start == 0){

        data -> start = - 1;
        data -> len --;
    
    } else {

        data -> start--; 
        data -> len--;
    }

    return data;
}

deque* remove_rigth (deque* data) {

    if (data -> len == 0) {
        
        printf("Deque vazio!\n");
        return data;
    
    } else if (data -> finish == data -> capacity - 1){

        data -> finish = 0;
        data -> len --;
    
    } else {

        data -> finish++; 
        data -> len--;
    }

    return data;
}

void print (deque* data) {

    if (data -> start >= 0) {

        for (int i = 0; i <= data -> start; i++) {
            printf("vec[%d] = %d \n", i, data -> vec[i]);
        }        
    }

    if (data -> finish > 0) {

        for (int i = data -> finish; i < data -> capacity; i++) {
            printf("vec[%d] = %d \n",i, data -> vec[i]);
        }
    }
}