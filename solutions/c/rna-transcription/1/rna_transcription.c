#include "rna_transcription.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna)
{
    int len = strlen(dna);
    char *rna = malloc((len + 1) * sizeof(char));
    if (rna == NULL)
    {
        printf("ERROR");
    }
    for (int i = 0 ; i < len; i++)
    {
        if (dna[i] == 'G')
            rna[i] = 'C';
        else if(dna[i] == 'C')
            rna[i] = 'G';
        else if(dna[i] == 'T')
            rna[i] = 'A';
        else if(dna[i] == 'A')
            rna[i] = 'U';
    }
    rna[len] = '\0';
    return rna;
    // free (rna);
}
