#include "anagram.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void find_anagrams(const char *subject, struct candidates *candidates)
{
    int sub_len = strlen(subject);
    for (int i = 0; i < (int)candidates->count; i++)
    {
        int candidate_len = strlen(candidates->candidate[i].word);
        if (sub_len != candidate_len)
        {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
        }
        int arr[26] = {0};
        int same_count = 0;
        for (int j = 0; j < candidate_len; j++)
        {
            if (tolower(candidates->candidate[i].word[j]) ==  tolower(subject[j]))
                same_count++;
            arr[tolower(candidates->candidate[i].word[j]) - 'a'] += 1;
            arr[tolower(subject[j]) - 'a'] -= 1; 
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == 0)
                count++;
        }
        // printf("count %i\n",count);
        if (count == 26 && same_count != sub_len)
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        else
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }

    }
    





    
    // // candidates result;
    // // printf("%d\n",(*candidates).is_anagram);
    // if (candidates == NULL)
    //     return;
    // if ((*candidates).count == 0)
    //     return;
    // if ((candidates->count) > 2)
    // {
    //     printf("debug1 %i\n",candidates->candidate[0].is_anagram);
    //     printf("debug2 %s\n",candidates->candidate[0].word);
    //     printf("debug3 %s\n",candidates->candidate[1].word);
    //     printf("debug4 %s\n",candidates->candidate->word);
    //     printf("debug5 %c\n",candidates->candidate[1].word[2]);
    //     int len = strlen(candidates->candidate[2].word);
    //     printf("%i\n",len);
    //     // printf("debug_1 %s\n",candidates[1]candidate->word);
    //     // printf("debug %i\n",candidates[1].candidate);
    //     // printf("debug 1 %d\n",candidates[1].candidate->word);
        
    // }
    // for (int i =0 ; i < (int)candidates->count; i++)
    // {
    //     printf("candidate %i = %s\n",i,candidates->candidate[i].word);
    //     int candidate_len = strlen(candidates->candidate[i].word);
    //     printf("len %i\n",candidate_len);
    //     candidates->candidate[i].is_anagram = NOT_ANAGRAM;
    //     printf("anagram %i\n",candidates->candidate[i].is_anagram);
    // }

    // // printf("debug5 %c",candidates->candidate[1].word[1]);
    // // printf("%i\n",(*(*candidates).candidate).is_anagram);
    // // printf("%i\n",candidates->candidate->is_anagram);
    // // printf("%i\n",((candidates[0]).candidate[0]).is_anagram);
    
    // printf("%li\n",(*candidates).count);
    // // result.count = 0;
    
    
    // printf("check %s\n",subject);
    // printf
// }

