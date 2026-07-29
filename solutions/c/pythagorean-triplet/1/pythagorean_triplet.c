#include "pythagorean_triplet.h"
#include <stdlib.h>
#include <stdio.h>

triplets_t *triplets_with_sum(uint16_t sum)
{
    printf("%i\n",sum);
    triplets_t *result = malloc(sizeof(triplets_t));
    triplet_t *values = malloc(sizeof(triplet_t) * 10);
    int count_triplet = 0;
    for (int i = 0; i < sum / 2; i++)
    {
        for (int j = i; j < sum / 2; j++)
        {
            int k = sum - (i+j);
            if ((i*i) + (j * j) == (k*k) && (i + j + k == sum))
            {
                printf("%i %i %i\n",i,j,k);
                    printf("debug 0\n");
                    values[count_triplet].a = i;
                    printf("debug 1\n");
                    values[count_triplet].b = j;
                    printf("debug 2\n");
                    values[count_triplet].c = k;
                    printf("debug 3\n");
                    count_triplet++;
            }
        }
    }
    printf("debug4 %i\n",count_triplet);
    triplet_t *efficient_triplet = realloc(values,sizeof(triplet_t) * count_triplet);
    result->count = count_triplet;
    result->triplets = efficient_triplet;
    printf("debug5\n");
    return result;
}

void free_triplets(triplets_t *triplets)
{
    printf("free\n");
    if (triplets == NULL)
        return;
    free(triplets->triplets);
    free(triplets);
}