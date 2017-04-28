/* Main calculating file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Please give the proper arguments:\n"
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
        printf("Enter a value: ");
        fgets(in_buffer, 50, stdin);
        stationing();
    } else if (!strcmp(argv[1], "-w")) {
        printf("Enter a value: ");
        fgets(in_buffer, 50, stdin);
        wind();
    } else {
        printf("Please give the proper arguments:\n"
        " -c for Closest Point of Approach\n -s for Stationing\n -w for Wind\n");
        return -1;
    }
    
    return 0;
}
