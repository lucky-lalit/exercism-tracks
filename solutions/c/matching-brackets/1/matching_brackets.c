#include "matching_brackets.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *result(int start,char *string,int length);

bool is_paired(const char *input)
{
    printf("is_paired\n");
    int len = strlen(input);
    if (len == 0)
        return true;
    char *temp = malloc(len);
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] != '{' && input[i] != '}' && input[i] != '[' && input[i] != ']' && input[i] != '(' && input[i] != ')')
            continue;
        else
        {
            temp[index] = input[i];
            index++;
        }
    }
    temp[index] = '\0';
    int temp_len = strlen(temp);
    index = 0;
    int count = 0;
    while(temp[index] != '\0')
    {
        int len = strlen(temp);
        if (index + 1 == len)
            return false;
        
        else if (temp[index] == '{' && temp[index + 1] == '}')
        {
            strcpy(temp,result(index,temp,len));
            index = -1;
            count++;
        }
        else if(temp[index] == '(' && temp[index + 1] == ')')
        {
            strcpy(temp,result(index,temp,len));
            index = -1;
            count++;
        }
        else if(temp[index] == '[' &&temp[index + 1] == ']')
        {
            strcpy(temp,result(index,temp,len));
            index = -1;
            count++;
        }
        index++;
    }
    if (count == (temp_len ) / 2)
    {   printf("pass\n");
        return true;
    }
    if (input == NULL)
        return false;
    return false;
}

char *result(int start,char *string,int length)
{
    for (int i = start; i < length - 2; i++)
        string[i] = string[i+2];
    string[length - 2] = '\0';
    return string;
}