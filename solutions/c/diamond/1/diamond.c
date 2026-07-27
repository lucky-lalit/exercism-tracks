#include "diamond.h"
#include <stdio.h>
#include <stdlib.h>

char **make_diamond(const char letter)
{

    // char **result = malloc(10000);
    // if (result == NULL)
    // {
    //     printf("malloc fail\n");
    //     return NULL;
    // }
    // printf("debug 0\n");
    // result[0] = malloc(777);
    // result[0][0] = ' ';
    // result[0][1] = 'A';
    // result[0][2] = ' ';
    // result[0][3] = '\0';
    // printf("debug 1\n");
    // result[1] = malloc(55);
    // result[1][0] = 'B';
    // result[1][1] = ' ';
    // result[1][2] = 'B';
    // result[1][3] = '\0';
    // // result[2] = 'A';
    // result[2] = result[0];
    // printf("debug 3\n");
    // return result;
    
    char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int size =  ((((letter - 'A') + 1) * 2) - 1);
    printf("size %i\n",size);
    char **matrix = malloc(sizeof(char *) * ((((letter - 'A') + 1) * 2) - 1));
    int row = ((((letter - 'A') + 1) * 2) - 1);
    int col = ((((letter - 'A') + 1) * 2) - 1);
    for (int i = 0; i < row; i++)
    {
        char *ith_row = malloc((sizeof(char) * col) + 1);
        for (int j = 0; j < col; j++)
        {
            ith_row[j] = ' ';
            // if (j+1 == col)
            //     ith_row[j+1] = '\0';
        }
        ith_row[col] = '\0';
        matrix[i] = ith_row;
    }
    if (size > 2)
        // printf("character in matrix %c\n",matrix[0][2]);
    if (size == 1)
    {
        matrix[0][0] = 'A';
        return matrix;
    }
    for (int i  = 0 ; i <= size / 2; i++)
    {
        // printf("debug 0\n");
        if (i + 1 > size / 2)
        {
            // printf("end condition\n");
            matrix[i][(size / 2 - i)] = arr[i];
            matrix[i][(size / 2) + i] = arr[i];
        }
        
        matrix[i][(size / 2 - i)] = arr[i];
        matrix[i][(size / 2) + i] = arr[i];
        if (size > 1)
        {
        matrix[(size - i) - 1][(size / 2) - i] = arr[i];
       matrix[(size - i) - 1][(size / 2) + i] = arr[i];
        }
    }
    // printf("debug checking the matrix\n");
    // for (int i = 0; i < col; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         printf("%c ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("matrix check end\n");
    // printf("%c\n",letter);
    return matrix;
}
void free_diamond(char **diamond)
{
    // printf("free\n");
    if (diamond == NULL)
        return;
    int index = 0;
    while (diamond[0][index] != '\0')
        index++;
    for (int i = 0; i < index; i++)
        free(diamond[i]);
    
    free(diamond);
        
}