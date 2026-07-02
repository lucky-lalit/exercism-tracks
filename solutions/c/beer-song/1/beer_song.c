#include "beer_song.h"
#include <stdio.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    // int temp = start_bottles;
    int index = 0; 
    for (int i = 0; i < take_down; i++)
    {
        if (start_bottles - i == 1)
        {
            sprintf(song[index],"%i bottle of beer on the wall, %i bottle of beer.",start_bottles - i,start_bottles - i);
            index++;
            sprintf(song[index], "Take it down and pass it around, no more bottles of beer on the wall.");
    index++;
    }
    else if (start_bottles - i == 0)
    {
        sprintf(song[index], "No more bottles of beer on the wall, no more bottles of beer.");
    index++;
        sprintf(song[index], "Go to the store and buy some more, 99 bottles of beer on the wall.");
    index++;
    }
    else if (start_bottles - i == 2)
    {
        sprintf(song[index], "%i bottles of beer on the wall, %i bottles of beer.",start_bottles - i,start_bottles - i);
    index++;
        sprintf(song[index], "Take one down and pass it around, %i bottle of beer on the wall.",(start_bottles - i) - 1);
    index++;
    }
    else
    {
        sprintf(song[index], "%i bottles of beer on the wall, %i bottles of beer.",start_bottles - i,start_bottles - i);
    index++;
        sprintf(song[index], "Take one down and pass it around, %i bottles of beer on the wall.",(start_bottles - i) - 1);
    index++;
    }
    if (i + 1 != 0)
    {
        index++;
    }
    } 
}