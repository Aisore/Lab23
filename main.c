#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bintree.c"
#include "bintree.h"

#define size 7 

int main(void)
{
    int num;
    char input[size];
    Tree *tree_bin = NULL;
    for (;;) {
        scanf("%7s", &input);
        if (!strcmp(input, "Help")) {
            printf("Print 'Paste' to paste node into tree\n");
            printf("Print 'Delete' to delete node from tree\n");
            printf("Print 'Print' to print tree\n");
            printf("Print 'Top' to print number of vertices of a tree \n");
            printf("Print 'Exit' to close program\n");
        } else if (!strcmp(input, "Paste")) {
            while(scanf("%d", &num)) {
                paste_node(&tree_bin, num); //tree
            }
        } else if (!strcmp(input, "Delete")) {
            if (!tree_bin) {
                printf("There are not nodes in tree\n");
            } else {
                while(scanf("%d", &num)) {
                    delete_node(tree_bin, num);  //tree
                }
            }
        } else if (!strcmp(input, "Print")) {
            print_tree(tree_bin, 0);
        } else if (!strcmp(input, "Top")) {
            if (!tree_bin) {
                printf("There are not nodes in tree\n");
            } else {
                top_of_tree(tree_bin, 0);   
            }    
        } else if (!strcmp(input, "Exit")) {
            free(tree_bin);
            return 0;
        } else {
            fprintf(stderr, "Invalid command input\n");
            fprintf(stdout, "Print 'Help' for information\n");
            exit(0);
        }
    }   
    return 1;
}
