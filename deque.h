#ifndef DEQUE_H
#define DEQUE_H


struct deque {

    int len;
    int capacity;
    int start;
    int finish;
    int * vec;
};

typedef struct deque deque;

deque * new_deque (int capacity);
deque* insert_left (deque* data, int value);
deque* insert_rigth (deque* data, int value);
deque* remove_left (deque* data);
deque* remove_rigth (deque* data);
void print (deque* data);

#endif