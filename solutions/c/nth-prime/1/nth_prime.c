#include "nth_prime.h"
#include <stdio.h>
#include <stdbool.h>

uint32_t nth(uint32_t n)
{
    // printf("input %i\n",n);
    if (n == 0)
        return 0;
    int counter = 0;
    int num = 1;
    while (counter < (int)n)
    {
    bool is_prime = true;
    num++;
    // printf("%i\n",num);
    for (int i = 2; i < num; i++)
    {
        // printf("debug1\n");
        if (num % i == 0)
        {
            // printf("division\n");
            is_prime = false;
            break;
        }
    }
        if (is_prime)
        {
            // printf("debug0 %i\n",counter);
            counter++;
            // printf("debug0 %i\n",counter);
        }
    }
    // }
    return num;
}
