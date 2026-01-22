////B
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE,*BiTree;
//void initBiTree(BiTree* t)
//{
//	t = NULL;
//}
//void createBiTree(BiTree* t,char **s)
//{
//	ElementType ch;
//	ch = **s;
//	(*s)++;
//	if (ch == '#')
//		*t = NULL;
//	else
//	{
//		*t = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!t)
//			exit(-1);
//		(*t)->data = ch;
//		createBiTree(&(*t)->lchild,s);
//		createBiTree(&(*t)->rchild,s);
//	}
//}
//void PrintElement(ElementType e)
//{
//	putchar(e);
//}
//void InOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		if (t->lchild)
//			InOrderTraverse(t->lchild);
//		PrintElement(t->data);
//		if (t->rchild)
//			InOrderTraverse(t->rchild);
//	}
//}
//void PostOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		if (t->lchild)
//		  PostOrderTraverse(t->lchild);
//		if (t->rchild)
//		PostOrderTraverse(t->rchild);
//		PrintElement(t->data);
//	}
//}
//
//typedef BiNODE* QElementType;
//typedef struct {
//	QElementType* data;
//	int front;
//	int rear;
//	int maxszie;
//}Queue;
//void initQueue(Queue* q,int maxsize)
//{
//	q->data = (QElementType*)malloc(sizeof(QElementType) * maxsize);
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxszie = maxsize;
//}
//int isemptyQ(Queue *q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//void EnQueue(Queue* q, QElementType e)
//{
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxszie;
//}
//void DeQueue(Queue* q, QElementType* e)
//{
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxszie;
//}
//void LevelOrderTraverse(BiTree t,Queue *q)
//{
//	QElementType e;
//	if (!t)
//		return;
//	EnQueue(q, t);
//	while (!isemptyQ(q))
//	{
//		DeQueue(q, &e);
//		PrintElement(e->data);
//		if (e->lchild)
//			EnQueue(q,e->lchild);
//		if (e->rchild)
//		    EnQueue(q,e->rchild);
//	}
//}
//int main()
//{
//	char s[100] = { 0 };
//	while (gets_s(s)!=NULL)
//	{
//		char* str = s;
//		BiTree t;
//		initBiTree(&t);
//		Queue q;
//		initQueue(&q, 100);
//		createBiTree(&t,&str);
//		InOrderTraverse(t);
//		printf(" ");
//		PostOrderTraverse(t);
//		printf(" ");
//		LevelOrderTraverse(t, &q);
//		printf("\n");
//	}
//	return 0;
//}

//C
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE,*BiTree;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;
//}
//typedef BiNODE* QElementType;
//typedef struct {
//	QElementType* data;
//	int front;
//	int rear;
//	int maxszie;
//}Queue;
//void initQueue(Queue* q,int maxsize)
//{
//	q->data = (QElementType*)malloc(sizeof(QElementType) * maxsize);
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxszie = maxsize;
//}
//int isemptyQ(Queue *q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//void EnQueue(Queue* q, QElementType e)
//{
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxszie;
//}
//void DeQueue(Queue* q, QElementType* e)
//{
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxszie;
//}
//void createBiTree(BiTree* t,Queue *q)
//{
//	QElementType e;
//	int n;
//	scanf("%d", &n);
//	if (n == -1)
//		return;
//	else if (n == 0)
//		*t = NULL;
//	else
//	{
//		*t = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!t)
//			exit(-1);
//		(*t)->data = n;
//		(*t)->lchild = (*t)->rchild = NULL;
//	}
//	EnQueue(q, *t);
//	while (!isemptyQ(q))
//	{
//		DeQueue(q,&e);
//		scanf("%d", &n);
//		if (n == -1)
//			return;
//		else if (n == 0)
//			e->lchild = NULL;
//		else
//		{
//			e->lchild = (BiNODE*)malloc(sizeof(BiNODE));
//			if (!e->lchild)
//				exit(-1);
//			e->lchild->data = n;
//			e->lchild->lchild = e->lchild->rchild = NULL;
//		}
//		scanf("%d", &n);
//		if (n == -1)
//			return;
//		else if (n == 0)
//			e->rchild = NULL;
//		else
//		{
//			e->rchild = (BiNODE*)malloc(sizeof(BiNODE));
//			if (!e->rchild)
//				exit(-1);
//			e->rchild->data = n;
//			e->rchild->lchild = e->rchild->rchild = NULL;
//		}
//		EnQueue(q,e->lchild);
//		EnQueue(q, e->rchild);
//	}
//}
//void PrintElement(ElementType e)
//{
//	printf(" %d",e);
//}
//void PreOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		PrintElement(t->data);
//		if (t->lchild)
//			PreOrderTraverse(t->lchild);
//		if (t->rchild)
//			PreOrderTraverse(t->rchild);
//	}
//}
//int BiTreeDepth(BiTree t)
//{
//	if (t == NULL)
//		return 0;
//	int m, n;
//	m = BiTreeDepth(t->lchild);
//	n = BiTreeDepth(t->rchild);
//	if (m > n)
//		return m + 1;
//	else
//		return n + 1;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		BiTree t;
//		initBiTree(&t);
//		Queue q;
//		initQueue(&q, 100);
//		createBiTree(&t,&q);
//		printf("%d", BiTreeDepth(t));
//		PreOrderTraverse(t);
//		printf("\n");
//	}
//}


