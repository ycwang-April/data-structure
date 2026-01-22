//上机
 
//A 约瑟夫环 用队列实现
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int front;
//	int rear;
//	int maxsize;
//}Queue;
//void initQueue(Queue* q,int maxsize)
//{
//	q->data = (ElementType*)malloc(sizeof(ElementType) * maxsize);
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//}
//void EnQueue(Queue* q, ElementType e)
//{
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxsize;
//}
//void DeQueue(Queue* q, ElementType* e)
//{
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//}
//int QueueLength(Queue q)
//{
//	return (q.rear - q.front + q.maxsize) % q.maxsize;
//}
//ElementType getTop(Queue q)
//{
//	return q.data[q.front];
//}
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	Queue q;
//	initQueue(&q, 100);
//	for (int i = 1; i <= n; i++)
//		EnQueue(&q, i);
//	while (QueueLength(q) != 1)
//	{
//		ElementType e;
//		int cnt = 1;
//		while (cnt != m)
//		{
//			DeQueue(&q, &e);
//			EnQueue(&q, e);
//			cnt++;
//		}
//		DeQueue(&q, &e);
//	}
//	printf("%d", getTop(q));
//}

//B
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//int cnt = 0;
//void initStack(Stack* s,int maxsize)
//{
//	s->data = (ElementType*)malloc(sizeof(ElementType) * maxsize);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//	s->maxsize = maxsize;
//}
//void push(Stack* s, ElementType e)
//{
//	s->top++;
//	s->data[s->top] = e;
//}
//void pop(Stack* s, ElementType* e)
//{
//	*e = s->data[s->top];
//	s->top--;
//}
//void solve_1(Stack* s, int n)
//{
//	int test = n;
//	int temp, judger = 0;
//	while (test)
//	{
//		temp = test % 10;
//		if (temp == 1)
//		{
//			cnt++;
//			judger = 1;
//		}
//		test /= 10;
//	}
//	if (judger==1)
//	    push(s, n);
//}
//int main()
//{
//	ElementType e;
//	int n;
//	scanf("%d", &n);
//	Stack s;
//	initStack(&s, 100);
//	for (int i = 0; i <= n; i++)
//		solve_1(&s, i);
//	printf("%d\n", cnt);
//	while (s.top != 0)
//	{
//		pop(&s, &e);
//		printf("%d ", e);
//	}
//	printf("%d", s.data[0]);
//}

//*C 1863
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//Stack s2;
//void initStack(Stack* s,int maxsize)
//{
//	s->data = (ElementType*)malloc(sizeof(ElementType) * maxsize);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//	s->maxsize = maxsize;
//}
//void push(Stack* s, ElementType e)
//{
//	s->top++;
//	s->data[s->top] = e;
//}
//void pop(Stack* s, ElementType* e)
//{
//	*e = s->data[s->top];
//	s->top--;
//}
//int isempty(Stack s)
//{
//	if (s.top == -1)
//		return 1;
//	else
//		return 0;
//}
//void clearStack(Stack* s)
//{
//	s->top = -1;
//}
//int sumStack(Stack s)
//{
//	ElementType e;
//	int sum = 0;
//	while (!isempty(s))
//	{
//		pop(&s, &e);
//		sum += e;
//	}
//	return sum;
//}
//void forw_printStack(Stack s)
//{
//	ElementType e;
//	for (int i = 0; i < s.top; i++)
//		printf("%d ", s.data[i]);
//	printf("%d\n\n", s.data[s.top]);
//}
//void findcom(Stack s1,Stack s2,int n,int num) 
//{
//	push(&s2, num);
//	ElementType e;
//	if (sumStack(s2) == n)
//		forw_printStack(s2);
//	else if (sumStack(s2) > n)
//		return;
//	else
//	{
//		while (!isempty(s1))
//		{
//			pop(&s1, &e);
//			findcom(s1, s2, n,e);
//		}
//	}
//}
//int main()
//{
//	Stack s1;
//	initStack(&s1, 100);
//	initStack(&s2, 100);
//	ElementType e;
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		push(&s1, i);
//	while (!isempty(s1))
//	{
//		pop(&s1, &e);
//		findcom(s1, s2,n,e);
//		clearStack(&s2);
//	}
//}

//D
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//int cnt = 0;
//void initStack(Stack* s,int maxsize)
//{
//	s->data = (ElementType*)malloc(sizeof(ElementType) * maxsize);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//	s->maxsize = maxsize;
//}
//void push(Stack* s, ElementType e)
//{
//	s->top++;
//	s->data[s->top] = e;
//}
//void pop(Stack* s, ElementType* e)
//{
//	*e = s->data[s->top];
//	s->top--;
//}
//int isempty_Stack(Stack s)
//{
//	if (s.top == -1)
//		return 1;
//	else
//		return 0;
//}
//typedef struct {
//	ElementType* data;
//	int front;
//	int rear;
//	int maxsize;
//}Queue;
//void initQueue(Queue* q,int maxsize)
//{
//	q->data = (ElementType*)malloc(sizeof(ElementType) * maxsize);
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//}
//void EnQueue(Queue* q, ElementType e)
//{
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % q->maxsize;
//}
//void DeQueue(Queue* q, ElementType* e)
//{
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//}
//int isempty_Queue(Queue q)
//{
//	if (q.front == q.rear)
//		return 1;
//	else
//		return 0;
//}
//int QueueLength(Queue q)
//{
//	return (q.rear - q.front + q.maxsize) % q.maxsize;
//}
//int compare(const void* a, const void* b)
//{
//	int* pa = (int*)a;
//	int* pb = (int*)b;
//	return *pa - *pb;
//}
//int main()
//{
//	Stack s;
//	initStack(&s,100);
//	Queue q;
//	initQueue(&q, 100);
//	int num,a[1000],k=0;
//	while (scanf("%d", &num) != EOF)
//		a[k++] = num;
//	qsort(a, k, sizeof(int), compare);
//	for (int i = 0; i < k; i++)
//	{
//		if (a[i] % 2 == 1)
//			push(&s, a[i]);
//		else
//			EnQueue(&q, a[i]);
//	}
//	ElementType e;
//	while (!isempty_Stack(s))
//	{
//		pop(&s, &e);
//		printf("%d ", e);
//	}
//	while (QueueLength(q) != 1)
//	{
//		DeQueue(&q, &e);
//		printf("%d ", e);
//	}
//	printf("%d", q.data[q.front]);
//}


//E
//#include <stdio.h>
//#include <string.h>
//void getNext(int next[], char t[], int len)
//{
//	int j = 0;  //j是前缀末尾
//	next[0] = 0;
//	for (int i = 1; i < len; i++)
//	{
//		while (j > 0 && t[i] != t[j])
//			j = next[j - 1];
//		if (t[i] == t[j])
//			j++;
//		next[i] = j;//求前缀表
//	}
//	for (int k = len - 1; k > 0; k--)
//		next[k] = next[k - 1] + 1;
//	next[0] = 0;//整体右移再加一
//}
//int main()
//{
//	int next[500] = { 0 };
//	char t[500] = { 0 };
//	gets_s(t);
//	int len = strlen(t);
//	getNext(next, t, len);
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len - 1)
//			printf("%d", next[i]);
//		else
//			printf("%d ", next[i]);
//	}
//}