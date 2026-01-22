#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}NODE,*List;
void InitList(List* l)
{
	NODE* p;
	p = (NODE*)malloc(sizeof(NODE));
	if (!p)  exit(-1);
	p->next = NULL;
	*l = p;
}
 