#include "all_your_base.h"
#include <stdio.h>
#include <math.h>


size_t rebase(int8_t io_digits[],int16_t input_base, int16_t output_base,size_t input_length)
{
    if (input_base < 2 || output_base < 2)
        return 0;
    printf("debug1\n");
    if (input_length == 0) 
        return 0;
    printf("debug1\n");
    for (int i = 0; i < (int)input_length; i++)
    {
        if (io_digits[i] < 0)
            return 0;
    }
    int count = 0;
    for (int i = 0; i < (int)input_length; i++)
    {
        if (io_digits[i] == 0)
            count++;
        if ((int)input_length == count)
            return 1;
    }
    for (int i = 0; i < (int)input_length; i++)
    {
        if (io_digits[i] >= input_base)
            return 0;
    }
    if (input_length == 1 && (io_digits[0] == 0))
        return 1;
    int decimal_value = base_to_decimal(io_digits,input_base,input_length);
    int output = decimal_to_ouput(io_digits,decimal_value,output_base);
    return output;
}


int base_to_decimal(int8_t io_digits[],int16_t input_base,size_t input_length)
{
    int sum = 0;
    for (int i = 0; i < (int)input_length; i++)
    {
        // sum = (sum * input_base) + io_digits[i];
        sum += ((io_digits[input_length - (i + 1)]) * (int)(floor(pow(input_base,i))));
    }
    return sum;
}
// int arr[10] = {0};
// int count = 0;
int decimal_to_ouput(int8_t io_digits[],int decimal,int16_t output_base)
{
    // index = 0;
    int arr[10] = {0};
    int count = 0;
    while(decimal != 0)
    {
        arr[count] = decimal % output_base;
        decimal = decimal / output_base;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        io_digits[i] = arr[count - (i + 1)];
    }
    return count;
}