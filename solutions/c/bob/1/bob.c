#include "bob.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *hey_bob(char *greeting)
{
    int len = strlen(greeting);
    int letter_count = 0;
    int upper_count = 0;
    int digit_count = 0;
    char *temp = malloc(len);

    
    while (len > 0 && greeting[len - 1] == ' ')
        len--;

    
    for (int i = 0; i < len; i++)
    {
        if (isdigit(greeting[i]))
        {
            digit_count++;
        }
        if (isalpha(greeting[i]))
            {
                letter_count++;
                if (isupper(greeting[i]))
                    upper_count++;
            }
    }
    
    if (greeting[len - 1] == '?' && (upper_count == letter_count) && upper_count != 0)
            {
                temp = "Calm down, I know what I'm doing!";
                return temp;
            }
    else if ((upper_count == letter_count) && upper_count != 0)
            {
                temp = "Whoa, chill out!";
                return temp;
            }
    else if (greeting[len - 1] == '?')
    {
        temp = "Sure.";
        return temp;
    }
    else if (letter_count == 0 && digit_count == 0)
    {
        temp = "Fine. Be that way!";
        return temp;
    }
    temp = "Whatever.";
    return temp;
}