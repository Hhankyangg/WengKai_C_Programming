#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void node_add(List* pList, int number) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = '\0';
    // find the last(before new node was created)
    Node *last = pList->head;
    if (last != '\0') {                 // not the first one
        while (last->next != '\0') {
            last = last->next;
        }
        // attach
        last->next = p;
    }
    else {                      // is the first one
        pList->head = p;
    }
}

void print(List* pList) {
    Node* p;
    for (p = pList->head; p; p = p->next) {
        printf("%d ", p->value);
    }
    printf("\n");
}

void node_remove(List* pList, int number) {
    Node* p;        // point to this one
    Node* q = '\0';        // point to the last one
    for (p=pList->head; p; p=p->next) {
        if (p->value == number) {
            if (q != '\0') {
                q->next = p->next;
            }
            else {
                pList->head = p->next;
            }
            free(p);
            break;
        }
        q = p;
    }
}

void node_eliminate(List* pList) {
    Node* p;
    Node* q;
    for (p=pList->head; p; p=q) {
        q = p->next;
        free(p);
    }
}