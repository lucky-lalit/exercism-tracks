#include "palindrome_products.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// #include <stdbool.h>

product_t *get_palindrome_product(int from, int to)
{
    int product = 0;
    char *temp = malloc(10);
    int count = 0;
    product_t *result = malloc(sizeof(product_t ));
    result->factors_sm = NULL;
    result->factors_lg = NULL;
    if (from > to)
    {
        sprintf(result->error,"invalid input: min is %i and max is %i",from,to);
            return result;
        }
    printf("from %i\n",from);
    printf("to %i\n",to);
    // int i_count = 0;
    
    for (int i = from; i <= to; i++)
    {
        for (int j = i; j <= to; j++)
        {
            // break;
            product = i * j;
            sprintf(temp,"%i",product);
            // break;
            
            // printf("%s\n",temp);
            // bool check = is_palindrom(temp);
            // printf("check for product = %i is %i\n",product,check);
            // break;
            if (is_palindrom(temp))
            {
                // break;
                if (count == 0)
                {
                    result->smallest = product;
                    result->largest = product;
                    count++;
                }
                else{
                    if (product < result->smallest)
                        result->smallest = product;
                    if (product > result->largest)
                        result->largest = product;
                }
            }
            // if (i_count > 2)
            //     break;
        }
        // i_count++;
    }
    printf("largest %i\n",result->largest);
    printf("smallest %i\n",result->smallest);
    factor_t *list = NULL;
    for (int i = from; i <= to; i++)
    {
        for (int j = i; j <= to; j++)
        {
            if (i*j == result->smallest)
            {
                printf(" smallest %i and %i\n",i,j);
                factor_t *new = malloc(sizeof(factor_t));
                result->factors_sm = new;
                result->factors_sm->factor_a = i;
                result->factors_sm->factor_b = j;
                result->factors_sm->next = NULL;
                if (list == NULL)
                {
                    list = new;
                }
                else {
                    for(factor_t *ptr = list; ptr != NULL; ptr=ptr->next)
                {
                    if (ptr->next == NULL)
                    {
                        ptr->next = new;
                        break;
                    }
                }
                       }
                }
            }
        }
    result->factors_sm = list;
    list = NULL;
    for (int i = from; i <= to; i++)
    {
        for (int j = i; j <= to; j++)
        {
            if (i*j == result->largest)
            {
                printf(" largest %i and %i\n",i,j);
                factor_t *new = malloc(sizeof(factor_t));
                result->factors_lg = new;
                result->factors_lg->factor_a = i;
                result->factors_lg->factor_b = j;
                result->factors_lg->next = NULL;
                if (list == NULL)
                {
                    list = new;
                }
                else {
                    for(factor_t *ptr = list; ptr != NULL; ptr=ptr->next)
                {
                        // printf("the a and b are %i %i",ptr->);
                    if (ptr->next == NULL)
                    {
                        ptr->next = new;
                        // result->factors_lg = list;
                        
                        break;
                    }
                }
                       }
                }
            }
        }
    result->factors_lg = list;
    // }
    if (result->factors_lg == NULL || result->factors_sm == NULL)
    {
        sprintf(result->error,"no palindrome with factors in the range %i to %i",from,to);
    }
    return result;
}

bool is_palindrom(char *input)
{
    // printf("debug 0\n");
    // return false;
    int index = 0;
    if (strlen(input) == 0)
        return false;
    int end = strlen(input) - 1;
    int front = 0;
    while (front < end)
    {
        if (input[front] != input[end])
            return false;
        index++;
        front = index;
        end = strlen(input) - (front + 1);
    }
    return true;
}
void free_product(product_t *p)
{
    if (p == NULL)
        return;
    factor_t *temp = p->factors_sm;
    while (temp != NULL)
    {
        factor_t *next = temp->next;
        free(temp);
        temp = next;
    }
    temp = p->factors_lg;
    while (temp != NULL)
    {
        factor_t *next = temp->next;
        free(temp);
        temp = next;
    }
    free(p);
}