#include "say.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
    const char *small[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };
    const char* tens[] = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };
int say(int64_t input, char **ans)
{
    printf("input = %li\n",input);
    printf("value of ans = %li\n",(long int)ans);
    printf("value at ans = %li\n",(long int)*ans);
    if (input < 0 || input > 999999999999)
        return -1;

    
    *ans = malloc(5000);
    if (input == 0)
    {
        strcpy(*ans, "zero");
    }
    else
    {
        int billions  = input / 1000000000LL;
        int millions  = (input / 1000000LL) % 1000;
        int thousands = (input / 1000LL) % 1000;
        int ones      = input % 1000;

        if (billions)
        {
            say_under_1000(billions,*ans);
            sprintf(*ans+ strlen(*ans), " billion");
        }

        if (millions)
        {
            if (strlen(*ans))
                sprintf(*ans + strlen(*ans), " ");

            say_under_1000(millions, *ans);
            sprintf(*ans + strlen(*ans), " million");
        }

        if (thousands)
        {
            if (strlen(*ans))
                sprintf(*ans + strlen(*ans), " ");

            say_under_1000(thousands, *ans);
            sprintf(*ans + strlen(*ans), " thousand");
        }

        if (ones)
        {
            if (strlen(*ans))
                sprintf(*ans + strlen(*ans), " ");

            say_under_1000(ones, *ans);
        }
    }
    // ans = realloc(sizeof(ans))
    // (*ans)[0] = 'z';
    // (*ans)[1] = 'e';
    // (*ans)[2] = 'r';
    // (*ans)[3] = 'o';
    // (*ans)[4] = '\0';
    // sprintf(*ans,"one");
    // if (ans == NULL)
    //     return 0;
    
    return 0;
}


void say_under_1000(int n, char *buffer)
{
    if (n >= 100)
    {
        sprintf(buffer + strlen(buffer),
                "%s hundred",
                small[n / 100]);

        n %= 100;

        if (n)
        {
            sprintf(buffer + strlen(buffer), " ");
        }
    }

    if (n >= 20)
    {
        sprintf(buffer + strlen(buffer),
                "%s",
                tens[n / 10]);

        n %= 10;

        if (n)
        {
            sprintf(buffer + strlen(buffer),
                    "-%s",
                    small[n]);
        }
    }
    else if (n > 0)
    {
        sprintf(buffer + strlen(buffer),
                "%s",
                small[n]);
    }
}