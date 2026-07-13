#include "saddle_points.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
saddle_points_t *saddle_points(uint8_t row,uint8_t column,uint8_t (*matrix)[column])
{
    printf("saddle_points\n");
    saddle_points_t *result = malloc(sizeof(saddle_points_t));
    result->points = malloc(sizeof(saddle_point_t) * (row * column));
    if (matrix == NULL)
    {
        result->count = 0;
        return result;
    }
    result->count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            bool largest = true;
            bool smallest = true;
            for(int k = 0; k < column; k++)
            {
             if (matrix[i][j] < matrix[i][k])
             {   
                 largest = false;
                 break;
             }
            }
            for (int m = 0; m < row; m++)
            {
                if (matrix[i][j] > matrix[m][j])
                {
                    smallest = false;
                    break;
                }
                    
            }
            if (largest && smallest)
            {
                result->points[result->count].row = i + 1;
                result->points[result->count].column = j + 1;
                result->count++;
            }
        }
    }
    printf("debug2\n");
    printf("%i\n",row);
    // printf("%i\n",matrix[0][0]);
    return result;
}

void free_saddle_points(saddle_points_t *result)
{
    free(result->points);
    free(result);
    // printf("%li\n",result->count);
}