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
