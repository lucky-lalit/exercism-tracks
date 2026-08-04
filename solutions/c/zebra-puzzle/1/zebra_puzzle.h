#ifndef ZEBRA_PUZZLE_H
#define ZEBRA_PUZZLE_H

typedef struct {
   const char *drinks_water;
   const char *owns_zebra;
} solution_t;

typedef struct{
    char *nationality;
    char *pet;
    char *drink;
    char *hobby;
}parameters_t;

solution_t solve_puzzle(void);

#endif
