#include "circular_buffer.h"
#include <stdio.h>


int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (buffer->current_length == buffer->capacity)
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    if (buffer->oldest_index == -1)
        buffer->oldest_index = 0;
    buffer->newest_index = ((buffer->newest_index + 1) % buffer->capacity);
    buffer->arr[buffer->newest_index] = value;
    buffer->current_length++;
    
    return EXIT_SUCCESS;
}
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    if (buffer->current_length == buffer->capacity)
    {    buffer->arr[buffer->oldest_index] = value;
        buffer->oldest_index = ((buffer->oldest_index + 1) % buffer->capacity);
        buffer->newest_index = ((buffer->newest_index + 1) % buffer->capacity);
    }
    else{
       buffer->newest_index = ((buffer->newest_index + 1) % buffer->capacity);
    buffer->arr[buffer->newest_index] = value;
    buffer->current_length++; 
    }
    return EXIT_SUCCESS;;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value)
{
    if ((buffer->current_length == 0))
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    else{
        *(value) = buffer->arr[buffer->oldest_index];
        buffer->oldest_index = ((buffer->oldest_index + 1) % buffer->capacity);
        buffer->current_length--;
    }
    return EXIT_SUCCESS;
}

circular_buffer_t *new_circular_buffer(size_t size)
{
    circular_buffer_t *result = malloc(sizeof(circular_buffer_t));
    result->capacity = size;
    result->current_length = 0;
    result->newest_index = -1;
    result->oldest_index = -1;
    buffer_value_t *arry = malloc(sizeof(int) * size);
    for (int i = 0; i < (int)size; i++)
    {
        arry[i] = 0;
    }
    result->arr=arry;    
    return result;
}

void delete_buffer(circular_buffer_t * buffer)
{
    free(buffer->arr);
    free(buffer);
}

void clear_buffer(circular_buffer_t * buffer)
{
    for (int i = 0; i < (int)buffer->capacity; i++)
    {
        buffer->arr[i] = 0;
    }
    buffer->current_length = 0;
    buffer->oldest_index = -1;
    buffer->newest_index = -1;

}