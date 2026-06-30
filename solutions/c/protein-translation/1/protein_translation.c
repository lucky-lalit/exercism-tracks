#include "protein_translation.h"
#include <stdio.h>
#include <string.h>

protein_t protein(const char *const rna)
{
    protein_t result;
    result.count = 0;
    // result.valid = false;
    // printf("%s\n",rna);
    int len = strlen(rna);
    // if (len % 3 != 0)
    // {
    //     printf("lenfalse");
    //     return result;
    // }
    if (len == 0)
    {   
        result.valid = true;
        return result;
    }
    char temp[4];
    // int count = 0;
    // return result;
    for (int i = 0; i < len; i = i + 3)
    {
        // return result;
        int index = 0;
        for (int j = i; j < i + 3; j ++)
        {
            // return result;
            temp[index] = rna[j];
            // return result;
            index++;
            // return result;
        }
        // return result;
        temp[3] = '\0';
        // return result;
        if (strcmp(temp,"AUG") == 0)
        {   
            result.amino_acids[result.count] = 0;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UUU") == 0)
        {   
            result.amino_acids[result.count] = 1;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UUC") == 0)
        {   
            result.amino_acids[result.count] = 1;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UUA") == 0)
        {   
            result.amino_acids[result.count] = 2;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UUG") == 0)
        {   
            result.amino_acids[result.count] = 2;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UCU") == 0)
        {   
            result.amino_acids[result.count] = 3;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UCC") == 0)
        {   
            result.amino_acids[result.count] = 3;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UCA") == 0)
        {   
            result.amino_acids[result.count] = 3;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UCG") == 0)
        {   
            result.amino_acids[result.count] = 3;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UAU") == 0)
        {   
            result.amino_acids[result.count] = 4;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UAC") == 0)
        {   
            result.amino_acids[result.count] = 4;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UGU") == 0)
        {   
            result.amino_acids[result.count] = 5;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UGC") == 0)
        {   
            result.amino_acids[result.count] = 5;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UGG") == 0)
        {   
            result.amino_acids[result.count] = 6;
            result.count++;
            result.valid = true;
        }
        else if (strcmp(temp,"UAA") == 0)
        {   result.valid = true;
            return result;
        }
        else if (strcmp(temp,"UAG") == 0)
        {   result.valid = true;
            return result;
        }
        else if (strcmp(temp,"UGA") == 0)
        {   result.valid = true;
            return result;
        }
        else
        {
            result.valid = false;
            return result;
        }       
    }
    // result.amino_acids[1] = 4;
    return result;
}