#include "etl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
    int length = 0;
    for (int i =0 ; i < (int)input_len; i++)
    {
        
    char *temp = (char *)(input+i)->keys;
    length += strlen(temp);
    
    }
    
    new_map *temp_malloc = malloc(sizeof(new_map) * length);
    *output = temp_malloc;
    int index = 0;
    
    for (int i = 0; i < (int)input_len; i++)
    
    {
        char *temp = (char *)(input + i)->keys;
        int len = strlen(temp);

        
         for (int j = 0; j < len; j++)
        {
             
            (*output)[index].key = tolower(temp[j]);
            (*output)[index].value = (input+i)->value;
             index++;
        
         }
    
    }

    for (int i = 0; i < length; i++)
     {
         for (int j = 0; j < length - i - 1; j++)
         {
             if ((*output)[j].key > (*output)[j+1].key)
             {
                 new_map temp = (*output)[j];
                 (*output)[j] = (*output)[j+1];
                 (*output)[j+1] = temp;
             }
         }
     }
    return index;
}