#include "largest_series_product.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int64_t largest_series_product(char *digits, size_t span)
{
    int product = 0;
    int count = 0;
    int len = strlen(digits);
    if (len < (int)span || (int)span < 0)
        return -1;
    while(count <= len - (int)span)
    {
        int sum = 1;
        for (int i = count; i < (int)span + count; i++)
        {
            if (!isdigit(digits[i]))
                return -1;
            sum = sum * (digits[i] - '0');
        }
        if (sum > product)
            product = sum;
        count++;
    }
    return product;
}