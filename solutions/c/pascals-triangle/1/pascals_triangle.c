#include "pascals_triangle.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t **create_triangle(size_t rows)
{
    printf("rows %li\n",rows);
    // return NULL;
    uint8_t **matrix = malloc(sizeof(uint8_t*) * (rows + 1));
    int row = rows;
    int col = rows;
    if (row < 1)
    {
        uint8_t *ith_row = malloc(sizeof(uint8_t) * 1);
        matrix[rows] = ith_row;
        matrix[rows][rows] = rows;
        return matrix;
    }
            
    //     return matrix;
    
    for (int i = 0; i < row; i++)
    {
        uint8_t *ith_row = malloc(sizeof(uint8_t) * rows);
        for (int j = 0; j < col; j++)
        {
            // printf("col = %i\n",j);
            ith_row[j] = 0;
        }
        matrix[i] = ith_row;
    }
    for (int i = 0; i < (int)rows ; i++)
    {
        for (int j = 0; j < (int)rows; j++)
        {
            if (i == 0 && j == 0)
                matrix[i][j] = 1;
            else if (j - 1 < 0 && i > 0)
                matrix[i][j] = matrix[i - 1][j];
            else if (i > 0)
                matrix[i][j] = matrix[i - 1][j] + matrix [i - 1][j - 1]; 
            // printf("%i = rows, %i\n",i,matrix[i][j]);
        }
    }
    // for (int i = 0; i < (int)rows; i++)
    // {
    //     for (int j = 0; j < (int)rows; j++)
    //     {
    //         printf("%i \n",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    return matrix;
}



void free_triangle(uint8_t **triangle, size_t rows)
{
    printf("free %li\n",rows);


    if (triangle == NULL) return;
    for (int i = 0; i < (int)rows; i++)
    {
        printf("Freeing row %i at address %p\n", i, (void*)triangle[i]);
        if (triangle[i] == NULL)
        {
            printf("debgug NULL\n");
            continue;
        }
        free(triangle[i]);
        printf("debug0\n");
    }
    printf("debug1\n");
    free(triangle);
    // // }
    // if (triangle == NULL)
    //     return;
}