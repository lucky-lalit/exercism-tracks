#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *count(const char *dna_strand)
{
    int len = strlen(dna_strand);
    printf("%i\n",len);
    char *temp = malloc(20);
    if (len >= 1)
    {
        for (int i = 0; i < len; i++)
        {   if((dna_strand[i] != 'A' && dna_strand[i] !=                 'G') && (dna_strand[i] != 'C' && dna_strand[i] != 'T'))
                {        temp[0] = '\0';
                         return temp;
                }        
        }    
    }
    int arr[26] = {0};
    for (int i = 0; i < len; i++)
    {
        arr[dna_strand[i] - 65] += 1; 
    }
    sprintf(temp,"A:%i C:%i G:%i T:%i",arr['A' - 65],arr['C'- 65],arr['G' - 65],arr['T' - 65]);
    return temp;
}