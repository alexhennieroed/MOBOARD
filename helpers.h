/* Defines the helper functions */

#define BUFF_SIZE 100

//Structs used by program
typedef struct {
    int range;
    int bearing;
    int time;
} contact_t;

typedef struct {
    int course;
    double speed;
} ship_t;

//Function prototypes
double findSpeed(int dist, double time);
int findDist(double speed, double time);
double findTime(int dist, double speed);

int cpa(ship_t *own_ship, contact_t *contact1, contact_t *contact2, int deltat);
int stationing();
int wind();

ship_t* inputtoship(char *buffer);
contact_t* inputtocontact(char* buffer);
int timepassed(int time1, int time2);
