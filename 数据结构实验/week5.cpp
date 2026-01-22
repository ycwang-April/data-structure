//上机A
//#include <stdio.h>
//#include <stdlib.h>
//int compare(const void* a, const void* b)
//{
//	int* pa = (int*)a;
//	int* pb = (int*)b;
//	return *pa - *pb;
//}
//int main()
//{
//	int n, k;
//	scanf("%d%d", &n, &k);
//	int a[1000] = { 0 };
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	qsort(a, n, sizeof(int), compare);
//	int i;
//	for (i = 0; i < k - 1; i++)
//		printf("%d ", a[i]);
//	printf("%d", a[i]);
//	return 0;
//}

//**B 1858
//#include <stdio.h>
//int main()
//{
//	int a[100] = { 0 },k=0,num,isFound=0;
//	char c;
//	while (scanf("%d", &a[k++]) ==1 && (c=getchar())!='\n');   //**可以学习
//	scanf("%d", &num);
//	for (int i = 0; i < k; i++)
//	{
//		for (int j = i; j < k; j++)
//		{
//			if (a[i] + a[j] == num)
//			{
//				printf("%d %d", a[i], a[j]);
//				isFound = 1;
//				break;
//			}
//		}
//		if (isFound == 1)
//			break;
//	}
//	return 0;
//}

////A
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct node {
//	ElementType data;
//	struct node* next;
//}Node,*List;
//void init(List* l)
//{
//	Node* t;
//	t = (Node*)malloc(sizeof(Node));
//	if (!t)
//		exit(-1);
//	*l = t;
//	t->next = NULL;
//}
//void insertlist(List l, int a[],int n)
//{
//	Node* p, * q=l;
//	for (int i = 0; i < n; i++)
//	{
//		p = (Node*)malloc(sizeof(Node));
//		if (!p)
//			exit(-1);
//		p->data = a[i];
//		q->next = p;
//		q = p;
//	}
//	q->next = NULL;
//}
//void deleteths(List l)
//{
//	Node* p =l->next , * q = l;
//	for (; p->next; q = q->next, p = q->next)
//	{
//		if (p->data == p->next->data)
//		{
//			q->next = p->next;
//			free(p);
//		}
//	}
//}
//void coutlist(List l)
//{
//	Node* p;
//	for (p = l->next; p->next; p = p->next)
//		printf("%d ", p->data);
//	printf("%d", p->data);
//}
//int compare(const void* a, const void* b)
//{
//	int* pa = (int*)a;
//	int* pb = (int*)b;
//	return *pa - *pb;
//}
//int main()
//{
//	int a[1000] = { 0 };
//	int a_size = 0;
//	while (scanf("%d", &a[a_size++]) != EOF)
//		;
//	a_size--;
//	qsort(a, a_size, sizeof(int), compare);
//	List l;
//	init(&l);
//	insertlist(l, a, a_size);
//	deleteths(l);
//	coutlist(l);
//}

//**B 1859
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//void initstack(Stack* s, int maxsize)
//{
//	s->data = (ElementType*)malloc(sizeof(ElementType) * maxsize);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//	s->maxsize = maxsize;
//}
//int isempty(Stack* s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
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
//char gettop(Stack* s)
//{
//	return s->data[s->top];
//}
//void clearstack(Stack* s)
//{
//	s->top = -1;
//}
//int main()
//{
//	char sentence[1000] = { 0 };
//	while (gets_s(sentence) != NULL)
//	{
//		Stack s;
//		initstack(&s, 1000);
//		char ch;
//		ElementType e;
//		int len = strlen(sentence);
//		int index[100] = { 0 }, k = 1;
//		index[0] = 0;
//		for (int i = 1; i < len - 1; i++)
//		{
//			if (sentence[i] == ' ')
//				index[k++] = i;
//		}
//		index[k] = len - 1;
//		int chcnt[100] = { 0 }, count = k - 1;
//		for (int i = 0; i + 1 <= k; i++)
//		{
//			int start = index[i] + 1, end = index[i + 1] - 1;
//			for (int j = end; j >= start; j--)
//			{
//				push(&s, sentence[j]);
//				chcnt[count]++;
//			}
//			count--;
//		}
//		printf("\"");
//		int cnt = 0, cot = 0;
//		while (!isempty(&s))
//		{
//			pop(&s, &e);
//			printf("%c", e);
//			cnt++;
//			if (cnt == chcnt[cot] && !isempty(&s))
//			{
//				printf(" ");
//				cnt = 0;
//				cot++;
//			}
//		}
//		printf("\"\n");
//	}
//	return 0;
//}

//"You are unbreakable."


//C
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100];
//	gets_s(s);
//	int count[128] = { 0 };
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//		count[s[i]]++;
//	for (int i = 0; i < len; i++)
//	{
//		if (count[s[i]] == 1)
//		{
//			printf("%c", s[i]);
//			break;
//		}
//	}
//	return 0;
//}

//D
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	while (gets_s(s) != NULL)
//	{
//		int len = strlen(s);
//		if (len % 2 == 0)
//		{
//			for (int i = len / 2 - 1; i >= 0; i--)
//				printf("%c", s[i]);
//			for (int i = len - 1 ; i >= len/2; i--)
//				printf("%c", s[i]);
//		}
//		else
//		{
//			for (int i = len / 2 - 1; i >= 0; i--)
//				printf("%c", s[i]);
//			printf("%c", s[len / 2]);
//			for (int i = len - 1; i > len/2; i--)
//				printf("%c", s[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[1000] = { 0 };
//	char str[500] = { 0 };
//	gets_s(s);
//	gets_s(str);
//	int cnt = 0;
//	int len1 = strlen(s), len2 = strlen(str);
//	for (int i = 0; i + len2 <= len1; i++)
//	{
//		int k = 0;
//		char temp[500] = { 0 };
//		for (int j = i; j - i < len2; j++)
//		{
//			temp[k++] = s[j];
//		}
//		if (strcmp(temp, str) == 0)
//			cnt++;
//	}
//	printf("%d", cnt);
//	return 0;
//}

//112121