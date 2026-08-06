#include "intergalactic_transmission.h"
#include <stdio.h>
#include <math.h>
int transmit_sequence(uint8_t *buffer, const uint8_t *message,
                      int message_length)
{
    // printf("binary = %b\n",10);
    if (message_length == 0)
        return 0;
    if (buffer == NULL)
        return -1;
    if (message == NULL)
        return -1;
    if (message_length == 0)
        return 0;
    printf("%i\n",message_length);
    int index = 0;
    int8_t complete[message_length * 8];
    for (int i = 0; i < message_length * 8;i++)
        complete[i] = 0;
    for (int i = 0; i < message_length; i++)
    {
        int8_t result[10] = {0};
        decimal_to_ouput(result,message[i],2);
        for (int i = 0; i < 8; i++)
        {
            complete[index] = result[i];
            index++;
        }
        print_binary(result);
    }
    int ones_count = 0;
    int parity_check = 0;
    int idx = 0;
    int8_t output[8] = {0};
    for (int i = 0; i < message_length * 8;i++)
    {
        output[parity_check] = complete[i];
        if (output[parity_check] == 1)
            ones_count++;
        parity_check++;
        printf("parity %i\n",parity_check);
        if (parity_check == 7 || (i + 1 == message_length * 8))
        {
            if (ones_count % 2 == 0)
                output[7] = 0;
            else
                output[7] = 1;
            print_binary(output);
            printf("%d\n", base_to_decimal(output,2,8));
            buffer[idx] = base_to_decimal(output,2,8);
            idx++;
            // printf("added parity %i\n",parity_check);
            ones_count = 0;
            parity_check = 0;
            for (int i = 0; i < 8;i++)
                output[i] = 0;
            
        }
        // printf("%i",complete[i]);
    }
    // printf(""/n");
    return idx;
    
}

int decode_message(uint8_t *buffer, const uint8_t *message, int message_length)
{
    if (message_length == 0)
        return 0;
    if (buffer == NULL)
        return -1;
    if (message == NULL)
        return -1;
    int index = 0;
    int count = 0;
    int8_t complete[message_length * 7];
    for (int i = 0; i < message_length * 8;i++)
        complete[i] = 0;
    for (int i = 0; i < message_length; i++)
    {
        int8_t result[10] = {0};
        decimal_to_ouput(result,message[i],2);
        for (int i = 0; i < 8; i++)
        {
            if (result[i] == 1)
                count++;
        }
        if (count % 2 != 0)
            return -1;
        count = 0;
        for (int i = 0; i < 7; i++)
        {
            complete[index] = result[i];
            index++;
        }
        print_binary(result);
    }
    printf("%i\n",message_length);
    int idx = 0;
    count = 0;
    int8_t output[8] = {0};
    for (int i = 0; i < message_length * 7;i++)
    {
        output[count] = complete[i];
        count++;
        if (count == 8 || (i + 1 == message_length * 8))
        {
            buffer[idx] = base_to_decimal(output,2,8);
            idx++;
            count = 0;
            for (int i = 0; i < 8; i++)
                output[i] = 0;
            continue;
        }
        // count++;
    }
    return idx;
    
    
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



int decimal_to_ouput(int8_t io_digits[],uint8_t decimal,int16_t output_base)
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
    io_digits[8 - count + i] = arr[count - 1 - i];
}
    // for (int i = 0; i < count; i++)
    // {
    //     io_digits[i] = arr[count - (i + 1)];
    // }
    return count;
}

void print_binary(int8_t array[])
{
    printf("0b->");
    for (int i = 0; i < 8; i++)
    {
        printf("%i",array[i]);
    }
    printf("\n");
}