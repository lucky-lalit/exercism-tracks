#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void)
{

    struct list *result = malloc(sizeof(struct list));
    if (result == NULL)
        return NULL;
    result->first = NULL;
    result->last = NULL;
    return result;
}

size_t list_count(const struct list *list)
{
    printf("list_count\n");
    if (list == NULL)
        return 0;
    struct list_node *temp = list->first;
    size_t count = 0;
    while(temp != 0)
    {
        count++;
        temp = temp->next;
        
    }
    return count;
}

void list_push(struct list *list, ll_data_t item_data)
{
    if (list == NULL)
        return;
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = item_data;
    new_node->prev = NULL;
    if (list->first == NULL && list->last == NULL)
    {
        new_node->next = NULL;
        list->first = new_node;
        list->last = new_node;
    }
    else
    {
    list->first->prev = new_node;
    new_node->next = list->first;
    list->first = new_node;
    }

}

ll_data_t list_pop(struct list *list)
{

    if (list == NULL)
        return 0;
    ll_data_t data = list->first->data;
    
    if (list_count(list) == 1)
    {
     // data = list->first->data;
     free(list->first);
     list->first = NULL;
     list->last = NULL;
    }
    
    else
    {
        struct list_node *temp = list->first->next;
        free(list->first);
        list->first = temp;
        list->first->prev = NULL;
    }
    
    return data;
}


void list_unshift(struct list *list, ll_data_t item_data)
{
    if (list == NULL)
        return;
    
    struct list_node *new_node = malloc(sizeof(struct list_node));
    new_node->data = item_data;
    new_node->next = NULL;
    
    if (list->first == NULL && list->last == NULL)
    {
        new_node->prev = NULL;
        list->first = new_node;
        list->last = new_node;
    }
    
    else
    {
        list->last->next = new_node;
        new_node->prev = list->last;
        list->last = new_node;
    }
}

ll_data_t list_shift(struct list *list)
{
    printf("list_shift\n");
    if (list == NULL)
        return 0;
    
    ll_data_t data = list->last->data;
    
    if (list_count(list) == 1)
    {
     // data = list->first->data;
     free(list->last);
     list->first = NULL;
     list->last = NULL;
    }
    
    else{
        struct list_node *temp = list->last->prev;
        free(list->last);
        list->last = temp;
        list->last->next = NULL;
    }
    
    return data;
}


void list_delete(struct list *list, ll_data_t data)
{
    if (list == NULL)
        return;
    struct list_node *temp = list->first;
    
    while(temp != NULL && temp->data != data)
        temp = temp->next;
    
    if (temp == NULL)
        return;
    
    if (temp->next == NULL)
    {
        printf("last\n");
        if (temp->prev == NULL)
        { 
            list->first = NULL;
            list->last = NULL;
            free(temp);
            return;
        }
        struct list_node *ptr = temp->prev;
        free(temp);
        ptr->next = NULL;
        list->last = ptr;
    }
    
    else if (temp->prev == NULL)
    {
        printf("first\n");
        if (temp->next == NULL)
        {    
        list->first = NULL;
        list->last = NULL;
        free(temp);
        return;
        }
        struct list_node *ptr = temp->next;
        free(list->first);
        ptr->prev = NULL;
        list->first = ptr;
    }

    
    else {
        printf("middle\n");
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void list_destroy(struct list *list)
{
    printf("list_destroy\n");
    
    if (list == NULL)
        return;
    
    struct list_node *ptr = list->first;
    while(ptr != NULL)
    {
        struct list_node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(list);

}