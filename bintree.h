#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <stdbool.h>

typedef struct tree {
	int item;
	struct tree *left;
	struct tree *right;
} Tree;

void insert_tree(Tree **l, int x);
void delete_tree(Tree *l, int key);
Tree *search_tree(Tree *l, int x);
void print_tree(Tree *l, int depth);
void demolish(Tree *l);
//bool check_node(Tree *l, int x);

#endif
