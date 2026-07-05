#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H
#include <stdbool.h>

typedef enum { CLOVER = 0, GRASS = 1, RADISHES = 2, VIOLETS = 3 } plant_t;

typedef struct {
   plant_t plants[4];
} plants_t;

// void kindergarden_garden(char *diagram,char *student,plant_t plants);
plants_t plants(const char *diagram,const char *student);

#endif
