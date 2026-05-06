#include "binary.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int convert(const char *input)
{
    printf("%s\n",input);
    int result = 0;
    int power = 0;
    int len = strlen(input);
    for (int i = len - 1; i >= 0; i--)
    {
        if(input[i] != '0' && input[i] != '1')
            return -1;
        int num = (input[i]) - '0';
        printf("debug5 %i %f %f\n",num,pow(2,power),num * pow(10,power));
        result += num * pow(2,power);
        printf("debug%i %i\n",i,result);
        power++;
    }
    return result;
}
