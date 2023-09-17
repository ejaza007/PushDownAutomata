// List source code file.
//
// Modified by Armaghan Ejaz
//

#include "list.h" // no additional includes needed here

/** Add code for implementing you list functionality. **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Define the structure for a singly linked list node.

// Create and initialize a new list node.
struct list_node *generate_list_node(char item) {
    struct list_node *node = malloc(sizeof(struct list_node));

    // Error checking
    if (node == NULL) {
        printf("ERROR: %s\n", __FUNCTION__);
        printf("     : %s\n", strerror(errno));
        exit(-1);
    }

    node->next = NULL;
    node->item = item;

    return node;
}

// Add a new node to the end of the linked list.
struct list_node *insert(struct list_node *list, char item) {
    struct list_node *element = generate_list_node(item);

    // If the list is empty, the new element becomes the list itself.
    if (list == NULL) {
        return element;
    }

    // Traverse to the end of the list and insert the new element.
    struct list_node *current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = element;
    return list;
}

// Remove the last node from the linked list.
struct list_node *delete_last(struct list_node *list) {
    if (list == NULL) {
        return NULL; // Nothing to delete from an empty list.
    }

    if (list->next == NULL) {
        // If there is only one element in the list, free it and return NULL.
        free(list);
        return NULL;
    }

    // Traverse the list to find the second-to-last node.
    struct list_node *current = list;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the last node and set the next pointer of the second-to-last node to NULL.
    free(current->next);
    current->next = NULL;

    return list;
}

char peekList(struct list_node *list){

    // If not null, return item otherwise null value.
    if(list)
        return list->item;
    else
        return '\0';
}



struct list_node *listPop(struct list_node *list) {

    struct list_node *next = list->next;

    // Always free memory that is no longer needed.
    free(list);

    return next;
}


void display_list(struct list_node *list) {
    struct list_node *node = list;

    printf("List: ");
    while (node != NULL) {
        putchar(node->item);
        node = node->next;
    }
    puts("");
}

