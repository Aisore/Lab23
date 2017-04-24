#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

void paste_node(Tree **tr, int x)
{
    Tree *tree_bin;
    
    if ((*tr) == NULL) {
        tree_bin = (Tree *) malloc(sizeof(Tree));
        tree_bin->item = x;
        tree_bin->lchild = tree_bin->rchild = NULL;
        *tr = tree_bin;
        return;
    }
    
    if (x < (*tr)->item) {
        paste_node(&((*tr)->lchild), x);
    } else if (x == (*tr)->item) {
        (*tr)->item = x;
    } else {
        paste_node(&((*tr)->rchild), x);
    }
}

void print_tree(Tree *tr, int depth)
{
    if (tr != NULL) {
        print_tree(tr->lchild, depth + 1);
        for(int i = 0; i < depth; ++i) printf("   ");
        printf("|%d<\n", tr->item);
        print_tree(tr->rchild, depth + 1);
    }
}