#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdbool.h>

typedef struct tree {
    int item;
    struct tree *lchild, *rchild;
} Tree;

void paste_node(Tree **l, int x);
Tree *delete_node(Tree *l, int key);
void print_tree(Tree *l, int depth);
void top_of_tree(Tree *tr, int quantity);

#endif