//A
//#include <stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//		int ispop[10000] = { 0 };
//		int a[10000] = { 0 };
//		for (int i = 0; i < n; i++)
//			scanf("%d", a + i);
//		int judge = 1;
//		ispop[a[0]] = 1;
//		for (int i = 1; i < n; i++)
//		{
//			if (a[i] < a[i - 1])
//			{
//				for (int j = a[i - 1]; j > a[i]; j--)
//				{
//					if (ispop[j] != 1)
//					{
//						judge = 0;
//						break;
//					}
//				}
//			}
//			ispop[a[i]] = 1;
//			if (judge == 0)
//				break;
//		}
//		if (judge == 0)
//			printf("No\n");
//		else
//			printf("Yes\n");
//	}
//	return 0;
//}

//D
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//int k = 0;
//void initStack(Stack* s, int maxsize)
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
//ElementType getTop(Stack* s)
//{
//	return s->data[s->top];
//}
//int isempty(Stack *s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//void InFixtoPostFix(char infixExpr[], char postfixExpr[], int len, Stack* s)
//{
//	char ch;
//	ElementType e;
//	int isp[128] = { 0 }, osp[128] = { 0 };
//	isp['('] = 1; isp[')'] = 7; isp['+'] = isp['-'] = 3; isp['*'] = isp['%'] = isp['/'] = 5;
//	osp['('] = 9; osp[')'] = 7; osp['+'] = osp['-'] = 3; osp['*'] = osp['%'] = osp['/'] = 5;
//	for (int i = 0; i < len; i++)
//	{
//		ch = infixExpr[i];
//		if ('0'<=ch && ch<='9')
//			postfixExpr[k++] = ch;
//		else if (ch == '(')
//			push(s, ch);
//		else if (ch == ')')
//		{
//			while (getTop(s) != '(')
//			{
//				pop(s, &e);
//				postfixExpr[k++] = e;
//			}
//			pop(s, &e);
//		}
//		else
//		{
//			while (osp[ch] <= isp[getTop(s)])
//			{
//				pop(s, &e);
//				postfixExpr[k++] = e;
//			}
//			push(s, ch);
//		}
//	}
//	while (!isempty(s))
//	{
//		pop(s, &e);
//		postfixExpr[k++] = e;
//	}
//}
//int main()
//{
//	Stack s;
//	initStack(&s, 100);
//	char infixExpr[101] = { 0 };
//	char postfixExpr[101] = { 0 };
//	gets_s(infixExpr);
//	int len = strlen(infixExpr);
//	InFixtoPostFix(infixExpr, postfixExpr, len, &s);
//	for (int i = 0; i < k - 1; i++)
//		printf("%c ", postfixExpr[i]);
//	printf("%c", postfixExpr[k - 1]);
//	return 0;
//}

//E
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	gets_s(s);
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '@')
//		{
//			for (int j = 0; j <= i; j++)
//				s[j] = 0;
//		}
//		else if (s[i] == '#')
//		{
//			s[i] = 0;
//			int j = i;
//			while (s[j] == 0)
//			{
//				j--;
//			}
//			s[j] = 0;
//		}
//	}
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] != 0)
//			printf("%c", s[i]);
//	}
//	return 0;
//}

//B
//#include <stdio.h>
//#include <stdlib.h>
//int k = 0;
//int solution[100][100] = { 0 };
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//void initStack(Stack* s, int maxsize)
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
//ElementType getTop(Stack* s)
//{
//	return s->data[s->top];
//}
//int isempty(Stack *s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//void backtrack(int n, int num,int output[], int index, Stack* s) {
//    ElementType e;
//    if (index == n) 
//    {
//        for (int i = 0; i < index; i++)
//            solution[k][i] = output[i];
//        k++;
//        return;
//    }
//
//    if (!isempty(s)) {
//        pop(s, &e);
//        output[index] = e;
//        backtrack(n, num,output,index + 1, s);
//        push(s, e);
//    }
//
//    if (num < n) {
//        push(s, num + 1);
//        backtrack(n, num + 1,output, index, s);
//        pop(s,&e);
//    }
//
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    int output[100] = { 0 };
//    Stack s;
//    initStack(&s,100);
//    backtrack(n, 0,output, 0, &s);
//    printf("%d\n", k);
//    for (int i=0;i<k;i++)
//        for (int j = 0; j < n; j++)
//        {
//            printf("%d", solution[i][j]);
//            if (j != n - 1)
//                printf(" ");
//            else
//                printf("\n");
//        }
//    return 0;
//}


//C
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//void initStack(Stack* s, int maxsize)
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
//ElementType getTop(Stack* s)
//{
//	return s->data[s->top];
//}
//int isempty(Stack *s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//void backtrack(int n, int num, int output[], int index, Stack* s)
//{
//	ElementType e;
//	if (index == n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			printf("%d", output[i]);
//			if (i != n - 1)
//				printf(" ");
//			else
//				printf("\n");
//		}
//		return;
//	}
//	if (!isempty(s))
//	{
//		pop(s, &e);
//		output[index] = e;
//		backtrack(n, num, output, index + 1, s);
//		push(s, e);
//	}
//	if (num < n)
//	{
//		push(s, num+1 );
//		backtrack(n, num + 1, output,index, s);
//		pop(s, &e);
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		Stack s;
//		initStack(&s,100);
//		int n;
//		scanf("%d", &n);
//		int output[100] = { 0 };
//		backtrack(n,0,output,0,&s);
//	}
//	return 0;
//}