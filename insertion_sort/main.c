#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main() {
    FILE *fp;
    char filename[15];
    char ch;
    struct mynode *current = NULL;
    struct mynode *start = NULL;

    //printf("Enter the name of the input file:\n");
    printf("Enter the numbers (terminate with zero):\n");
    //scanf("%s", filename);
    /*fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
            exit(0);
    }*/
    int value = -1;
    //while (!feof(fp)) {
    while(1) {
        //fscanf(fp, "%d", &value);
	scanf("%d", &value);
        if (value == 0) {
            break;
        }
        struct mynode temp = {value, NULL, NULL};
        //struct mynode *node = malloc(sizeof(struct mynode));
        //memcpy(node, &temp, sizeof(struct mynode));
        if (start == NULL) {
            start = malloc(sizeof(struct mynode));
            memcpy(start, &temp, sizeof(struct mynode));
            current = start;
        } else {
            current->next = malloc(sizeof(struct mynode));
            current = current->next;
            memcpy(current, &temp, sizeof(struct mynode));
        }
        /*
        if (start == NULL) {
            start = node;
        } else {
            if (start->value > node->value) {
                node->next = start;
                start->prev = node;
                start = node;
            } else {
                current = start;
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
        }*/        
    }
    //fclose(fp);
    start = insertionsort(start);
    printlist(start);
}
