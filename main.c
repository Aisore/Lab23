#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "bintree.h"
#include "bintree.c"

int main(void)
{
    char cli_input[8];
    int input;
    int quan = 0;
    Tree *baum = NULL;
    
    printf("To get help type 'help'\n");    
    
    for (;;) {
        scanf("%7s", cli_input);
        
        if (!strcmp(cli_input, "help")) {
            printf("'insert' or 'ins' - insert new nodes.\n");
            printf("'delete' or 'del' - delete the vertice and all nested vertices.\n");
            printf("'print' or 'p' - print the tree.\n");
            printf("'quit', 'q' or 'exit' - close the program.\n");
            printf("'top' - print number of vertices of a tree.\n");
        } else if (!strcmp(cli_input, "delete") || !strcmp(cli_input, "del")) {
            while (scanf("%d", &input))
                baum = delete_node(baum, input);
        } else if (!strcmp(cli_input, "quit") || !strcmp(cli_input, "exit") || !strcmp(cli_input, "q")) {
            demolish(baum);
            return 0;
        } else if (!strcmp(cli_input, "print") || !strcmp(cli_input, "p")) {
            printf("\n");
            if (!baum)
                printf("There are no vertices in the tree.\n");
            print_tree(baum, 0);
            printf("\n");
        } else if (!strcmp(cli_input, "insert") || !strcmp(cli_input, "ins")) {
            while (scanf("%d", &input))
                insert_tree(&baum, input);
        } else if (!strcmp(cli_input, "top")) { 
            quan = NodeCount(baum);
            printf("%d", quan);
        } else {
            printf("The command is not recognised. Type 'help'.\n\n");
        }
    }
    
    return 1;
}
