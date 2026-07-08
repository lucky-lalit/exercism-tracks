#include "spiral_matrix.h"
#include <stdio.h>
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int size)
{
    spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));
    if (size == 0)
    {
        result->size = 0;
        result->matrix = NULL;
        return result;
    }
    int **matrix = malloc(sizeof(int*) * size);
    int row = size;
    int col = size;
    for (int i = 0; i < row; i++)
    {
        int *ith_row = malloc(sizeof(int) * size);
        for (int j = 0; j < col; j++)
        {
            // printf("col = %i\n",j);
            ith_row[j] = 0;
        }
        matrix[i] = ith_row;
    }
    int counter = 1;
    int top = 0; 
    int bottom = size - 1;
    int left = 0; 
    int right = size - 1;

while (top <= bottom && left <= right) 
{
    for(int col = left; col <= right; col++)
    {
        matrix[top][col] = counter++;
    }
    top++;
    for (int row = top; row <= bottom ; row++)
    {
        matrix[row][right] = counter++;
    }
    right--;

    if (top <= bottom)
    {
        for (int col = right; col >= left; col--)
        {
            matrix[bottom][col] = counter++;
        }
        bottom--;
    }
    if (right >= left)
    {
        for (int row = bottom; row >= top; row--)
        {
            matrix[row][left] = counter++;
        }
        left++;
    }
}
    result->matrix = matrix;
    result->size =size;
    
    return result;
}


void spiral_matrix_destroy(spiral_matrix_t *actual)
{
    if (actual == NULL)
        return;
    // int size = actual->size;
    // int **matrix = actual->matrix;
    for (int i = 0; i < actual->size; i++)
    {
        free(actual->matrix[i]);
    }
    free(actual->matrix);
    free(actual);
}