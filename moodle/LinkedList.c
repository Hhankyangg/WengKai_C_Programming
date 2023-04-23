#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

int main() {
    List list;
    list.head = '\0';
    list.tail = '\0';

    // input nums
    int number;
    scanf("%d", &number);
    while (number != -1) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->value = number;
        p->next = '\0';
        if (list.head == '\0') {
            list.head = p;
            list.tail = p;
        }
        else {
            list.tail->next = p;
            list.tail = list.tail->next;
        }
        scanf("%d", &number);
    }

    // print
    Node* i;
    for (i=list.head; i; i=i->next) {
        printf("%d ", i->value);
    }

    // free
    Node* j;
    for (i=list.head; i; i=j) {
        j = i->next;
        free(i);
    }

    return 0;
}