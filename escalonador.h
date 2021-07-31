#ifndef ESCALONADOR_H
#define ESCALONADOR_H

struct process {
    int id;
    struct process* next;
};

typedef struct process process;

struct scheduler {

    process* start;
    process* finish;
};

typedef struct scheduler scheduler;

scheduler* new_scheduler ();
scheduler* insert_process (scheduler* processes, int id);
int is_empty (scheduler* s);
scheduler* remove_process(scheduler* processes);
void print(scheduler* processes);

#endif