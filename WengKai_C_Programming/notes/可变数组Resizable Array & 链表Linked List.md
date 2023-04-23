# 可变数组Resizable Array & 链表Linked List

## 可变数组Resizable Array

可变数组分块: 几个为一块, 类似 Tab

### 头文件的编写

````c
#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
    int *array;
    int size;
} Array;

const BLOCK_SIZE = 5;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

#endif
````

### `array.c`的编写

````c
#include "array.h"

//typedef struct {
//   int *array;
//    int size;
//} Array;				// 注: 结构声明在.h中已声明过, 不需要再声明

Array array_create(int init_size) {
    Array a;
    a.array = (int*)malloc(sizeof(int) * init_size);
    a.size = init_size;
    return a;			// 返回一个结构体变量 a
}

void array_free(Array *a) {
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

int array_size(Array *a) {
    return a->size;		// 封装
}

int* array_at(Array *a, int index) {
    return &(a->array[index]);	// 返回指针, 使得可被写入, 可被读
    if (index >= a->size) {
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
        // array_at 自动增长
    }
}

void array_inflate(Array *a, int more_size) {
    int *p = (int*)malloc(sizeof(int) * (a->size+more_size));
    int i;
    for (i=0; i<a->size; i++) {
        p[i] = a->array[i];
    }
    // for 循环可用 memcpy()
    // C 库<string.h>函数 
    // void *memcpy(void *str1, const void *str2, size_t n) 
    // 从存储区 str2 复制 n 个字节到存储区 str1
    // for 循环可改写为:
    // memcpy(p, a->array, sizeof(int)*a->size);
    free(a->array);
    a->array = p;
    a->size += more_size;
}
````

## 链表Linked List

![image-20230418141334007](D:\devc\noteOnMooc\C\可变数组Resizable Array & 链表Linked List.assets\image-20230418141334007-1681798421711-1.png)

### 头文件的编写

````c
#ifndef _NODE_H_
#define _NODE_H_

typedef struct _Node {		// 每个结
	int value;
	struct _Node *next;
} Node;

typedef struct _List {		// 整个struct
	Node *head;
} List;

void node_add(List *pList, int number);
void print(List* pList);
void node_remove(List* pList, int number);
void node_eliminate(List* pList);

#endif
````

###  `main`

````c
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
````

### `Node.c`的编写

````c
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
    Node* q;        // point to the last one
    for (q='\0', p=pList->head; p; q=p, p=p->next) {
        if (p->value == number) {
            if (q != '\0') {
                q->next = p->next;
            }
            else {
                pList->head = p->next;
            }
            free(p);
            break;	//一定要及时 break!!!!
        }
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
````



