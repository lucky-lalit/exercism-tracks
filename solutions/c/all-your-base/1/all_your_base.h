#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H
#include <stddef.h>
#include <stdint.h>

#define DIGITS_ARRAY_SIZE 64
size_t rebase(int8_t io_digits[],int16_t input_base, int16_t output_base,size_t input_length);

int base_to_decimal(int8_t io_digits[],int16_t input_base,size_t input_length);

int decimal_to_ouput(int8_t io_digits[],int decimal,int16_t output_base);
#endif
