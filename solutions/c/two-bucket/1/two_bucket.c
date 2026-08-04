#include "two_bucket.h"
#include <stdlib.h>
#include <stdio.h>


bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket)
{
    printf("inside measure with args\n");
    printf("bucket_1_size = %i\n", bucket_1_size);
    printf("bucket_2_size = %i\n", bucket_2_size);
    printf("goal_volume = %i\n", goal_volume);
    printf("start_bucket = %i\n", start_bucket);
    bucket_result_t result ;
    result.possible = false;
    result.move_count = 0;
    result.goal_bucket = BUCKET_ID_1;
    result.other_bucket_liters = 0;

    // check invalid case
    if (goal_volume > bucket_1_size && goal_volume > bucket_2_size)
        return result;

    printf("valid inputs\n");

    // check early exit on bucket 1
    if (goal_volume == bucket_1_size)
    {
        result.possible = true;
        result.move_count = 1;
        result.goal_bucket = BUCKET_ID_1;
        result.other_bucket_liters = 0;
        if (start_bucket == BUCKET_ID_2)
        {
            result.move_count = 2;
            result.other_bucket_liters = bucket_2_size;
        }
        printf("early exit with bucket 1\n");
        return result;
    }

    // check early exit on bucket 2
    if (goal_volume == bucket_2_size)
    {
        result.possible = true;
        result.move_count = 1;
        result.goal_bucket = BUCKET_ID_2;
        result.other_bucket_liters = 0;
        if (start_bucket == BUCKET_ID_1)
        {
            result.move_count = 2;
            result.other_bucket_liters = bucket_1_size;
        }
        printf("early exit with bucket 2\n");
        return result;
    }

    printf("check with tranfer\n");
    bucket_liters_t start_curr_water = 0;
    bucket_liters_t other_curr_water = 0;
    bucket_liters_t start_capacity = bucket_1_size;
    bucket_liters_t other_capacity = bucket_2_size;
    bucket_id_t other_bucket = BUCKET_ID_2;
    if (start_bucket == BUCKET_ID_2)
    {
        start_capacity = bucket_2_size;
        other_capacity = bucket_1_size;
        other_bucket = BUCKET_ID_1;
    }

    while (1) // Fill Start
    {
        // if (result.move_count > 5)
        //     break;
        start_curr_water = start_capacity; // Fill Start
        result.move_count++;
        display_state(result.move_count, start_curr_water, other_curr_water);

        while (start_curr_water > 0) // Transfer From Start
        {
            // if (result.move_count > 5)
            //     break;

            if (other_curr_water == other_capacity) // Empty Other
            {
                other_curr_water = 0; // Empty Other
                result.move_count++;
                display_state(result.move_count, start_curr_water, other_curr_water);
            }

            // Transfer From Start
            bucket_liters_t total_water = start_curr_water + other_curr_water;
            if (total_water > other_capacity)
                other_curr_water = other_capacity;
            else
                other_curr_water = total_water;
            start_curr_water = total_water - other_curr_water;
            result.move_count++;
            display_state(result.move_count, start_curr_water, other_curr_water);
            // Transferred From Start

            // check target achieved
            if (start_curr_water == goal_volume) {
                result.possible = true;
                result.goal_bucket = start_bucket;
                result.other_bucket_liters = other_curr_water;
                return result;
            }
            else if (other_curr_water == goal_volume) {
                result.possible = true;
                result.goal_bucket = other_bucket;
                result.other_bucket_liters = start_curr_water;
                return result;
            }
        }

        if (other_curr_water == other_capacity)
            return result;
    }
    return result;
}

void display_state(int move, bucket_liters_t start_volume, bucket_liters_t other_volume) {
    printf("move = %i, start = %i, other = %i\n", move, start_volume, other_volume);
}