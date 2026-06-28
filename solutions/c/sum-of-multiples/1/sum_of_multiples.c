#include "sum_of_multiples.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
    int capacity = limit;
    int *arr = malloc(capacity * (sizeof(int)));
    // int *arr_2 = malloc(capacity * (sizeof(int)));
    printf("%i\n",factors[0]);
    printf("%li\n",number_of_factors);
    printf("%i\n",limit);
    int count = 0;
    for (int i = 0; i < (int)number_of_factors; i++)
    {
        if (factors[i] == 0) continue;
        for (int j = factors[i]; j < (int)limit; j++)
        {
            if (count + 1 == capacity)
            {
                capacity *= 2;
            int *temp = realloc(arr, capacity * sizeof(int));
            if (temp == NULL) 
            {
                printf("Reallocation failed!\n");
                free(arr); 
                return 1;
            }
                arr = temp;
            }
            if (j % factors[i] == 0)
            {
                arr[count] = j;
                count++;
            }
        }
    }
    printf("%i\n",count);
    for (int i =0; i <= count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] == arr[j])
                arr[i] = 0;
        }
    }
    // return 3;
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += arr[i];
    }
    return sum;

    // int result_sum = 0;
    // bool dup_check_arr[limit];
    // for (int i = 0; i < (int)limit; i++)
    // {
    //     dup_check_arr[i] = false;
    // }
    // for (int i = 0; i < (int)number_of_factors; i++)
    // {
    //     if (factors[i] == 0) continue;
    //     // int multiple = factors[i]; 
    //     for (int j = factors[i]; j < (int)limit; j++)
    //     {
    //         if (j % factors[i] != 0)
    //             continue;
    //         if (dup_check_arr[j])
    //             continue;
    //         result_sum += j;
    //         dup_check_arr[j] = true;
    //     }
    // }
    // return result_sum;
    
}