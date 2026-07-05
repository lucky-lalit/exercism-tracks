#include "kindergarten_garden.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// void kindergarden_garden(char *diagram,char *student,plant_t plants)
plants_t plants(const char *diagram,const char *student)
{
    plants_t result;
    int arr[12] = {0};
    arr[student[0] - 'A'] = 1;
    int name_position = 0;
    for (int i = 0; i < 12; i++)
    {if (arr[i] == 1)
            name_position = i;
    }
    // printf("name \n%i",name_position);
    int len = strlen(diagram);
    char *str1 = malloc((len / 2) + 1);
    char *str2 = malloc((len / 2) + 1);
    // printf("debug len %i\n",len);
    int count = 0;
    bool test = true;
    for (int i = 0; i < len; i++)
    {if (diagram[i] == '\n')
        {test = false;
            str1[count] = '\0';
        }
        if (test)
        {str1[i] = diagram[i]; 
            count++;
        }
        else 
        {   str2[i - ((len / 2) + 1)] = diagram[i];
            if (i+1 == len)
                str2[count] = '\0';}
    }
    for (int i = 0; i < 2; i++)
    {if (i == 0)
        {if (str1[name_position * 2] == 'G')
            result.plants[i] = GRASS;
        else if (str1[name_position * 2] == 'C')
            result.plants[i] = CLOVER;
        // printf("%c\n"str1[name_position * 2]);
        else if (str1[name_position * 2] == 'R')
        {printf("debug %i\n",i);
        result.plants[i] = RADISHES;}
        else if (str1[name_position * 2] == 'V')
            result.plants[i] = VIOLETS;}
        
     
        else{
        if (str1[(name_position * 2 ) + 1] == 'G')
            result.plants[i] = GRASS;
        else if (str1[(name_position * 2) + 1] == 'C')
            result.plants[i] = CLOVER;
        // printf("%c\n"str1[name_position * 2]);
        else if (str1[(name_position * 2 ) + 1] == 'R')
        {printf("debug %i\n",i);
            result.plants[i] = RADISHES;
        }
        else if (str1[(name_position * 2 ) + 1] == 'V')
            result.plants[i] = VIOLETS;
        }
    }
    for (int i = 0; i < 2; i ++)
    {
        if (i == 0)
        {
        if (str2[name_position * 2] == 'G')
            result.plants[i + 2] = GRASS;
        else if (str2[name_position * 2] == 'C')
            result.plants[i + 2] = CLOVER;
        else if (str2[name_position * 2] == 'R')
            result.plants[i + 2] = RADISHES;
        else if (str2[name_position * 2] == 'V')
            result.plants[i + 2] = VIOLETS;
    }
        else{
            if (str2[(name_position * 2 ) + 1] == 'G')
                result.plants[i + 2] = GRASS;
            else if (str2[(name_position * 2 ) + 1] == 'C')
                result.plants[i + 2] = CLOVER;
            else if (str2[(name_position * 2 ) + 1] == 'R')
                result.plants[i + 2] = RADISHES;
            else if (str2[(name_position * 2 ) + 1] == 'V')
                result.plants[i + 2] = VIOLETS;
        }
    }
    // for (int i = 0; i < 4; i++)
        // printf("%i\n",result.plants[i]);
    // result.plants[0] = CLOVER;
    return result;
    
}