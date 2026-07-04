#include "scrabble_score.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned int score(const char *word)
{
    static const int arr[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int len = strlen(word);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        char copy = tolower(word[i]);
        sum += arr[copy - 'a'];
        
    }
    return sum;
}