#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdbool.h>

typedef struct tree {
    int item;
    struct tree *lchild, *rchild;
} Tree;

void paste_node(Tree **l, int x);
Tree *minimum(Tree *tr);
Tree *delete_node(Tree *l, int num);
void print_tree(Tree *l, int depth);
int check_node(Tree **tr, int x);

#endif