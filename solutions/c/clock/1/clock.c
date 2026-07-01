#include "clock.h"
#include <stdio.h>
#include <string.h> 
#include <math.h>
clock_t clock_create(int hour, int minute)
{
    printf("clock_create\n");
    clock_t result;
    // // result.text[0] = '0';
    // sprintf(result.text,"%02d:%02d",((((hour % 24) + 24) % 24) +  (int)floor((double)minute / 60)) ,((minute % 60) + 60) % 60);
    // printf("%i\n",hour);
    // printf("%i\n",minute);
    // return result;
    int final_minutes = ((minute % 60) + 60) % 60;
    
    // 2. Calculate how many full hours are hidden inside the minutes
    // We subtract final_minutes to ensure negative minutes borrow correctly
    int extra_hours = (minute - final_minutes) / 60;
    
  
    int total_hours = hour + extra_hours;
    int final_hours = ((total_hours % 24) + 24) % 24;

    sprintf(result.text, "%02d:%02d", final_hours, final_minutes);
    
    return result;
    
}
clock_t clock_add(clock_t clock, int minute_add)
{

    int hour;
    int minute;
    sscanf(clock.text,"%d:%d",&hour,&minute);

    // add_minute =  res
    // result.text[0] = '0';
    // printf("%s\n",clock.text);
    // printf("%i\n",minute_add);
    return (clock_create(hour,minute + minute_add));
}
clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    // clock_t result;
    int hour;
    int minute;
    sscanf(clock.text,"%d:%d",&hour,&minute);
    return (clock_create(hour,minute - minute_subtract));
    // result.text = ""
}
bool clock_is_equal(clock_t a, clock_t b)
{
    if (strcmp(a.text,b.text) == 0)
        return true;
    return false;
}