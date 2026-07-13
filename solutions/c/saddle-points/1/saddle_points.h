#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H
#include <stdint.h>
#include <stddef.h>

// typedef saddle_point_t saddle_points_t;
typedef struct{
    uint8_t row;
    uint8_t column;
}saddle_point_t;

typedef struct{
    size_t count;
    saddle_point_t *points;
}saddle_points_t;

// typedef saddle_points_t saddle_point_t;

saddle_points_t *saddle_points(uint8_t row,uint8_t column,uint8_t (*matrix)[column]);

void free_saddle_points(saddle_points_t *result);
#endif
