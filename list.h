// C code for a singly linked list.
//
// Modified by <your-name-here>
//

#ifndef LAB02_LIST_H
#define LAB02_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // this is only needed for the error handling
#include <stddef.h>
#include <errno.h>

#include "stack.h"

// Struct for a singly linked list
// This should not be modified unless you
// are creating a doubly-linked list.
struct list_node {
    struct list_node *next;
    struct stack_node *stack;
    char item;
};

/** Add your prototypes for the list functions here. **/
/** To get started, take a look as the stack header. **/

struct list_node *generate_list_node(char item);
struct list_node *insert(struct list_node *list, char item);
struct list_node *delete_last(struct list_node *list);
void display_list(struct list_node *list);
char peekList(struct list_node *list);
struct list_node *listPop(struct list_node *stack);


#endif //LAB02_LIST_H
