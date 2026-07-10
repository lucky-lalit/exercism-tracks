#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>

typedef uint16_t buffer_value_t;
// tyepdef
typedef char* string;
// typedef enum {       
// }buffer_value_t;

typedef struct{
    
    int newest_index;
    int oldest_index;
    size_t capacity;
    size_t current_length;
    buffer_value_t *arr;

}circular_buffer_t;

int16_t write(circular_buffer_t *buffer, buffer_value_t value);

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

int16_t read(circular_buffer_t *buffer, buffer_value_t *value);

circular_buffer_t *new_circular_buffer(size_t size);

void delete_buffer(circular_buffer_t * buffer);

void clear_buffer(circular_buffer_t * buffer);

// uint16_t read

#endif
