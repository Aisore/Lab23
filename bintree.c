#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

void insert_tree(Tree **l, int x)
{
    Tree *tmp;
    
    if (*l == NULL) {
        tmp = (Tree *) malloc(sizeof(Tree));
        tmp->item = x;
        tmp->left = tmp->right = NULL;
        *l = tmp;
        return;
    }
    
    if (x < (*l)->item) {
        insert_tree(&((*l)->left), x);
    } else if (x == (*l)->item) {
        return;
    } else {
        insert_tree(&((*l)->right), x);
    }
}

Tree *minimum(Tree *l)
{
    if (l->left == NULL) return l;
    return minimum(l->left);
}

Tree *delete_node(Tree *l, int key)
{
    if (l == NULL) return l;
    
    if (key < l->item)
        l->left = delete_node(l->left, key);
    else if (key > l->item)
        l->right = delete_node(l->right, key);
    else {
        if (l->left == NULL) {
            Tree *tmp = l->right;
            free(l);
            return tmp;           
        }
        else if (l->right == NULL) {
            Tree *tmp = l->left;
            free(l);
            return tmp;
        }
        
        Tree *tmp = minimum(l->right);
        l->item = tmp->item;
        l->right = delete_node(l->right, tmp->item);
    }
    
    return l;
}

Tree *search_tree(Tree *l, int x)
{
    if (l == NULL)
        return (NULL);
    if (x == l->item)
        return (l);
    if (x < l->item)
        return (search_tree(l->left, x));
    else
        return (search_tree(l->right, x));
}

void print_tree(Tree *l, int depth)
{
    if (l != NULL) {
        print_tree(l->left, depth + 1);
        for(int i = 0; i < depth; ++i) printf("---");
        printf("|%d\n", l->item);
        print_tree(l->right, depth + 1);
    }
}

void demolish(Tree *l)
{
    if (l == NULL) return; 
    demolish(l->left);
    demolish(l->right);
    
    free(l);
}
