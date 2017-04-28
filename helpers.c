/* Helper functions for the program */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

double findSpeed(int dist, double time) {
    return ((double) dist) / time;
}

int findDist(double speed, double time) {
    return (int) (speed * time);
}

double findTime(int dist, double speed) {
    return ((double) dist) / speed;
}

int cpa(ship_t *own_ship, contact_t *contact1, contact_t *contact2, int deltat) {
    //TODO
    printf("Own Ship Data\n- course: %d\n- speed: %lf\n", own_ship->course, own_ship->speed);
    printf("Contact1 Data\n- range: %d\n- bearing: %d\n", contact1->range, contact1->bearing);
    printf("Contact2 Data\n- range: %d\n- bearing: %d\n", contact2->range, contact2->bearing);
    printf("Time Change: %d\n", deltat);
    return 0;
}

int stationing() {
    //TODO
    printf("Beginning Stationing Problem...\n");
    return 0;
}

int wind() {
    //TODO
    printf("Beginning Wind Problem...\n");
    return 0;
}

ship_t* inputtoship(char *buffer) {
    ship_t *own_ship = malloc(sizeof(ship_t));
        
    printf("Own Ship course: ");
    fgets(buffer, BUFF_SIZE, stdin);
    own_ship->course = strtol(buffer, NULL, 10);
        
    printf("Own Ship speed: ");
    fgets(buffer, BUFF_SIZE, stdin);
    own_ship->speed = strtod(buffer, NULL);
    
    return own_ship;
}

contact_t* inputtocontact(char* buffer) {
    contact_t *contact = malloc(sizeof(contact_t));
    
    printf("Time: ");
    fgets(buffer, BUFF_SIZE, stdin);
    contact->time = strtol(buffer, NULL, 10);
        
    printf("Contact range: ");
    fgets(buffer, BUFF_SIZE, stdin);
    contact->range = strtol(buffer, NULL, 10);
        
    printf("Contact bearing: ");
    fgets(buffer, BUFF_SIZE, stdin);
    contact->bearing = strtol(buffer, NULL, 10);
    
    return contact;
}

int timepassed(int time1, int time2) {
    return time2 - time1;
}
