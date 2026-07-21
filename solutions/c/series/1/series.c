#include "series.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

slices_t slices(char *input_text, unsigned int substring_length)
{
    int len = strlen(input_text);
    slices_t result;
    
    result.substring_count = (len -                 ((int)substring_length -1));
    if ((len -((int)substring_length -1)) < 1 || substring_length < 1)
    {    result.substring = NULL;
         result.substring_count = 0;
         return result;
    }
        char **temp = malloc(sizeof(char*) * result.substring_count);   
        
    for (int i = 0; i < (int)result.substring_count; i++)    
        {
            char *string = malloc(substring_length + 1);
            
            for (int j = 0; j < (int)substring_length; j++)
                string[j] = input_text[i + j];
            string[substring_length] = '\0';
            temp[i] = string;
        }
    
    result.substring = temp;
    return result;
}