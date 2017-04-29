/* Defines the helper functions */

#define BUFF_SIZE 100

//Structs used by program
typedef struct {
    double range;
    double bearing;
    int time;
} contact_t;

typedef struct {
    double course;
    double speed;
} ship_t;

typedef struct {
    double x;
    double y;
} vector_t;

typedef struct {
    double range;
    double bearing;
    int time;
    ship_t *contact;
} cpa_return_t;

//Function prototypes
double findSpeed(double dist, int time);
double findDist(double speed, int time);
int findTime(double dist, double speed);

int cpa(ship_t *own_ship, contact_t *contact1, contact_t *contact2, int deltat);
int stationing(ship_t *own_ship, contact_t *contact1, contact_t *contact2,
    int station_range, int station_bearing, int min_dist);
int wind();

ship_t* inputtoship(char *buffer);
contact_t* inputtocontact(char* buffer);
int timepassed(int time1, int time2);
ship_t* find_true(vector_t *own_ship, vector_t *contact, int deltat);
