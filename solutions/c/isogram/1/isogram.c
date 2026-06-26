#include "isogram.h"
#include <stdio.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{    
    if (phrase == NULL)
        return false;
    int array[26] = {0};
    for (int i = 0; phrase[i] != '\0'; i++)
        {
            printf("%c\n",phrase[i]);
        }
    for (int i = 0; phrase[i] != '\0'; i++)
    {
        if (isalpha(phrase[i]))
        {   
            // printf("debug0 %i \n",tolower(phrase[i]) - 97);
            int temp = tolower(phrase[i]) - 97;
            if (temp >= 0 && temp < 26)
            {
                // printf("debug1 %i \n",array[i]);
                if (array[temp] == 1)
                    return false;
                array[temp] = 1;
            }
        }
    }
    return true;
    }



    
    // if (phrase != NULL)
    // {   
    //     for (int i = 0; phrase[i] != '\0'; i++)
    //     {
    //         printf("%c\n",phrase[i]);
    //     }
    //         // printf("%c\n",phrase[0]);
    // }
    // return false;
// }