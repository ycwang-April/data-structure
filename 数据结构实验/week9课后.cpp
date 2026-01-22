//A
//#include <stdio.h>
//#include <stdlib.h>
//typedef char ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//	int ltag, rtag;
//}BiNODE,*BiTree;
//BiNODE* pre;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;
//}
//void CreateBiTree(BiTree* t,char** str)
//{
//	char ch;
//	ch = **str;
//	(*str)++;
//	if (ch == '#')
//		*t = NULL;
//	else if (ch != ' '| ch != '\n')
//	{
//		(*t) = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!t)
//			exit(-1);
//		(*t)->data = ch;
//		(*t)->ltag = (*t)->rtag = 0; //
//		CreateBiTree(&(*t)->lchild,str);
//		CreateBiTree(&(*t)->rchild,str);
//	}
//}
//void InThreading(BiNODE* p)
//{
//	if (p)
//	{
//		InThreading(p->lchild);
//		if (!p->lchild)
//		{
//			p->ltag = 1;
//			p->lchild = pre;
//		}
//		if (!pre->rchild)
//		{
//			pre->rtag = 1;
//			pre->rchild = p;
//		}
//		pre = p;
//		InThreading(p->rchild);
//	}
//}
//BiNODE* InOrderThreading(BiTree t)
//{
//	BiNODE* head;
//	head = (BiNODE*)malloc(sizeof(BiNODE));
//	if (!head)
//		exit(-1);
//	head->ltag = 0;
//	head->rtag = 1;
//	head->rchild = head;
//	if (!t)
//		head->lchild = head;
//	else
//	{
//		head->lchild = t;
//		pre = head;
//		InThreading(t);
//		pre->rtag = 1;
//		pre->rchild = head;
//		head->rchild = pre;
//	}
//	return head;
//}
//void InOrderThrTraverse(BiNODE* head)
//{
//	BiNODE* p;
//	p = head->lchild;
//	while (p != head)
//	{
//		while (p->ltag == 0)
//			p = p->lchild;
//		putchar(p->data);
//		while (p->rtag == 1 && p->rchild != head)
//		{
//			p = p->rchild;
//			putchar(p->data);
//		}
//		p = p->rchild;
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d%*c", &t);
//	while (t--)
//	{
//		char s[100] = { 0 };
//		gets_s(s);
//		char* str = s;
//		BiNODE* head;
//		BiTree t;
//		initBiTree(&t);
//		CreateBiTree(&t,&str);
//		head = InOrderThreading(t);
//		InOrderThrTraverse(head);
//		printf("\n");
//	}
//	return 0;
//}


////B
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
//void InOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		InOrderTraverse(t->lchild);
//		PrintElement(t->data);
//		InOrderTraverse(t->rchild);
//	}
//}
//int BiTreeDepth(BiTree t)
//{
//	if (!t)
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
//		InOrderTraverse(t);
//		printf("\n");
//	}
//}

