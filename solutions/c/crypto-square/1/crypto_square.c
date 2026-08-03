#include "crypto_square.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char *ciphertext(const char *input)
{
    // printf("%s\n",input);
    int len = strlen(input);
    char *copy = malloc(len);
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if(isalnum(input[i]))
        {
            copy[index] = tolower(input[i]);
            index++;
        }
    }
    copy[index] = '\0';
    if (1 >= strlen(copy))
        return copy;
    
    int row = 0;
    int col = 0;
    int len2 = strlen(copy);
    bool is_found = false;
    for (int i = 2; i < len2; i++)
    {
        if (is_found)
            break;
        for (int j = i; j < len2; j++)
        {
            if (j - i > 1)
                break;
        
            else if ( i * j >= len2 && j - i <= 1 && j >= i)
            {
                row = i;
                col = j;
                is_found = true;
                break;
            }
        }
    }
    printf("the row = %i and col = %i and the string is %s\n",row,col,copy);

    char **matrix = malloc(sizeof(char*) * row);
        // int row = size;
        // int col = size;
        for (int i = 0; i < row; i++)
        {
            char *ith_row = malloc(sizeof(char) * (col + 1));
            for (int j = 0; j < col; j++)
            {
                // printf("col = %i\n",j);
                ith_row[j] = ' ';
            }
            matrix[i] = ith_row;
        }
    index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = copy[index];
            index++;
        }
        matrix[i][col] = '\0';
    }
    for (int i  =0 ; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
          printf("%c ",matrix[i][j]);  
        }
        printf("%s\n",matrix[i]);
    }
    index = 0;
    printf("len of copy %li\n",strlen(copy));
    free(copy);
    char *result = malloc(len + 1);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (!isalpha(matrix[j][i]))
            {
                result[index] = ' ';
                index++;
                continue;
            }
            result[index] = matrix[j][i];
            index++;
        }
        printf("%i\n",i);
        if (i + 1 == col)
        {
            // printf("is last condition %i\n");
            result[index] = '\0';
            return result;
        }
        result[index] = ' ';
        index++;
    }
    
    return result;
}