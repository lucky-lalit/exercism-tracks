#include "perfect_numbers.h"
#include <stdio.h>

kind classify_number(int a)
{
    printf("%i\n",a);
    int sum = 0;
    if (a < 1)
        return ERROR;
    for(int i = 1; i < a; i++)
    {
        if(a % i == 0)
        {
            sum = sum + i;
        }
    }
    printf("%i\n",sum);
    if (sum == a)
        return PERFECT_NUMBER;
    else if (a < sum)
        return ABUNDANT_NUMBER;
    return DEFICIENT_NUMBER;
}