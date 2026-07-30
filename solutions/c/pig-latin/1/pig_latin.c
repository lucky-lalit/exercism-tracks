#define _GNU_SOURCE
#include "pig_latin.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>


char *translate(const char *phrase)
{

    char *write_phrase = malloc(strlen(phrase) + 1);
    strcpy(write_phrase,phrase);
    char *result = malloc(1);
    result[0] = '\0';
  while (write_phrase != NULL)
  {
    char *word = strsep(&write_phrase, " ");
    char *new_word =translate_word(word);
    int current_len_result = strlen(result);
    char *temp = realloc(result, strlen(result) + strlen(new_word) + 1 + 1);
    if (temp == NULL)
      return NULL;
    
    result = temp;
      if (current_len_result > 0)
      {
          strcat(result," ");
      }
    // strcat(result," ");
    strcat(result, new_word);
  }
    return result;
    // int len = strlen(phrase);
    // char *result = malloc(len * len);
    // int index = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     if (isalpha(phrase[i]))
    //     {
    //         result[index] = phrase[i];
    //         index++;
    //     }
    //     else if (i+1 == len)
    //     {
    //         if (result[0] == 'a' || result[0] == 'e' || result[0] == 'i' || result[0] == 'o' || result[0] == 'u' || ((result[0] == 'x') && (result[1] == 'r')) || ((result[0] == 'y') && (result[1] == 't'))) 
    //         {
    //             strcpy(result,add_ay(result));
    //         }
            
            
    //     }
    //     else
    //     {
            
    //     }
    // }
    return translate_word(phrase);
}
char *translate_word(const char *word)
{
    int i = get_i(word);
    char *new_result = move_to_i(i,word);
    return add_ay(new_result);
}

int get_i(const char *str)
{
  int have_i_seen_consonant = 0;
  int have_i_seen_vowels = 0;
  
  for(int i=0; i < (int)strlen(str); i++){

    switch(str[i]) {
      case ' ':
        continue;
        break;
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        have_i_seen_vowels = 1;
        break;
      default:
        have_i_seen_consonant = 1;
    }
    
    // rule 1
    if (i == 0) // check start
    {
        printf("debug rule\n");
      if (have_i_seen_vowels == 1)
        return i;
      if (i <= (int)(strlen(str)-2))
      {
        if (str[i] == 'x' && str[i+1] == 'r')
          return i;
        if (str[i] == 'y' && str[i+1] == 't')
          return i;
      }
    }
    
    // rule 2
    if (have_i_seen_consonant == 1 && have_i_seen_vowels == 1)
      return i;
      
    // rule 3
    if (i <= (int)strlen(str)-2)
    {
      if (str[i] == 'q' && str[i+1] == 'u')
        return i+2;
    }
    
    // rule 4
    if (i > 0 && have_i_seen_consonant == 1 && str[i] == 'y')
      return i;
        
  }
    return 0;
}

char *add_ay(char *string)
{
    if (string == NULL)
        return NULL;
  
  char *new_string = realloc(string,strlen(string) + 3);
  strcat(new_string,"ay");
  return new_string; 
}

char *move_to_i(int index,const char *string)
  {
    if (string == NULL)
      return NULL;
    // if (index == 0)
      // return string;
    int len = strlen(string);
    if (index >= len)
      return NULL;
    
    
    char *new_str = malloc(len+1);
    for (int i = 0; i < len; i++)
    {
      new_str[i] = string[(i+index)%len];
      if (i+1 == len)
        new_str[i+1] = '\0';
      }
    return new_str;
    
    }