//D
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE, * BiTree;
//void initBiTree(BiTree* t)
//{
//	t = NULL;
//}
//typedef BiNODE* QElementType;
//typedef struct {
//	QElementType* data;
//	int front;
//	int rear;
//	int maxszie;
//}Queue;
//void initQueue(Queue* q, int maxsize)
//{
//	q->data = (QElementType*)malloc(sizeof(QElementType) * maxsize);
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxszie = maxsize;
//}
//int isemptyQ(Queue* q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//void EnQueue(Queue* q, QElementType e)
//{
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxszie;
//}
//void DeQueue(Queue* q, QElementType* e)
//{
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxszie;
//}
//void createBiTree(BiTree* t, Queue* q)
//{
//	QElementType e;
//	int n;
//	scanf("%d", &n);
//	if (n == -1)
//		return;
//	else if (n == 0)
//		*t = NULL;
//	else
//	{
//		*t = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!t)
//			exit(-1);
//		(*t)->data = n;
//		(*t)->lchild = (*t)->rchild = NULL;
//	}
//	EnQueue(q, *t);
//	while (!isemptyQ(q))
//	{
//		DeQueue(q, &e);
//		scanf("%d", &n);
//		if (n == -1)
//			return;
//		else if (n == 0)
//			e->lchild = NULL;
//		else
//		{
//			e->lchild = (BiNODE*)malloc(sizeof(BiNODE));
//			if (!e->lchild)
//				exit(-1);
//			e->lchild->data = n;
//			e->lchild->lchild = e->lchild->rchild = NULL;
//		}
//		scanf("%d", &n);
//		if (n == -1)
//			return;
//		else if (n == 0)
//			e->rchild = NULL;
//		else
//		{
//			e->rchild = (BiNODE*)malloc(sizeof(BiNODE));
//			if (!e->rchild)
//				exit(-1);
//			e->rchild->data = n;
//			e->rchild->lchild = e->rchild->rchild = NULL;
//		}
//		EnQueue(q, e->lchild);
//		EnQueue(q, e->rchild);
//	}
//}
//void PrintElement(ElementType e)
//{
//	printf(" %d", e);
//}
//void PostOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		if (t->lchild)
//			PostOrderTraverse(t->lchild);
//		if (t->rchild)
//			PostOrderTraverse(t->rchild);
//		PrintElement(t->data);
//	}
//}
//int BiTreeDepth(BiTree t)
//{
//	if (t == NULL)
//		return 0;
//	int m, n;
//	m = BiTreeDepth(t->lchild);
//	n = BiTreeDepth(t->rchild);
//	if (m > n)
//		return m + 1;
//	else
//		return n + 1;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		BiTree t;
//		initBiTree(&t);
//		Queue q;
//		initQueue(&q, 100);
//		createBiTree(&t, &q);
//		printf("%d", BiTreeDepth(t));
//		PostOrderTraverse(t);
//		printf("\n");
//	}
//}


//A
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE, * BiTree;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;
//}
//BiTree pres_insToposts(char pres[],int i,char ins[],int j,int n)
//{
//	if (n <= 0)
//		return NULL;
//	char d = pres[i];
//	BiNODE* t = (BiNODE*)malloc(sizeof(BiNODE));
//	t->data = d;
//	t->lchild = t->rchild = NULL;
//	int p = 0;
//	for (int a = j; a < j+n ; a++)
//	{
//		if (ins[a] == d)
//		{
//			p = a;
//			break;
//		}
//	}
//	int k = p - j;
//	t->lchild=pres_insToposts(pres, i+1, ins, j,k);
//	t->rchild=pres_insToposts(pres, i+k+1, ins, p+1 ,n-k-1);
//	return t;
//}
//void PrintElement(ElementType e)
//{
//	putchar(e);
//}
//void PostOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		if (t->lchild)
//			PostOrderTraverse(t->lchild);
//		if (t->rchild)
//			PostOrderTraverse(t->rchild);
//		PrintElement(t->data);
//	}
//}
//int main()
//{
//	char pres[50] = { 0 }, ins[50] = { 0 };
//	while (scanf("%s",pres)!=EOF && scanf("%s",ins) != EOF)
//	{
//		BiTree t;
//		initBiTree(&t);
//		t=pres_insToposts(pres, 0, ins, 0, strlen(pres));
//		PostOrderTraverse(t);
//		printf("\n");
//	}
//	return 0;
//}