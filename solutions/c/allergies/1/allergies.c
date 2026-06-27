#include "allergies.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool is_allergic_to(allergen_t allergy, int allergy_score)
{
    printf("debug inside is_allergic_to");
    printf("%i\n",allergy);
    printf("%i\n",allergy_score);
    int index = 0;
    while(true)
    {
        int is_i_allergy = allergy_score % 2;
        if(index == (int)allergy && is_i_allergy == 1)
            return true;
        allergy_score = allergy_score / 2;
        index++;
        if(allergy_score == 0)
            break;
    }

    // allergy_score = allergy_score / (pow(2,allergy));
    // int is_allergic = allergy_score % 2;
    // return is_allergic == 1;
    
    return false;
}

allergen_list_t get_allergens(int score)
{
    printf("%i\n",score);
    allergen_list_t result;
    result.count = 0;
    // result.allergens[2] = true;
    for (allergen_t i = 0;i < ALLERGEN_COUNT; i++)
    {
        bool is_allergic = is_allergic_to(i,score);
        if (is_allergic)
            result.count++;
        result.allergens[i] = is_allergic;
    }
    return result;
}