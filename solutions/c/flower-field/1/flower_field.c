#include "flower_field.h"
#include <stdio.h>
#include <stdlib.h>

int malloc_count = 0;

char **annotate(const char **garden, const size_t rows)
{
    if (garden == NULL)
        return NULL;
    int col = 0;
    while(garden[0][col] != '\0')
        col++;
    int count = 0;
    
    char **matrix = malloc(sizeof(char *) * (rows + 1));
    for (int i = 0; i < (int)rows; i++)
    {       
        char *ith_row = malloc(col + 1);
        // if (i + 1 == (int)rows)
        // {   matrix[i][0] = '\0'
            // char *ith_row = malloc(1);
        // }
        
        // malloc_count++;
        if (col == 0)
        {
            ith_row[i] = garden[i][col];
            matrix[i] = ith_row;
            return matrix;
        }
        for (int j = 0; j < col; j++)
        {
            count = 0; 
            if (garden[i][j] == '*')
                ith_row[j] = '*';
            else{
                if (i - 1 >= 0)
                {
                    if (garden[i - 1][j] == '*')
                    {
                        count++;
                    }
                }
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    if (garden[i - 1][j - 1] == '*')
                        {
                        count++;
                    }
                }
                if (j - 1 >= 0)
                {
                    if (garden[i][j - 1] == '*')
                        {
                        count++;
                    }
                }
                if (i + 1 < (int)rows)
                {
                    if (garden[i + 1][j] == '*')
                        {
                        count++;
                    }
                }
                if (j + 1 < col)
                {
                    if (garden[i][j + 1] == '*')
                        {
                        count++;
                    }
                }
                if (i + 1 < (int)rows && j + 1 < col)
                {
                    if (garden[i + 1][j + 1] == '*')
                        {
                        count++;
                    }
                }
                if (i + 1 < (int)rows && j - 1 >= 0)
                {
                    if (garden[i + 1][j - 1] == '*')
                        {
                        count++;
                    }
                }
                if (i - 1 >= 0 && j + 1 < col)
                {
                    if (garden[i - 1][j + 1] == '*')
                        {
                        count++;
                    }
                }
                
            if (count == 0)
                ith_row[j] = garden[i][j];
            else
                ith_row[j] = count + '0';                
            }
        }
    ith_row[col] = '\0';
    matrix[i] = ith_row;
    // if (i + 1 == (int)rows)
    //     matrix[i+1] = NULL;
    }
    matrix[rows] = NULL;
    return matrix;
    
}


void free_annotation(char **annotation)
{
    printf("free\n");
    if (annotation == NULL)
        return;
    int rows = 0;
    while (annotation[rows] != NULL)
        rows++;
    for (int i = 0; i < rows; i++)
        free(annotation[i]);
    
    free(annotation);
}