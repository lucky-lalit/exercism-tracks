#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>
int count = 0;
int index = 0;
node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    if (tree_data == NULL)
        return NULL;
    node_t *root = NULL;
    for (int i = 0; i < (int)tree_data_len; i++)
    {
        root = insert(root,tree_data[i]);
    }
    // for (int i = 0; i < (int)tree_data_len; i++)
    // {
        // printf("original values %i\n",tree_data[i]);
    // }
    return root;
}
void free_tree(node_t *tree)
{
    if (tree == NULL)
        return;
    free_tree(tree->right);
    free_tree(tree->left);
    free(tree);
    
}
int *sorted_data(node_t *tree)
{
    if (tree == NULL)
        return NULL;
    int *array = malloc(sizeof(int) * count);
    inorder(array,tree);
    index = 0;
    return array;
}

node_t *getnewnode(int data)
{
    node_t *newnode = malloc(sizeof(node_t));
    count++;
    if (newnode == NULL)
        return NULL;
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

node_t *insert(node_t *root,int data)
{
    if (root == NULL)
        root = getnewnode(data);
    else if (data <= root->data)
        root->left = insert(root->left,data);
    else 
        root->right = insert(root->right,data);
    return root;
}
// int index = 0;
void inorder(int *array,node_t *root)
{
    if (root == NULL)
    { 
        return;
    }
    inorder(array,root->left);
    // printf("index %i\n",index);
    array[index] = root->data;
    // printf("value %i\n",array[index]);
    index++;
    inorder(array,root->right);
    // return array;
}
