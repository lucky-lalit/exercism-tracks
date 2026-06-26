#include "gigasecond.h"
#include <stdio.h>

void gigasecond(time_t input, char *output, size_t size)
{
    // struct tm *gm_time = gm_time(&input);
    // printf("tm_sec : %d\n", gm_time->tm_sec);
    printf("debug 1 %li\n",input);
    printf("debug 2 %li\n",size);
    printf("debug 3 %s\n",output);
    time_t new_time = input + 1000000000;
    // char *ctime_result = ctime(&new_time);
    // printf("%s debug4 \n",ctime_result);
    struct tm *tm_time = gmtime(&new_time);
    char *format = "%Y-%m-%d %H:%M:%S";
    strftime(output, size, format, tm_time);
}