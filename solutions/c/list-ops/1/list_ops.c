#include "list_ops.h"
#include <stdio.h>

list_t *new_list(size_t length, list_element_t elements[])
{
    printf("new_list\n");
    printf("new_list length = %li, elements_address = %p\n",length,(void *)elements);
    
    
    // if (length == 0 || elements == NULL)
    // {
    //     printf("empty\n");
    //     return NULL;
    // }
    printf("Non empty\n");
    list_t *result = NULL;
    // printf("element at index 0 %i\n",elements[0]);
    if (length == 0)
    {
        // result = malloc(sizeof(list_t));
        return NULL;
    }
    else
        result = malloc(sizeof(size_t) + (sizeof(list_element_t) * length));
    // result = malloc(sizeof(list_t) + (sizeof(list_element_t) * length ));
    // list_t *result = malloc(sizeof(list_t));
    printf("debug0\n");
    // size_t result_length = length;
    result->length = length;
    // result->elements = element_arr;
    // printf("%li\n",length);
    for (int i = 0; i < (int)length; i++)
        result->elements[i] = elements[i];
    printf("exit\n");
    return result;
        
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2)
{
    printf("append_list\n");
   size_t result_length;
   list_element_t *result_elements = NULL;
    printf("append list1_addres = %p, list2_address = %p\n",(void *)list1,(void *)list2);
    
    if (list1 == NULL && list2 == NULL)
        result_length = 0;
    
    else if (list1 == NULL)
        result_length = list2->length;
    
    else if(list2 == NULL)
        result_length = list1->length;
    
    else
        result_length = list1->length + list2->length;
    
    result_elements = malloc(sizeof(list_element_t) * result_length);
    printf("Non empty\n");
    
    if (list1 == NULL && list2 == NULL)
        printf("empty");
    else if (list1 == NULL)
    {
        for (int i = 0; i < (int)list2->length; i++)
            result_elements[i] = list2->elements[i];
    }
    else if(list2 == NULL)
    {
        for (int i = 0; i < (int)list1->length; i++)
            result_elements[i] = list1->elements[i];
    }
    else
    {
        for (int i = 0; i < (int)list1->length; i++)
            result_elements[i] = list1->elements[i];
        for (int i = 0; i < (int)list2->length; i++)
            result_elements[(int)list1->length + i] = list2->elements[i];
    }
    
    list_t *result = malloc(sizeof(size_t) + (sizeof(list_element_t) * result_length));
    
    result->length = result_length;
    
    for (int i = 0; i < (int)result_length; i++)
        result->elements[i] = result_elements[i];
    
    return result;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    printf("filter_list\n");
    size_t result_length;
   list_element_t *result_elements = NULL;
    if (list == NULL)
    {
        printf("empty");
        result_length = 0;
    }
    else
        result_length = list->length;
    result_elements = malloc(sizeof(list_element_t) * result_length);
    int index = 0;
    for (int i = 0;i < (int)result_length; i++)
    {
        if (filter(list->elements[i]))
        {
            result_elements[index] = (list->elements[i]);
            index++;
        }
    }
    list_t *result = malloc(sizeof(size_t) + (sizeof(list_element_t) * result_length));
    result->length = index;
    for (int i = 0; i < index; i++)
        result->elements[i] = result_elements[i];
    printf("Non empty\n");
    return result;
}

// returns the length of the list
size_t length_list(list_t *list)
{
    printf("length_list\n");
    if (list == NULL)
    {
        printf("empty\n");
        return 0;
    }
    printf("nonempty\n");
    return list->length;
    // return 0;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    printf("map_list\n");
    size_t result_length;
   list_element_t *result_elements = NULL;
    if (list == NULL)
    {
        printf("empty");
        result_length = 0;
    }
    else
        result_length = list->length;
    result_elements = malloc(sizeof(list_element_t) * result_length);
    // int count = 0; 
    for (int i = 0; i < (int)result_length; i++)
        result_elements[i] = map(list->elements[i]);
    list_t *result = malloc(sizeof(size_t) + (sizeof(list_element_t) * result_length));
    result->length = result_length;
    for (int i = 0; i < (int)result_length; i++)
        result->elements[i] = result_elements[i];
    printf("Non empty\n");
    return result;
    
    // printf("non empty\n");
    // return NULL;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
    printf("foldl_list\n");
    size_t result_length;
    if (list == NULL)
        result_length = 0;
    else
        result_length = list->length;
    
    for (int i = 0; i < (int)result_length; i++)
        initial = foldl(initial,list->elements[i]);
    return initial;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
    printf("foldr_list\n");
    size_t result_length;
    if (list == NULL)
        result_length = 0;
    else
        result_length = list->length;
    
    for (int i = result_length; i > 0; i--)
        initial = foldr(list->elements[i - 1],initial);
    return initial;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list)
{

    printf("reverse\n");
    size_t result_length;
   list_element_t *result_elements = NULL;
    if (list == NULL)
    {
        printf("empty");
        result_length = 0;
    }
    else
        result_length = list->length;
    
    result_elements = malloc(sizeof(list_element_t) * result_length);
    int index = 0;
    for (int i = result_length; i > 0; i--)
    {
        result_elements[index] = list->elements[i - 1];
        index++;
    }
    
    list_t *result = malloc(sizeof(size_t) + (sizeof(list_element_t) * result_length));
    
    result->length = result_length;
    
    for (int i = 0; i < (int)result_length; i++)
        result->elements[i] = result_elements[i];
    return result;
}


// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list)
{
    printf("delete_list\n");
    if (list == NULL)
    {
        printf("empty");
        return;
    }
    free(list);    
    printf("NON empty\n");
    // return NULL;
}