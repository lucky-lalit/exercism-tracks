#include "prime_factors.h"
#include <stdio.h>

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
    
{
    // printf("%li\n",n);
    // printf("%li\n",factors[0]);
    int temp = n;
    // printf("%i\n",temp);
    int index = 2;
    int count = 0;
    int product = 1;

        while(product != temp)
    {
        if (n % index == 0)
        {
            factors[count] = index;
            n = n / index;
            product *= index;
            count++;
        }
        else
            index++;
    }
    return count;
    
//     while(n > 1)
//     {
//         if (n % index == 0)
//         {
//             factors[count] = index;
//             n = n / index;
//             // product *= index;
//             count++;
//         }
//         else
//             index++;
//     }
//     return count;
}