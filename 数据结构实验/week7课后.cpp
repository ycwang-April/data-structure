//A
//#include <stdio.h>
//#include <string.h>
//int isdelete(char ch, char delalpha[],int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (ch == delalpha[i])
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char str[1000] = { 0 };
//	char newstr[1000] = { 0 };
//	char delalpha[26] = { 0 };
//	int k = 0;
//	gets_s(str);
//	gets_s(delalpha);
//	int len1 = strlen(str), len2 = strlen(delalpha);
//	for (int i = 0; i < len1; i++)
//	{
//		if (isdelete(str[i], delalpha, len2) != 1)
//			newstr[k++] = str[i];
//	}
//	printf("%s", newstr);
//	return 0;
//}

//B
//#include <stdio.h>
//int main()
//{
//	int a[10];
//	for (int i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	for (int i = 0; i < 9; i++)
//	{
//		if (a[i] == 0)
//			printf("6 ");
//		else if (a[i] == 1)
//			printf("2 ");
//		else if (a[i] == 2 || a[i] == 6)
//			printf("1 ");
//		else
//			printf("0 ");
//	}
//	if (a[9] == 0)
//		printf("6");
//	else if (a[9] == 1)
//		printf("2");
//	else if (a[9] == 2 || a[9] == 6)
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}

//C
//#include <stdio.h>
//void isUglyNumber(int n)
//{
//	for (int i = 7; i < 500; i+=2)
//	{
//		if (n % i == 0)
//		{
//			printf("NO");
//			return;
//		}
//	}
//	printf("YES");
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	isUglyNumber(n);
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
//int main()
//{
//	int t;
//	scanf("%d%*c", &t);
//	while (t--)
//	{
//		Stack s;
//		initStack(&s,100);
//		char Expr[1000] = { 0 };
//		gets_s(Expr);
//		ElementType e;
//		int len = strlen(Expr);
//		for (int i = 0; i < len; i++)
//		{
//			if (Expr[i] == '[' || Expr[i] == '{' || Expr[i] == '(')
//				push(&s, Expr[i]);
//			else if (Expr[i] == ')' && !isempty(s))
//			{
//				pop(&s, &e);
//				if (e != '(')
//				{
//					push(&s, e);
//					break;
//				}
//			}
//			else if (Expr[i] == ']'&&!isempty(s))
//			{
//				pop(&s, &e);
//				if (e != '[')
//				{
//					push(&s, e);
//					break;
//				}
//			}
//			else if (Expr[i] == '}' && !isempty(s))
//			{
//				pop(&s, &e);
//				if (e != '{')
//				{
//					push(&s, e);
//					break;
//				}
//			}
//		}
//		if (isempty(s) == 1)
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	return 0;
//}

//*E 1878 用栈实现递归
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct {
//	int m, n;
//}ope;
//typedef ope ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
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
//int isempty(Stack *s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//int AKM(Stack *s)
//{
//	while (!isempty(s))
//	{
//		ElementType e;
//		pop(s, &e);
//		if (e.m == 0)
//		{
//			if (!isempty(s))
//			{
//				int temp = e.n + 1;
//				pop(s, &e);
//				ElementType e1 = { e.m,temp };
//				push(s, e1);
//			}
//			else
//				return e.n + 1;
//		}
//		else if (e.m != 0 && e.n == 0)
//		{
//			ElementType e1 = { e.m - 1,1 };
//			push(s, e1);
//		}
//		else if (e.m != 0 && e.n != 0)
//		{
//			ElementType e1 = { e.m - 1, 0 };
//			ElementType e2 = { e.m, e.n - 1 };
//			push(s,e1);//用0占位
//			push(s, e2);
//		}
//	}
//} //这个系统太旧了，不能在函数值中用花括号
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	Stack s;
//	initStack(&s, 100);
//	ElementType e = { m,n };
//	push(&s,e);
//	printf("%d",AKM(&s));
//	return 0;
//} 