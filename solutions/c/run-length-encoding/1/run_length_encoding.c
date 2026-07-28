#include "run_length_encoding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encode(const char *text)
{
    // printf("%s\n",text);
    int len = strlen(text);
    char *encoded = malloc(len+1);
    int index = 0;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == text[i+1])
            count++;
        else
        {
            count++;
            if (count > 9)
            {
            int first_digit = count / 10;
            encoded[index] = first_digit + '0';
            index++;
            int second_digit = count % 10;
            encoded[index] = second_digit + '0';
            index++;
            count = 0;
            }
            else {
                if (count == 1)
                {
                    encoded[index] = text[i];
                    index++;
                    count = 0;
                    continue;
                }
                encoded[index] = count + '0';
                index++;
                count = 0;
                }
            encoded[index] = text[i];
            index++;
                
        }
        // if(len)
        
    }
    encoded[index] = '\0';
    printf("encoded string %s\n",encoded);
    return encoded;
}
char *decode(const char *data)
{
    char *decoded = malloc(100);
    int index = 0;
    int count = 0;
    int number = 0;
    // int len = strlen(data);
    
    while(data[count] != '\0')
    {
        if (isdigit(data[count]) && isdigit(data[count+1]))
        {
            // printf("two digit integer loop\n");
            int number = (data[count] - '0') * 10;
            number = number + (data[count+1] - '0');
            for (int j = 0; j < number; j++)
            {
                // printf("%i\n",j);
                decoded[index] = data[count+2];
                index++;
            }
            number  = 0;
            count = count + 3;
        }

        else if (isdigit(data[count]))
        {
            // printf("one digit integer loop\n");
            number = data[count] - '0';
            for (int k = 0; k < number; k++)
            {
                // printf("one digit %i\n",k);
                decoded[index] = data[count+1];
                index++;
            }
            number = 0;
            count = count + 2;
        }
        else
        {
            // printf("aplhabet loop\n");
            decoded[index] = data[count];
            count++;
            index++;
            
        }
    }
    
    // for (int i = 0; i < len; i++)
    // {
    //     printf("main loop\n");
    //     // if (isalpha(data[i]) && isalpha(data[i+1]))
    //     // {
    //     //     decoded[index] = data[i+1];
    //     //     index++;
    //     // }
    //     if (isdigit(data[i]) && isdigit(data[i+1]))
    //     {
    //         printf("two digit integer loop\n");
    //         int count = (data[i] - '0') * 10;
    //         count = count + (data[i+1] - '0');
    //         for (int j = 0; j < count - 1; j++)
    //         {
    //             printf("%i\n",j);
    //             decoded[index] = data[i+2];
    //             index++;
    //         }
    //         count  = 0;
    //         // continue;
    //     }
    //     else if(isdigit(data[i])){
    //         printf("one digit integer loop\n");
    //         count = data[i] - '0';
    //         for (int k = 0; k < count - 1; k++)
    //         {
    //             printf("one digit %i\n",k);
    //             decoded[index] = data[i+1];
    //             index++;
    //         }
    //         count = 0;
    //         // continue;
            
    //     }
    //     else if (isalpha(data[i]))
    //     {
    //         printf("aplhabet loop\n");
    //         decoded[index] = data[i];
    //         index++;
    //     }
    // }
    decoded[index] = '\0';
    printf("%s\n",data);
    printf("decoded string %s\n",decoded);
    int len_decoded = strlen(decoded);
    printf(" string decoded length %i\n",len_decoded);
    char *efficient_decode = realloc(decoded,len_decoded);
    if (efficient_decode == NULL)
    {
        free(decoded);
        return NULL;
    }
    return efficient_decode;
}