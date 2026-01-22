////C
//#include <stdio.h>
//#include <stdlib.h>
//int cnt = 0;
//typedef struct {
//	int* data;
//	int top;
//}Stack;
//void initstack(Stack* s)
//{
//	s->data = (int*)malloc(sizeof(int) * 100);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//}
//void push(Stack* s, int num)
//{
//	s->top++;
//	s->data[s->top] = num;
//}
//void pop(Stack* s)
//{
//	int e = s->data[s->top];
//	s->top--;
//	if (cnt == 3)
//	{
//		printf("%d\n", e);
//		cnt = 0;
//	}
//	else
//	{
//		printf("%d ", e);
//		cnt++;
//	}
//}
//int isempty(Stack* s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//void f(int n,int index, Stack* s,int a[],int output[])
//{
//	if (index == n)
//	{
//		for (int i = 0; i < n; i++)
//			printf("%d ", output[i]);
//		printf("\n");
//	}
//	if (index < n)
//	{
//
//	}
//}
//int main()
//{
//	Stack s;
//	initstack(&s);
//	int n;
//	scanf("%d", &n);
//	int* a = (int*)malloc(sizeof(int) * n);
//	int* output = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//
//	return 0;
//}


//D
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct {
//	int weight;
//	int value;
//	float ratio;
//}ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//}Stack;
//void initstack(Stack* s)
//{
//	s->data = (ElementType*)malloc(sizeof(ElementType) * 100);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//}
//void push(Stack* s, ElementType e)
//{
//	s->top++;
//	s->data[s->top] = e;
//}
//void pop(Stack* s,ElementType *e)
//{
//	*e = s->data[s->top];
//	s->top--;
//}
//int isempty(Stack* s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//int compare(const void* a, const void* b)
//{
//	ElementType* a1 = (ElementType*)a;
//	ElementType* b1 = (ElementType*)b;
//	if (b1->ratio > a1->ratio)
//		return 1;
//	else if (b1->ratio < a1->ratio)
//		return -1;
//	else
//		return 0;
//}
//int main()
//{
//	Stack s;
//	initstack(&s);
//	int n, maxwei, maxvalue = 0, currentwei = 0;
//	scanf("%d%d", &n, &maxwei);
//	ElementType* array = (ElementType*)malloc(sizeof(ElementType)*n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d", &array[i].weight, &array[i].value);
//		array[i].ratio = (float)array[i].value / array[i].weight;
//	}
//	qsort(array, n,sizeof(ElementType), compare);
//	for (int i=0;i<n;i++)
//	{
//		if (currentwei < maxwei)
//		{
//			push(&s, array[i]);
//			currentwei += array[i].weight;
//			maxvalue += array[i].value;
//			if (currentwei > maxwei)
//			{
//				ElementType e;
//				pop(&s,&e);
//				currentwei -= e.weight;
//				maxvalue -= e.value;
//			}
//		}
//	}
//	printf("%d", maxvalue);
//	return 0;
//}


//E
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//}Stack;
//void initstack(Stack* s)
//{
//	s->data = (ElementType*)malloc(sizeof(ElementType) * 100);
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//}
//void push(Stack* s, ElementType e)
//{
//	s->top++;
//	s->data[s->top] = e;
//}
//void pop(Stack* s,ElementType *e)
//{
//	*e = s->data[s->top];
//	s->top--;
//}
//int isempty(Stack* s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//void f(int k, int a[], Stack* s, int index, int size, int output[], int out_size);
//void revise(int k, int a[], Stack* s, int index, int size, int output[], int out_size);
//void f(int k, int a[], Stack* s,int i,int size,int output[],int out_size)
//{
//	for (int i=0;i<size;i++)
//	{
//		push(s, a[i]);
//		output[out_size++] = a[i];
//		revise(k, a, s, i , size, output, out_size);
//	}
//}
//void revise(int k, int a[], Stack* s, int i, int size, int output[], int out_size)
//{
//	if (s->top + 1 == k)
//	{
//		for (int i = 0; i < out_size; i++)
//			printf("%d ", output[i]);
//		printf("\n");
//	}
//	else if (s->top + 1 < k && i < size)
//	{
//		ElementType e;
//		f(k, a, s, i + 1, size, output, out_size);
//		pop(s, &e);
//	}
//}
//int main()
//{
//	Stack s;
//	initstack(&s);
//	int k;
//	scanf("k=%d", &k);
//	int a[1000] = { 0 };
//	int output[1000] = { 0 };
//	int size = 0,out_size=0;
//	while (scanf("%d", &a[size]) != EOF)
//		size++;
//	f(k, a, &s, 0,size,output,out_size);
//	return 0;
//}


//ÉÏ»úC 2033
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAXSIZE 100
//typedef char ElementType;
//typedef struct {
//	ElementType data[MAXSIZE];
//	int top;
//}Stack;
//void init(Stack* s)
//{
//	s->top = -1;
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
//int isempty(Stack* s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//void clear(Stack* s)
//{
//	s->top = -1;
//}
//ElementType getbottom(Stack* s)
//{
//	return s->data[0];
//}
//char calculate(Stack* s)
//{
//	while (s->top!=1)
//	{
//		ElementType e;
//		int num1, num2;
//		pop(s, &e);
//		num2 = e - '0';
//		pop(s, &e);
//		num1 = e - '0';
//		int res = 0;
//		char operater = s->data[0];
//		switch (operater)
//		{
//		case '+':push(s, '0' + num1 + num2); break;
//		case '-':push(s, '0' + num1 - num2); break;
//		case '*':push(s, '0'+ num1 * num2); break;
//		case '/':push(s, '0' + num1 / num2); break;
//		case '%':push(s, '0' + num1 % num2); break;
//		}
//	}
//	return s->data[1];
//}
//int main()
//{
//	char lispEper[100] = { 0 };
//	char final[100] = { 0 };
//	Stack s;
//	init(&s);
//	gets_s(lispEper);
//	int len = strlen(lispEper);
//	char ch;
//	int is_zk=0,k=0;
//	for (int i = 0; i < len; i++)
//	{
//		ch = lispEper[i];
//		if (ch == '('&& is_zk==0)
//		{
//			is_zk = 1;
//		}
//		else if (ch!='('&&ch!=' '&& ch!=')' && is_zk == 1)
//			final[k++] = ch;
//		else if (ch == '(' && is_zk == 1)
//		{
//			i++;
//			ch = lispEper[i];
//			while (ch != ')')
//			{
//				if (ch!=' ')
//				  push(&s, ch);
//				i++;
//				ch = lispEper[i];
//			}
//            char num=calculate(&s);
//			final[k++] = num;
//			clear(&s);
//		}
//	}
//	for (int i = 0; i < k; i++)
//		push(&s, final[i]);
//	int res=calculate(&s)-'0';
//	printf("%d", res);
//	return 0;
//}