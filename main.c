/* Main calculating file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Please give the proper argument:\n"
        " -c for Closest Point of Approach\n -s for Stationing\n -w for Wind\n");
        return -1;
    }
    
    char in_buffer[BUFF_SIZE];
    
    if (!strcmp(argv[1], "-c")) {
        printf("Beginning CPA Problem...\n");
        int time1, time2;
        printf("\n***Own Ship***\n");
        ship_t *own_ship = inputtoship(in_buffer);
        printf("\n***Contact***\n");
        contact_t *contact1 = inputtocontact(in_buffer);
        contact_t *contact2 = inputtocontact(in_buffer);
        printf("********************\n");
        cpa(own_ship, contact1, contact2, timepassed(contact1->time, contact2->time));
        free(own_ship);
        free(contact1);
        free(contact2);
    } else if (!strcmp(argv[1], "-s")) {
        printf("Beginning Stationing Problem...\n");
        printf("\n***Own Ship***\n");
        ship_t *own_ship = inputtoship(in_buffer);
        printf("\n***Guide***\n");
        contact_t *contact1 = inputtocontact(in_buffer);
        contact_t *contact2 = inputtocontact(in_buffer);
        printf("\n***Stationing Parameters***\n");
        printf("Stationing Range: ");
        fgets(in_buffer, BUFF_SIZE, stdin);
        int station_range = strtol(in_buffer, NULL, 10);
        printf("Stationing Bearing (relative): ");
        fgets(in_buffer, BUFF_SIZE, stdin);
        int station_bearing = strtol(in_buffer, NULL, 10);
        printf("Minimum Distance to Maintain: ");
        fgets(in_buffer, BUFF_SIZE, stdin);
        int min_dist = strtol(in_buffer, NULL, 10);
        printf("********************\n");
        stationing(own_ship, contact1, contact2, station_range, station_bearing, min_dist);
        free(own_ship);
        free(contact1);
        free(contact2);
    } else if (!strcmp(argv[1], "-w")) {
        printf("Beginning Wind Problem...\n");
        printf("\n***Own Ship***\n");
        ship_t *own_ship = inputtoship(in_buffer);
        printf("\n***Wind Parameters***\n");
        printf("True Wind: ");
        printf("Relative Wind: ");
        printf("Desired Relative Wind: ");
        printf("********************\n");
        wind();
        free(own_ship);
    } else {
        printf("Please give the proper argument:\n"
        " -c for Closest Point of Approach\n -s for Stationing\n -w for Wind\n");
        return -1;
    }
    
    return 0;
}
