#include "space_age.h"
#include <stdio.h>
#include <math.h>

float year[] = {0.2408467,0.61519726,1.0,1.8808158,11.862615,29.447498,84.016846,164.79132};

float age(planet_t planet, int64_t seconds)
{
    if (planet < 0 || planet > 7)
        return -1;
    printf("%i\n %li\n",planet,seconds);
    // printf("%f",year[planet]);
    // return 0;
    
    return (seconds / (year[planet] * 31557600));
}