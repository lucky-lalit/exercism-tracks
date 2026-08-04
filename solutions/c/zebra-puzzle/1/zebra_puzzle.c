#include "zebra_puzzle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
solution_t solve_puzzle(void)
{
    parameters_t houses[5];
    solution_t solution;
    houses[0].nationality = "Englishman";
    houses[0].pet = "horse";
    houses[0].drink = "orange_juice";
    houses[0].hobby = "football";
    houses[1].nationality = "Ukranian";
    houses[1].pet = "fox";
    houses[1].drink = "tea";
    houses[1].hobby = "painter";
    houses[2].nationality = "Spainard";
    houses[2].pet = "dog";
    houses[2].drink = "reading";
    houses[2].hobby = "milk";
    houses[3].nationality = "Norwegian";
    houses[3].pet = "snail";
    houses[3].drink = "not_found";
    houses[3].hobby = "dancer";
    houses[4].nationality = "Japanese";
    houses[4].pet = "not_found";
    houses[4].drink = "coffee";
    houses[4].hobby = "chess";

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(houses[i].drink,"not_found") == 0)
            solution.drinks_water = houses[i].nationality;
        if (strcmp(houses[i].pet,"not_found") == 0)
            solution.owns_zebra = houses[i].nationality;
    }
    
    return solution;
}