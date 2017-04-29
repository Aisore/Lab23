#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

void paste_node(Tree ** tr, int x)
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
    } else {
        paste_node(&((*tr)->rchild), x);
    }
}

Tree * minimum(Tree *tr)
{
    if (tr->lchild == NULL) return tr;
    return minimum(tr->lchild);
}

Tree* delete_node(Tree* tr, int num)
{ 
    if (tr == NULL) return tr;

    if (num < tr->item)
        tr->lchild = delete_node(tr->lchild, num);
    else if (num > tr->item)
        tr->rchild = delete_node(tr->rchild, num);
    else {
        if (tr->lchild == NULL) {
            Tree *tree_bin = tr->rchild;
            free(tr);
            return tree_bin;
        }
        else if (tr->rchild == NULL) {
            Tree *tree_bin = tr->lchild;
            free(tr);
            return tree_bin;
        }
        
        Tree *tree_bin = minimum(tr->rchild);
        tr->item = tree_bin->item;
        tr->rchild = delete_node(tr->rchild, tree_bin->item);
    }
    
    return tr;
}

void print_tree(Tree *tr, int depth)
{
    if (tr != NULL) {
        print_tree(tr->lchild, depth + 1);
        for(int i = 0; i < depth; ++i) printf("   ");
        printf("%d<\n", tr->item);
        print_tree(tr->rchild, depth + 1);
    }
}

int check_node(Tree **tr, int x) {
    if ((*tr) == NULL) {
        return 1;
    }
    
    if (x < (*tr)->item) {
        check_node(&((*tr)->lchild), x);
    } else if (x == (*tr)->item) {
        return -1;
    } else {
        check_node(&((*tr)->rchild), x);
    }
}