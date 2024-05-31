// Serene Akhtar
// 1224434328
// list_write.cpp

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

// Function to insert a new node at the head of the list
NODE * listInsert(LIST *list, double key) {
    NODE *newNode = (NODE *) malloc(sizeof(NODE));
    if (!newNode) {
        fprintf(stderr, "Error: cannot allocate memory for new node\n");
        exit(1);
    }
    newNode->key = key;
    newNode->next = list->head;
    list->head = newNode;
    if (list->tail == NULL) {
        list->tail = newNode;
    }
    printf("Node with key %.6lf inserted\n", key);
    return newNode;
}

// Function to append a new node at the tail of the list
NODE * listAppend(LIST *list, double key) {
    NODE *newNode = (NODE *) malloc(sizeof(NODE));
    if (!newNode) {
        fprintf(stderr, "Error: cannot allocate memory for new node\n");
        exit(1);
    }
    newNode->key = key;
    newNode->next = NULL;
    if (list->tail) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
    printf("Node with key %.6lf appended\n", key);
    return newNode;
}

// Function to search for a node with the given key
NODE * listSearch(LIST *list, double key) {
    NODE *current = list->head;
    while (current) {
        if (current->key == key) {
            printf("Query %.6lf FOUND in list\n", key);
            return current;
        }
        current = current->next;
    }
    printf("Query %.6lf NOT FOUND in list\n", key);
    return NULL;
}

// Function to delete the first node with the given key
NODE * listDelete(LIST *list, double key) {
    NODE *current = list->head;
    NODE *prev = NULL;
    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current == list->tail) {
                list->tail = prev;
            }
            printf("Node with key %.6lf deleted\n", key);
            free(current);
            return list->head;
        }
        prev = current;
        current = current->next;
    }
    printf("Node with key %.6lf not found for deletion\n", key);
    return list->head;
}
