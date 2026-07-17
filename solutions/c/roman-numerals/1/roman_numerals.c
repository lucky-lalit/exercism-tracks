#include "roman_numerals.h"
#include <stdio.h>
#include <stdlib.h>

char *to_roman_numeral(unsigned int number)
{
    printf("%i\n",number);
    char *temp = malloc(20);
    // temp[19] = 'I';
    int index = 0;
    while (number != 0)
    {
        if (number >= 1000)
        {
            number = number - 1000;
            temp[index] = 'M';
        }
        else if (number >= 900)
        {
            number = number - 900;
            temp[index] = 'C';
            index++;
            temp[index] = 'M';
        }
        else if (number >= 500)
        {
            number = number - 500;
            temp[index] = 'D';
        }
        else if (number >= 400)
        {
            number = number - 400;
            temp[index] = 'C';
            index++;
            temp[index] = 'D';
        }
        else if(number >= 100)
        {
            number = number - 100;
            temp[index] = 'C';
        }
        else if(number >= 90)
        {
            number = number - 90;
            temp[index] = 'X';
            index++;
            temp[index] = 'C';
        }
        else if (number >= 50)
        {
            number = number - 50;
            temp[index] = 'L';
        }
        else if(number >= 40)
        {
            number = number - 40;
            temp[index] = 'X';
            index++;
            temp[index] = 'L';
        }
        else if(number >= 10)
        {
            number = number - 10;
            temp[index] = 'X';
        }
        else if (number >= 9)
        {
            number = number - 9;
            temp[index] = 'I';
            index++;
            temp[index] = 'X';
        }
        else if(number >= 5)
        {
            number = number - 5;
            temp[index] = 'V';
        }
        else if (number >= 4)
        {
            number = number - 4;
            temp[index] = 'I';
            index++;
            temp[index] = 'V';
        }
        else if (number >= 1)
        {
            number = number - 1;
            temp[index] = 'I';
        }
        index++;
    }
    temp[index] = '\0';
    return temp;
}