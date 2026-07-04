#include "sublist.h"
#include <stdio.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
    if (list_to_compare == NULL && base_list == NULL )
        return EQUAL;
    if (list_to_compare == NULL && list_to_compare_element_count == 0)
        return SUBLIST;
    if (base_list == NULL && base_list_element_count == 0)
        return SUPERLIST;
    // printf("%i\n",*(list_to_compare));
    // printf("%i\n",*(base_list));
    // printf("%li\n",list_to_compare_element_count);
    // printf("%li\n",base_list_element_count);
    if (list_to_compare_element_count == base_list_element_count)
    {
        int count = 0;
        for (int i = 0; i < (int)list_to_compare_element_count; i++)
        {
            if (*(list_to_compare + i) == *(base_list + i))
                count++;
        }
        if (count == (int)list_to_compare_element_count)
            return EQUAL;
        else 
            return UNEQUAL;
    }
    if (list_to_compare_element_count > base_list_element_count)
    {
        for (int i = 0; i < (int)list_to_compare_element_count; i++)
        {
            for (int j = 0; j < (int)base_list_element_count; j++)
            {
                if (*(list_to_compare + i + j) != *(base_list + j))
                    break;
                if (j == (int)base_list_element_count - 1)
                return SUPERLIST;
            }
        }
    }
    if (list_to_compare_element_count < base_list_element_count)
    {
        for (int i = 0; i < (int)base_list_element_count; i++)
        {
            for (int j = 0; j < (int)list_to_compare_element_count; j++)
            {
                if (*(base_list + i + j) != *(list_to_compare + j))
                    break;
                if (j == (int)list_to_compare_element_count - 1)
                    return SUBLIST;
            }
        }
    }
    return UNEQUAL;
}