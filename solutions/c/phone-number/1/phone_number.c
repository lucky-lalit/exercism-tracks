#include "phone_number.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *phone_number_clean(const char *input)
{
    int len = strlen(input);
    char *temp = malloc(len + 1);
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (isdigit(input[i]))
        {
            if (index == 0 && (input[i] == '1' || input[i] == '0'))           continue;
            else{
                temp[index] = input[i];
                index++;
            }
        }
            
    }
    temp[index] = '\0';
    
    int new_len = strlen(temp);
    if (new_len != 10 || temp[3] == '1' || temp[3] == '0')
    {
        for (int i = 0; i < 10; i++)
            temp[i] = '0';
    }
    temp[10] = '\0';   
    return temp;
    
}