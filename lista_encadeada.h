 #ifndef LISTA_ENCADEADA_H
 #define LISTA_ENCADEADA_H

struct list {
    int info;
    struct list* next;
};

typedef struct list list;

list* new_node (void);
list* insert(list* node, int value);
list* search (list* data, int value);
list* delete_node (list* data, int value);
void free_list (list* data);
void print(list* data);
int is_empty(list* data);

 #endif