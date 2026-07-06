#include "variable_length_quantity.h"

#include <stdio.h>
int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   // write to `output`, return final output's length
   // `output` buffer should be enough to hold the full result

    int arr[10] = {0};
    int total_count = 0;
    int index = -1;
    for (int i = 0; i < (int)integers_len; i++)
    {
        int count = 0;
        long number = integers[i];
        if (number == 0)
        {
            index++;
            total_count++;
            *(output+index) = 0;
        }
        while(number != 0)
        {
            arr[count] = number % 128;
            number = number / 128;
            count++;
            total_count++;
        }
        for (int j = 0; j < count; j++)
        {
            index++;
            if (j + 1 == count)
                *(output + index) = arr[count - (j + 1)];
            else
                *(output + index) = arr[count - (j + 1)] + 128;
        }
    }
    return total_count;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   // write to `output`, return final output's length
   // return -1 if error
   // `output` buffer should be enough to hold the full result
    int index = 0;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < (int)buffer_len; i++)
    {
        if (buffer_len == 1 && *(bytes + i) >= 128)
            return -1;
        if (*(bytes + i) < 128 && *(bytes + (i - 1)) < 128 && i != 0)
        {
            *(output + index) = *(bytes + i);
            index++;
            count++;
        }
        else if(*(bytes+i) >= 128)
        {
            sum = sum * 128 + (*(bytes+i) - 128);
        }
        else
        {
            sum = sum * 128 + *(bytes + i);
            *(output + index) = sum;
            index++;
            count++;
            sum = 0;
        }
    }
    return count;
}
