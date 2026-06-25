#include "luhn.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

bool luhn(const char *num)
{
    int len = strlen(num);
    char *temp = malloc((len) * sizeof(char));
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (isspace(num[i]))
        {}
        // else if ((!isdigit(num[i])))
        
        // {     free(temp);
        //       return false;
        // }
        else 
        {
            temp[count] = num[i];
            count++;
        }
    }
    temp[count] = '\0';
    int len_temp = strlen(temp);
    if (len_temp < 2)
        return false;
    // printf(" %i\n",len_temp);
    // printf("debug0 %s\n",num);
    // printf("temp %s\n",temp);
    for (int i = 0; i < len_temp; i++)
    {
        if (!isdigit(temp[i]))
        { free(temp);
          return false;
        }
    }
    int even_sum = 0;
    int odd_sum = 0;
    for (int i = 1; i <= len_temp; i++)
    {
        if (i % 2 == 0)
            if (2*(temp[len_temp - i] - '0') > 9)
                even_sum += (2*(temp[len_temp - i] - '0') - 9);
            else 
                even_sum += (2*(temp[len_temp - i] - '0'));
        else 
         odd_sum += (temp[len_temp - i] - '0');
    }
    // printf("sum %i\n",sum);
    // printf( odd_sum %i\n" odd_sum);
    if ((even_sum + odd_sum) % 10 == 0)
    {
        // printf("valid");
        return true;
    }
    free(temp);
    return false;
}