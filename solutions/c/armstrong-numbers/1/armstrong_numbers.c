#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool is_armstrong_number(int candidate)
{
    char temp[15];
    int sum = 0;
    sprintf(temp,"%i",candidate);
    int len = strlen(temp);
    for (int i = 0; i < len; i++)
    {
        // char str[2] = {temp[i],'\0'}; 
        sum += pow(temp[i] - '0', len);
    }
    // printf("%i\n",candidate);
    if (sum == candidate)
        return true;
    return false;
}