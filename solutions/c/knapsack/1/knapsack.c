#include "knapsack.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int maximum_value(unsigned int maximum_weight,item_t *item,size_t item_count)
{
    // printf("%li\n",item_count);
    // if (item == NULL)
    //     return 0;
    // if (item_count == 0)
    //     return 0;
    // if (item_count == 1 && item[0].weight > maximum_weight)
    //     return 0;

    
    unsigned int **matrix = malloc(sizeof(unsigned int *) * (item_count+1));
    for (int i = 0; i <= (int)item_count; i++)
        {
            unsigned int *ith_row = malloc(sizeof(unsigned int) * (maximum_weight + 1));
            for (int j = 0; j <= (int)maximum_weight; j++)
            {
                // printf("col = %i\n",j);
                ith_row[j] = 0;
            }
            matrix[i] = ith_row;
        }

    for (int i = 1; i <= (int)item_count; i++)
    {
        for (int j = 1; j <= (int)maximum_weight; j++)
        {
            int val = item[i-1].value;
            int wt = item[i-1].weight;

            if (wt <= j)
            {
                if (val + matrix[i-1][j-wt] > matrix[i-1][j])
                    matrix[i][j] = val + matrix[i-1][j-wt];
                else
                    matrix[i][j] = matrix[i-1][j];
            }
                else{
                    matrix[i][j] = matrix[i-1][j];
                }
            
        }
    }
    printf("%i\n",maximum_weight);
    return matrix[item_count][maximum_weight];
}