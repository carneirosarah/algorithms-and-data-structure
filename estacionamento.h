#ifndef ESTACIONAMENTO_H
#define ESTACIONAMENTO_H

struct car {
    char license_plate[8];
    int maneuvers;
    struct car* next;
};

typedef struct car car;

struct parking {

    car* start;
    car* finish;
};

typedef struct parking parking;

parking* new_praking ();
parking* car_arrives (parking* p, char* plate);
parking* car_leaves (parking* p, char* plate);
int is_empty(parking* p);
int length (parking* p);
void print(parking* data);


#endif