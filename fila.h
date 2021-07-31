#ifndef FILA_H
#define FILA_H

struct element {
    int size;
    int* values;
    struct element* next;
};

typedef struct element element;

struct queue {

    element* start;
    element* finish;
};

typedef struct queue queue;

queue* new_queue ();
queue* insert (queue* data, int* values, int size);
queue* remove_element (queue* data);
int is_empty(queue* p);
void free_queue (queue* data);
void print(queue* data);

#endif