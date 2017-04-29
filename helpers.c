/* Helper functions for the program */

#define PI (22.0/7.0)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

double findSpeed(double dist, int time) {
    dist = dist / 2025.372;
    double t = ((double) time) / 60.0;
    return dist / t;
}

double findDist(double speed, int time) {
    return speed * time;
}

int findTime(double dist, double speed) {
    return ceil(dist / speed);
}

double distance(vector_t *vector) {
    return ceil(sqrt(pow(vector->x, 2) + pow(vector->y, 2)));
}

vector_t* unit_vec(vector_t *vector) {
    vector_t *ans = malloc(sizeof(vector_t));
    
    double mag = distance(vector);
    ans->x = (vector->x) / mag;
    ans->y = (vector->y) / mag;
    
    return ans;
}

int cpa(ship_t *own_ship, contact_t *contact1, contact_t *contact2, int deltat) {
    vector_t *ship_vec = malloc(sizeof(vector_t));
    vector_t *contact_vec = malloc(sizeof(vector_t));
    ship_t *return_ship = malloc(sizeof(ship_t));
    
    double owncourseedit = own_ship->course + 90.0;
    if (owncourseedit >= 360.0) { owncourseedit -= 360.0; }
    ship_vec->x = (own_ship->speed / 5.0) * cos(owncourseedit * (PI / 180.0));
    ship_vec->y = (own_ship->speed / 5.0) * sin(owncourseedit * (PI / 180.0));
    
    double c1bearingedit = contact1->bearing + 90.0;
    if (c1bearingedit >= 360.0) { c1bearingedit -= 360.0; }
    double start_x = (contact1->range / 1000.0) * cos(c1bearingedit * (PI / 180.0));
    double start_y = (contact1->range / 1000.0) * sin(c1bearingedit * (PI / 180.0));
    
    double c2bearingedit = contact2->bearing + 90.0;
    if (c2bearingedit >= 360.0) { c2bearingedit -= 360.0; }
    double end_x = (contact2->range / 1000.0) * cos(c2bearingedit * (PI / 180.0));
    double end_y = (contact2->range / 1000.0) * sin(c2bearingedit * (PI / 180.0));
    
    contact_vec->x = end_x - start_x;
    contact_vec->y = end_y - start_y;
    
    return_ship = find_true(ship_vec, contact_vec, deltat);
    printf("True speed: %lf\n", return_ship->speed);
    printf("True course: %lf\n", return_ship->course);
    
    double rel_speed = findSpeed(distance(contact_vec), deltat);
    
    free(ship_vec);
    free(contact_vec);
    return 0;
}

int stationing(ship_t *own_ship, contact_t *contact1, contact_t *contact2,
    int station_range, int station_bearing, int min_dist) {
    //TODO
    return 0;
}

int wind() {
    //TODO
    return 0;
}

ship_t* inputtoship(char *buffer) {
    ship_t *own_ship = malloc(sizeof(ship_t));
        
    printf("Ship course: ");
    fgets(buffer, BUFF_SIZE, stdin);
    own_ship->course = strtod(buffer, NULL);
        
    printf("Ship speed: ");
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
    contact->range = strtod(buffer, NULL);
        
    printf("Contact bearing: ");
    fgets(buffer, BUFF_SIZE, stdin);
    contact->bearing = strtod(buffer, NULL);
    
    return contact;
}

ship_t* find_true(vector_t *own_ship, vector_t *contact, int deltat) {
    ship_t *true_ship = malloc(sizeof(ship_t));

    double rel_speed = findSpeed(distance(contact) * 1000.0, deltat);
    printf("Relative Speed: %lf\n", rel_speed);
    vector_t *relative = unit_vec(contact);
    relative->x = relative->x * (rel_speed / 5);
    relative->y = relative->y * (rel_speed / 5);
    
    double true_x = own_ship->x + relative->x;
    double true_y = own_ship->y + relative->y;
    
    true_ship->speed = 5.0 * sqrt(pow(true_x, 2.0) + pow(true_y, 2.0));
    double bearing_radians = atan(true_y / true_x);
    double bearing_degrees = bearing_radians * (180.0 / PI);
    double bdedited = bearing_degrees - 90.0;
    if (bdedited < 0) { bdedited += 360.0; }
    true_ship->course = bdedited;
    
    return true_ship;
}

int timepassed(int time1, int time2) {
    int t1hour = time1 / 100;
    int t1min = time1 % 100;
    time1 = (t1hour * 60) + t1min;
    
    int t2hour = time2 / 100;
    int t2min = time2 % 100;
    time2 = (t2hour * 60) + t2min;
    
    return time2 - time1;
}