//C
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//	int Preindex;
//	int tag;
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
//void PrintElement(ElementType e)
//{
//	putchar(e);
//}
//void PreOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		PrintElement(t->data);
//		PreOrderTraverse(t->lchild);
//		PreOrderTraverse(t->rchild);
//	}
//}
//void PostOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		PostOrderTraverse(t->lchild);
//		PostOrderTraverse(t->rchild);
//		PrintElement(t->data);
//	}
//}
//int findalpha(ElementType e, char ins[],int start, int end)
//{
//	int len = strlen(ins);
//	for (int i = start; i < end; i++)
//	{
//		if (ins[i] == e)
//			return i;
//	}
//	return -1;
//}
//void levs_insCreateBiTree(char levs[],char ins[], int n, BiTree* t, Queue* q)
//{
//	QElementType e;
//	int ind = 0;
//	(*t) = (BiNODE*)malloc(sizeof(BiNODE));
//	(*t)->data = levs[ind++];
//	(*t)->lchild = (*t)->rchild = NULL;
//	EnQueue(q, *t);
//	while (!isemptyQ(q) && ind < n )
//	{
//		QElementType e;
//		DeQueue(q, &e);
//		int d = findalpha(e->data, ins, 0, n);
//
//		if (ind == 1)
//		{
//			//左子树
//			if (findalpha(levs[ind], ins, 0, d) != -1)
//			{
//				e->lchild = (BiNODE*)malloc(sizeof(BiNODE));
//				e->lchild->data = levs[ind];
//				e->lchild->lchild = e->lchild->rchild = NULL;
//				e->lchild->tag = 0;
//				e->lchild->Preindex = d;
//				ind++;
//			}
//			//右子树
//			if (findalpha(levs[ind], ins, d + 1, n) != -1)
//			{
//				e->rchild = (BiNODE*)malloc(sizeof(BiNODE));
//				e->rchild->data = levs[ind];
//				e->rchild->lchild = e->rchild->rchild = NULL;
//				e->rchild->tag = 1;
//				e->rchild->Preindex = d;
//				ind++;
//			}
//			if (e->lchild)
//				EnQueue(q, e->lchild);
//			if (e->rchild)
//				EnQueue(q, e->rchild);
//		} 
//
//		else
//		{
//			if (e->tag == 0)
//			{
//				//左子树
//				if (findalpha(levs[ind], ins, 0, d) != -1)
//				{
//					e->lchild = (BiNODE*)malloc(sizeof(BiNODE));
//					e->lchild->data = levs[ind];
//					e->lchild->lchild = e->lchild->rchild = NULL;
//					e->lchild->tag = 0;
//					e->lchild->Preindex = d;
//					ind++;
//				}
//				//右子树
//				if (findalpha(levs[ind], ins, d + 1, e->Preindex) != -1)
//				{
//					e->rchild = (BiNODE*)malloc(sizeof(BiNODE));
//					e->rchild->data = levs[ind];
//					e->rchild->lchild = e->rchild->rchild = NULL;
//					e->rchild->tag = 1;
//					e->rchild->Preindex = d;
//					ind++;
//				}
//				if (e->lchild)
//				    EnQueue(q, e->lchild);
//				if (e->rchild)
//				    EnQueue(q, e->rchild);
//			}
//
//			else if (e->tag == 1)
//			{
//				//左子树
//				if (findalpha(levs[ind], ins, e->Preindex ,d) != -1)
//				{
//					e->lchild = (BiNODE*)malloc(sizeof(BiNODE));
//					e->lchild->data = levs[ind];
//					e->lchild->lchild = e->lchild->rchild = NULL;
//					e->lchild->tag = 0;
//					e->lchild->Preindex = d;
//					ind++;
//				}
//				//右子树
//				if (findalpha(levs[ind], ins, d + 1, n) != -1)
//				{
//					e->rchild = (BiNODE*)malloc(sizeof(BiNODE));
//					e->rchild->data = levs[ind];
//					e->rchild->lchild = e->rchild->rchild = NULL;
//					e->rchild->tag = 1;
//					e->rchild->Preindex = d;
//					ind++;
//				}
//				if (e->lchild)
//					EnQueue(q, e->lchild);
//				if (e->rchild)
//					EnQueue(q, e->rchild);
//			}
//
//		}
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		char ins[30] = { 0 }, levs[30] = { 0 };
//		scanf("%s%s", levs, ins);
//		BiTree t;
//		initBiTree(&t);
//		Queue q;
//		initQueue(&q, 100);
//		levs_insCreateBiTree(levs, ins, strlen(levs), &t, &q);
//		PreOrderTraverse(t);
//		printf(" ");
//		PostOrderTraverse(t);
//		printf("\n");
//	}
//	return 0;
//}

//D
//当二叉树中存在只有一个子节点的节点时，会有不同的中序遍历方案:2^n
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		char pres[100] = { 0 }, posts[100] = { 0 };
//		scanf("%s%s", pres, posts);
//		int len = strlen(posts);
//		int possibility=1;
//		for (int i=0;i<len;i++)
//			for (int j = 0; j < len ; j++)
//			{
//				if (pres[i] == posts[j])
//				{
//					if (j > 0 && pres[i + 1] == posts[j - 1])
//						possibility *= 2;
//					break;
//				}
//			}
//		printf("%d\n",possibility);
//	}
//	return 0;
//}