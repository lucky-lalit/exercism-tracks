#ifndef INTERGALACTIC_TRANSMISSION_H
#define INTERGALACTIC_TRANSMISSION_H

#include <stdint.h>
#include <stdlib.h>

#define WRONG_PARITY -1

int transmit_sequence(uint8_t *buffer, const uint8_t *message,
                      int message_length);

int decode_message(uint8_t *buffer, const uint8_t *message, int message_length);

int decimal_to_ouput(int8_t io_digits[],uint8_t decimal,int16_t output_base);


int base_to_decimal(int8_t io_digits[],int16_t input_base,size_t input_length);

void print_binary(int8_t array[]);
#endif
