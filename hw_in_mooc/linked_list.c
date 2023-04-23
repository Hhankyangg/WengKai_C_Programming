// 逆序输出（10分）
// 题目内容：
// 你的程序会读入一系列的正整数，预先不知道正整数的数量，一旦读到-1，就表示输入结束。然后，按照和输入相反的顺序输出所读到的数字，不包括最后标识结束的-1。
// 输入格式:
// 一系列正整数，输入-1表示结束，-1不是输入的数据的一部分。
// 输出格式：
// 按照与输入相反的顺序输出所有的整数，每个整数后面跟一个空格以与后面的整数区分，最后的整数后面也有空格。
// 输入样例：
// 1 2 3 4 -1
// 输出样例：
// 4 3 2 1 

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

typedef struct {
    Node* head;
} List;

int main() {
    List list;
    list.head = '\0';

    // input nums
    int number;
    scanf("%d", &number);
    while(number != -1) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->value = number;
        p->next = list.head;
        list.head = p;
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