#include "dnd_character.h"
#define _DEFAULT_SOURCE
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int modifier(int score)
{    
    return floor((score - 10.0) / 2);
}
int ability(void)
{
    srandom(time(NULL));
    int arr[4];
    int smallest = 7;
    int top_three = 0;
        for(int i = 0; i < 4; i++)
    {
        arr[i] = 1 + random() % 6;
    }
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    for (int i = 0; i < 3; i++)
    {
        if(arr[i] == smallest)
        {}
        top_three += arr[i];
    }
    return top_three;
}
dnd_character_t make_dnd_character(void)
{
    dnd_character_t result;
    result.strength = ability();
    result.dexterity = ability();
    result.constitution = ability();
    result.intelligence = ability();
    result.wisdom = ability();
    result.charisma = ability();
    result.hitpoints = modifier(ability()) + 10;
    return result;
}