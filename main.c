#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bintree.c"
#include "bintree.h"

#define size 7 

int main(void)
{
    int num, quan = 0;
    int ch = 0;
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
                ch = check_node(&tree_bin, num);
                paste_node(&tree_bin, num);
                if (ch == 1) {quan++;}
            }
        } else if (!strcmp(input, "Delete")) {
            if (!tree_bin) {
                printf("There are not nodes in tree\n");
            } else {
                while(scanf("%d", &num)) {
                    delete_node(tree_bin, num);
                }
            }
        } else if (!strcmp(input, "Print")) {
            print_tree(tree_bin, 0);
        } else if (!strcmp(input, "Top")) {
            if (!tree_bin) {
                printf("There are not nodes in tree\n");
            } else {
                printf("%d\n", quan);
            }    
        } else if (!strcmp(input, "Exit")) {
            return 0;
        } else {
            fprintf(stderr, "Invalid command input\n");
            fprintf(stdout, "Print 'Help' for information\n");
            exit(0);
        }
    }
    return 1;
}
