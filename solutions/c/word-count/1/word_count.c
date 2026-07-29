#include "word_count.h"
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int count_words(const char *sentence, word_count_word_t *words)
{
    char next_word[MAX_WORD_LENGTH + 1] = {'\0'};
    printf("%i\n",words->count);
    int i = 0;
    int index = 0;
    printf("the length of string %li\n",strlen(sentence));
    // while (i < (int)strlen(sentence) )
    printf("debug0 %s\n",sentence);
    printf("debug1 %li\n",strlen(sentence));
    
    while(sentence[i] != '\0')
    {
    printf("debug2 %c , %i\n",sentence[i],i);
     // i++;
    get_next_word(i,sentence,next_word);
    printf("the len sum  %li\n",strlen(next_word));
    if (strlen(next_word) == 0)
    {i = i + 1;
     continue;
    }  
    else
        i += strlen(next_word);
        
    printf("next_word %s\n",next_word);
    if (check_word(words,next_word) == -1)
    {
        strcpy(words[index].text,next_word);
        words[index].count = 1;
        index++;
    }
    else{
        words[check_word(words,next_word)].count++;
    }
    // i = strlen(next_word) + 1;
    // int index = (check_word(words,next_word));
    // printf("%i\n",index);
    }
     return index;
}

void get_next_word(int i,const char *inp_str,char next_word[MAX_WORD_LENGTH + 1])
{
    // printf("get_next_word\n");
    // printf("%i\n",i);
    // printf("%s\n",inp_str);
    // printf("%s\n",next_word);
    // printf("first_char %c\n",inp_str[i]);
    int index = 0;
    if (i >= (int)strlen(inp_str))
        return;
    if (isalnum(inp_str[i])){
         while(inp_str[i] != '\0' && ((isalnum(inp_str[i]) || inp_str[i] == '\'')))
         {
            next_word[index] = tolower(inp_str[i]);
            index++;
             i++;
         }
        if (next_word[index-1] == '\'')
            index--;
    }
    // printf("debug0 \n");
    next_word[index] = '\0';
    return;
}

int check_word(word_count_word_t *words,char *target_word)
{
    // printf("check_word\n");
    // printf("debug0 %li\n",strlen(target_word));
    // if (strlen(target_word) == 0)
    //     return -1;
    for (int i = 0; i < 20; i++)
    {
        if (strcasecmp(words[i].text,target_word) == 0)
            return i;
    }
    return -1;
}


