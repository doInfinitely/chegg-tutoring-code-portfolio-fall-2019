#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void printlist(struct mynode *start) {
    struct mynode *current = start;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
        if (current != NULL) {
            printf("<==>");
        }
    }
    printf("\n");
}

struct mynode *insertionsort(struct mynode* start1) {
    struct mynode *node = start1;
    struct mynode *start2 = NULL;
    struct mynode *current;
    struct mynode *temp;
    while (node != NULL) {
        temp = node->next;
        if (temp != NULL) {
            temp->prev = NULL;
        }
        node->next = NULL;

        if (start2 == NULL) {
            start2 = node;
        } else {
            if (start2->value > node->value) {
                node->next = start2;
                start2->prev = node;
                start2 = node;
            } else {
                current = start2;
                while (current->value <= node->value) {
                    if (current->next == NULL) {
                        current->next = node;
                        node->prev = current;
                        break;
                    }
                    current = current->next;
                }
                if (current->value > node->value) {
                    node->next = current;
                    current->prev->next = node;
                    current->prev = node;
                }
            }
        }
        node = temp;
    }
    return start2;
}
