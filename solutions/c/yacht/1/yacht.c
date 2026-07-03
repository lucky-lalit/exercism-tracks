#include "yacht.h"
#include <stdio.h>
int score(dice_t dice, category_t category)
{
    int arr[6] = {0};
    int count = 0;
    // int zeros_count = 0;
    if (category == YACHT)
    {
    for (int i = 1; i < 5; i++)
    {
        if (dice.faces[i - 1] != dice.faces[i])
            return 0;
    }
    return 50;
    }
    if (category == ONES)
    {
        for (int i = 0; i < 5; i++)
        {
            if(dice.faces[i] == 1)
                count++;
        }
    return count;
    }
    if (category == TWOS)
    {
        for (int i = 0; i < 5; i++)
        {
            if(dice.faces[i] == 2)
                count++;
        }
    return count * 2;
    }
    if (category == THREES)
    {
        for (int i = 0; i < 5; i++)
        {
            if(dice.faces[i] == 3)
                count++;
        }
    return count * 3;
    }
    if (category == FOURS)
    {
        for (int i = 0; i < 5; i++)
        {
            if(dice.faces[i] == 4)
                count++;
        }
    return count * 4;
    }
    if (category == FIVES)
    {
        for (int i = 0; i < 5; i++)
        {
            if(dice.faces[i] == 5)
                count++;
        }
    return count * 5;
    }
    if (category == SIXES)
    {
        for (int i = 0; i < 5; i++)
        {
            if(dice.faces[i] == 6)
                count++;
        }
    return count * 6;
    }
    int zeros_count = 0;
    if (category == FULL_HOUSE)
    {
        for (int i = 0;i < 5; i++)
        {
            arr[dice.faces[i] - 1] += 1;
            count = count + dice.faces[i];
        }
        for (int i = 0;i < 6;i++)
        {
            if (arr[i] == 0)
                zeros_count++;
            if (arr[i] > 3)
                return 0;
        }
        if (zeros_count == 4)
            return count;
        else 
            return 0; 
    }
    // int zeros_count = 0;
    int valid = 0;
    if (category == FOUR_OF_A_KIND)
    {
        for (int i = 0;i < 5; i++)
        {
            arr[dice.faces[i] - 1] += 1;
        }
        for (int i = 0;i < 6;i++)
        {
            if (arr[i] == 0)
                zeros_count++;
            if (arr[i] == 4)
                valid++;
        }
        if (valid == 0 && zeros_count != 5)
            return 0;
        for (int i = 1; i < 5; i++)
        {
            if (dice.faces[i - 1] == dice.faces[i])
            {    count = dice.faces[i];
                break;
            }
        }    
        printf("debug %i\n",zeros_count);
        if (zeros_count == 4 || zeros_count == 5)
            return count * 4;
        else
            return 0;
    }
    if (category == LITTLE_STRAIGHT)
    {
        for (int i = 1; i < 5; i++)
        {
            if (dice.faces[i - 1] == dice.faces[i])
                return 0;
        }
        for (int i = 0; i < 5; i++)
        {
            if (dice.faces[i] == 6)
                return 0;
        }
        return 30;
    }
    if (category == BIG_STRAIGHT)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice.faces[i] == 1)
                return 0;
        }
        return 30;
    }
    if (category == CHOICE)
    {
        for (int i = 0; i < 5;i++)
            count = count + dice.faces[i];

    return count;
    }
    return 0;
}