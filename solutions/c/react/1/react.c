#include "react.h"
#include <stdlib.h>
static void update_children(struct cell *cell);

static callback_id next_callback_id = 1;

enum cell_type
{
    INPUT,
    COMPUTE1,
    COMPUTE2
};

struct callback_node
{
    callback_id id;

    void *data;

    callback fn;

    struct callback_node *next;
};

struct reactor
{
    struct cell *head;
};

struct cell
{
    int value;

    enum cell_type type;

    struct cell *dep1;
    struct cell *dep2;

    compute1 fn1;
    compute2 fn2;

    struct cell **children;
    int child_count;

    struct cell *next_in_reactor;

    struct callback_node *callbacks;

    struct reactor *reactor;

    int old_value_before_update;
};


struct reactor *create_reactor(void)
{
    struct reactor *reactor = malloc(sizeof(struct reactor));
    reactor->head = NULL;
    return reactor;
}

void destroy_reactor(struct reactor *reactor)
{
    struct cell *current = reactor->head;
    while (current != NULL)
    {
    struct cell *next = current->next_in_reactor;
    free(current->children);
    free(current);
    current = next;
    }
    free(reactor);
}

struct cell *create_input_cell(struct reactor *reactor,
                               int initial_value)
{
    struct cell *new_cell = malloc(sizeof(struct cell));
    if (new_cell == NULL)
        return NULL;
    new_cell->value = initial_value;
    new_cell->type = INPUT;
    new_cell->dep1 = NULL;
    new_cell->dep2 = NULL;
    new_cell->fn1 = NULL;
    new_cell->fn2 = NULL;
    new_cell->children = NULL;
    new_cell->child_count = 0;
    new_cell->next_in_reactor = reactor->head;
    reactor->head = new_cell;

    new_cell->callbacks = NULL;

    new_cell->old_value_before_update = 0;

    new_cell->reactor = reactor;
    return new_cell;
}

struct cell *create_compute1_cell(struct reactor *reactor,
                                  struct cell *cell,
                                  compute1 function)
{
    struct cell *new_cell = malloc(sizeof(struct cell));
    if (new_cell == NULL)
        return NULL;
    new_cell->type = COMPUTE1;
    new_cell->dep1 = cell;
    new_cell->dep2 = NULL;
    new_cell->fn1 = function;
    new_cell->fn2 = NULL;
    new_cell->value = function(cell->value);

    new_cell->children = NULL;
    new_cell->child_count = 0;

    cell->children = realloc(cell->children,sizeof(struct cell *) * (cell->child_count + 1 ));


    cell->children[cell->child_count] = new_cell;
    cell->child_count++;

    new_cell->next_in_reactor = reactor->head;
    reactor->head = new_cell;

    new_cell->callbacks = NULL;
    new_cell->old_value_before_update= 0;
    new_cell->reactor = reactor;
    
    return new_cell;
    
}


struct cell *create_compute2_cell(struct reactor *reactor,
                                  struct cell *cell1,
                                  struct cell *cell2,
                                  compute2 function)
{
    struct cell *new_cell = malloc(sizeof(struct cell));
    if (new_cell == NULL)
        return NULL;
    new_cell->type = COMPUTE2;
    new_cell->dep1 = cell1;
    new_cell->dep2 = cell2;
    new_cell->fn1 = NULL;
    new_cell->fn2 = function;
    new_cell->value = function(cell1->value,cell2->value);

    new_cell->children = NULL;
    new_cell->child_count = 0;

    cell1->children = realloc(
    cell1->children,
    sizeof(struct cell *) * (cell1->child_count + 1));

cell1->children[cell1->child_count] = new_cell;
cell1->child_count++;

    cell2->children = realloc(
    cell2->children,
    sizeof(struct cell *) * (cell2->child_count + 1));

cell2->children[cell2->child_count] = new_cell;
cell2->child_count++;

    new_cell->next_in_reactor = reactor->head;
    reactor->head = new_cell;


    new_cell->callbacks = NULL;
    new_cell->old_value_before_update = 0;
    new_cell->reactor = reactor;
    
    return new_cell;
}

int get_cell_value(struct cell *cell)
{
 return cell->value;   
}


void set_cell_value(struct cell *cell,
                    int new_value)
{
    if (cell->value == new_value)
        return;

    struct cell *cur = cell->reactor->head;

    /* Save all old stable values */
    while (cur != NULL)
    {
        cur->old_value_before_update = cur->value;
        cur = cur->next_in_reactor;
    }

    cell->value = new_value;

    update_children(cell);

    /* Fire callbacks only if final value differs
       from original stable value */
    cur = cell->reactor->head;

    while (cur != NULL)
    {
        if (cur->callbacks != NULL &&
            cur->value != cur->old_value_before_update)
        {
            struct callback_node *cb = cur->callbacks;

            while (cb != NULL)
            {
                cb->fn(cb->data, cur->value);
                cb = cb->next;
            }
        }

        cur = cur->    next_in_reactor;
    }
}

callback_id add_callback(struct cell *cell,
                         void *data,
                         callback function)
{
    struct callback_node *new_callback = malloc(sizeof(struct callback_node));
    if (new_callback == NULL)
        return -1;
    new_callback->id = next_callback_id++;
    new_callback->data = data;
    new_callback->fn = function;

    new_callback->next = cell->callbacks;
    cell->callbacks = new_callback;

    return new_callback->id;
    
}


void remove_callback(struct cell *cell,
                     callback_id id)
{
    struct callback_node *current = cell->callbacks;
    struct callback_node *prev = NULL;

    while(current != NULL)
    {
        if (current->id == id)
        {
            if (prev == NULL)
            {
                cell->callbacks = current->next;
            }
            else{
                prev->next = current->next;
            }
            free(current);
            return;
        }
    prev = current;
    current = current->next;
    }
}

static void update_children(struct cell *cell)
{
    for (int i = 0; i < cell->child_count; i++)
    {
        struct cell *child = cell->children[i];

        int old_value = child->value;
        int new_value;

        if (child->type == COMPUTE1)
        {
                new_value = child->fn1(child->dep1->value);
        }
        if (child->type == COMPUTE2)
        {
            new_value = child->fn2(child->dep1->value,child->dep2->value);
        }


        if (old_value != new_value)
{
    child->value = new_value;

    update_children(child);
}
    }
}