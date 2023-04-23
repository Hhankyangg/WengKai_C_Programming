#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    // 读数, 读到 -1 停止
    int number = 0;
    List list;
    list.head = '\0';
    do {
        scanf("%d", &number);
        if (number != -1) {
            node_add(&list, number);
        }
    } while (number != -1);

    // print
    print(&list);

    // remove
    int remove_num = 233;
    node_remove(&list, remove_num);
    print(&list);

    // eliminate
    node_eliminate(&list);

    return 0;
}