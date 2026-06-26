#include "pangram.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_pangram(const char *sentence)
{   
    if (sentence == NULL)
        return false;
    int array[26] = {0};
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if(isalpha(sentence[i]))
        {
            int temp = tolower(sentence[i]) - 97;
            if (temp >= 0 && temp < 26)
            {
                array[temp] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (array[i] == 0)
        {
            // return false;
        }
        else 
        {
            count++;
        }
    }

    if (count == 26)
        return true;
    return false;
    // return true;


}










    
    // int counter = 0;
    // char *buffer = "abcdefghijklmnopqrstuvwxyz";
    // for (int i = 0; buffer[i] != '\0'; i++)
    // {
    //     for (int j = 0; sentence[j] != '\0'; j++)
    //     {
    //         if (isalpha(sentence[j]))
    //         {
    //             if (tolower(sentence[i]) == buffer[j])
    //                 counter++;
    //         }
    //     }
    // }
    // printf("debug 3 %i\n",counter);
    // return counter == 26;
    
     // atol(buffer,sentence);
    // printf("debug0 %li\n",strlen(sentence));
    // if (strlen(sentence) > 2)
    // {
    //     for (int i = 0; buffer[i] != "\0"; i ++)
    //     {
    //         printf("debug 1 %c\n",sentence[i]);
    //     }
    // }
    // if (strlen(sentence) > 1)
    // printf("debug2 %c\n",sentence[1]);
    // if (sentence != NULL)
    //     printf("%s\n",sentence);
    // return true;
// }
