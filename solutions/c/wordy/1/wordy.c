#include "wordy.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
bool answer(const char *question, int *result)
{
    char *string = malloc(strlen(question) + 1);
    printf("result = %i\n",*result);
    strcpy(string,question);
    printf("input string = %s\n",string);
    long int left_operand = 0;
    
    
    char *t = strtok(string," ");
    
    while(t != NULL)
    {
        char *endptr = NULL;
        left_operand = strtol(t,&endptr,10);
        if ((strcmp(endptr,"?") == 0) || strlen(endptr) == 0)
            break;

        // INVALID CODE
        // if (strcmp(endptr,"?") == 0)
        // {    *result = (int)left_operand;
        //     return true;
        // }
        // if (strlen(endptr) == 0)
        //     break;
        
        t = strtok(NULL," ");
    }
    if (t == NULL)
        return false;
    printf("found the left_ooperand = %li\n",left_operand);
    printf("current t = %s\n",t);

    
    while(t != NULL)
    {
        char *operator = strtok(NULL," ");
        if (operator == NULL)
            break;
        printf("operator = %s\n",operator);
        char *next_str = strtok(NULL," ");
        if (next_str == NULL)
            return false;
        printf("next_str = %s\n",next_str);
        char *endptr = NULL;
        if (strcmp(operator,"plus") == 0)
        {
            long int right_operand = strtol(next_str,&endptr,10);
            if (((strcmp(endptr,"?") == 0) || strlen(endptr) == 0) == false)
                return false;
            left_operand = left_operand + right_operand;
        }
        else if (strcmp(operator,"minus") == 0)
        {
            long int right_operand = strtol(next_str,&endptr,10);
            if (((strcmp(endptr,"?") == 0) || strlen(endptr) == 0) == false)
                return false;
            left_operand = left_operand - right_operand;
        }
        else if (strcmp(operator,"multiplied") == 0)
        {
            if (strcmp(next_str,"by") != 0)
                return false;
            next_str = strtok(NULL," ");
            if (next_str == NULL)
                return false;
            long int right_operand = strtol(next_str,&endptr,10);
            if (((strcmp(endptr,"?") == 0) || strlen(endptr) == 0) == false)
                return false;
            left_operand = left_operand * right_operand;
        }
        else if (strcmp(operator,"divided") == 0)
        {
            if (strcmp(next_str,"by") != 0)
                return false;
            next_str = strtok(NULL," ");
            if (next_str == NULL)
                return false;
            long int right_operand = strtol(next_str,&endptr,10);
            if (((strcmp(endptr,"?") == 0) || strlen(endptr) == 0) == false)
                return false;
            left_operand = left_operand / right_operand;
        }
        else
            return false;    
        }
    *result = left_operand;
    return true;    
}

