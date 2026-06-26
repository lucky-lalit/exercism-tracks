#include "square_root.h"

int square_root(uint16_t number)
{
    for (int i = 1; i <= number / 2; i++)
    {
        if (i * i == number)
            return i;
        
    }
    return 1;
}