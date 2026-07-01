#include "sieve.h"
#include <stdio.h>
#include <stdbool.h>


uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    if (limit < 2)
        return 0;
    bool is_prime[limit - 1];
    int counter = 0;
    for (int i = 0; i < (int)limit - 1; i++)
        is_prime[i] = true;
    for (int i = 2; i <= (int)limit; i++)
    {
     if (is_prime[i - 2])
     {
         if (counter < (int)max_primes)
         {
         primes[counter] = i;
         printf("%i\n",i);
         counter++;
         }
         for (int j = i*i; j <= (int)limit; j = j + i)
         {
             is_prime[j - 2] = false;
         }
         
         }
    }
        
    // printf("%i\n",limit);
    // printf("%i\n",primes[0]);
    printf("%li\n",max_primes);
    
    
    return counter; 
    
}