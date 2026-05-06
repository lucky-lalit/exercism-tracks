#include "eliuds_eggs.h"
#include <stdio.h>

unsigned int egg_count(unsigned int input)
{   
    int count = 0;
    while(input != 0)
    {
        if (input % 2  != 0)
        {
            count++;
        }
        input = input / 2;
    }
    return count;
}