#include "high_scores.h"
#include <stdio.h>

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{   
    int32_t temp[scores_len];
    printf("%ls %ls\n",scores,output);
    for (size_t i = 0; i < scores_len; i++)
    {
     temp[i] = scores[i];   
    }
     for (size_t i = 0; i < scores_len; i++)
     {
         for (size_t j = 0; j < scores_len - i - 1; j++)
         {
             if (temp [j] > temp[j+1])
             {
                 int32_t tempp = temp[j];
                 temp[j] = temp[j+1];
                 temp[j+1] = tempp;
             }
         }
     }
    size_t count = 3;
    if (scores_len < count)
        count = scores_len;
    for (size_t i = 0; i < count; i++)
    {
        output[i] = temp[scores_len - i - 1];
    }
    // printf("%i\n",output[count-1]);
    // printf("%i\n",temp[count-2]);
    // printf("%i\n",temp[count-3]);
    return count;
}

int32_t latest(const int32_t *scores, size_t scores_len)
{
    // printf("%li\n",scores_len);
    // printf("%i\n",scores[scores_len - 1]);
    // printf("%i\n",scores[-2]);
    // printf("%i\n",scores[-3]);
    // printf("%i\n",scores[-4]);
    return *(scores + (scores_len - 1));
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    // printf("%li\n",scores_len);
    int32_t largest = 0;
    for (size_t i = 0; i < scores_len; i++)
    {
     if (largest < *(scores + i))
         largest = *(scores + i);
    }
    // printf("%i\n",largest);
    return largest;
}