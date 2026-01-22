//课后题
//B
//#include <stdio.h>
//typedef struct {
//	int i, j;
//}position;
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a[10][10] = { 0 };
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			scanf("%d", &a[i][j]);
//	int min = a[0][0], secmin = a[0][0];
//	position min_index , secmin_index;
//	min_index.i = min_index.j = secmin_index.i = secmin_index.j = 0;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] < min)
//			{
//				min = a[i][j];
//				min_index.i = i;
//				min_index.j = j;
//			}
//		}
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j]<secmin && a[i][j]>min)
//			{
//				secmin = a[i][j];
//				secmin_index.i = i;
//				secmin_index.j = j;
//			}
//		}
//	swap(&a[0][0], &a[min_index.i][min_index.j]);
//	swap(&a[n-1][n-1], &a[secmin_index.i][secmin_index.j]);
//	for (int i = 0; i < n; i++)
//	{
//		int j = 0;
//		for ( ; j < n-1; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("%d\n", a[i][j]);
//	}
//}

//C
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct node {
//	ElementType data;
//	struct node* next;
//}Node,*List;
//void initlist(List* l)
//{
//	Node* t;
//	t = (Node*)malloc(sizeof(Node));
//	if (!t)
//		exit(-1);
//	*l = t;
//	t->next = NULL;
//}
//void addelement(List l)
//{
//	Node* p, * q = l;
//	int num;
//	while (scanf("%d", &num) != EOF && num != 0)
//	{
//		p = (Node*)malloc(sizeof(Node));
//		if (!p)
//			exit(-1);
//		p->data = num;
//		q->next = p;
//		q = p;
//	}
//	q->next = NULL;
//}
//void forward(List l)
//{
//	Node* p = l->next,*q = l,*t;
//    while(p)
//	{
//		if (p->data > 0)
//		{
//			q->next = p->next;
//			for (t = l; t->next->data > 0; t = t->next);
//			p->next = t->next;
//			t->next = p;
//			p = q->next;
//		}
//		else
//		{
//			q = q->next;
//			p = p->next;
//		}
//	}
//}
//void coutlist(List l)
//{
//	Node* p;
//	for (p = l->next; p; p = p->next)
//		printf("%d ", p->data);
//}
//int main()
//{
//	List l;
//	initlist(&l);
//	addelement(l);
//	forward(l);
//	coutlist(l);
//}

//D
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int compare(const void* a, const void* b)
//{
//	char* pa = (char*)a;
//	char* pb = (char*)b;
//	return *pa - *pb;
//}
//int main()
//{
//	char s[1000] = { 0 };
//	gets_s(s);
//	int len = strlen(s);
//	qsort(s, len, sizeof(char), compare);
//	puts(s);
//	return 0;
//}

//F
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//typedef float ElementType;
//typedef struct {
//	ElementType* data;
//	int top;
//	int maxsize;
//}Stack;
//int k = 0;
//void initstack(Stack* s,int maxsize)
//{
//	s->data = (ElementType*)malloc(maxsize * sizeof(ElementType));
//	if (!s->data)
//		exit(-1);
//	s->top = -1;
//	s->maxsize = maxsize;
//}
//void push(Stack* s,ElementType e)
//{
//	s->top++;
//	s->data[s->top] = e;
//}
//void pop(Stack* s, ElementType* e)
//{
//	*e = s->data[s->top];
//	s->top--;
//}
//void clearstack(Stack* s)
//{
//	s->top = -1; 
//}
//int isempty(Stack* s)
//{
//	if (s->top == -1)
//		return 1;
//	else
//		return 0;
//}
//ElementType getTop(Stack* s)
//{
//	return s->data[s->top];
//}
//void infixExprTopostfixExpr(Stack *s,char infixExpr[], float postfixExpr[], int len)
//{
//	char ch;
//	ElementType e,test;
//	int isp[128] = { 0 }, osp[128] = { 0 };
//	isp['('] = 1; isp['+'] = isp['-'] = 3; isp['*'] = isp['%'] = isp['/'] = 5; isp[')'] = 7;
//	osp['('] = 9; osp['+'] = osp['-'] = 3; osp['*'] = osp['%'] = osp['/'] = 5; osp[')'] = 7;
//	for (int i = 0; i < len; i++)
//	{
//		ch = infixExpr[i];
//		if ('0' <= ch && ch <= '9')
//		{
//			float temp = ch - '0';
//			while ('0' <= infixExpr[i + 1] && infixExpr[i + 1] <= '9')
//			{
//				i++;
//				temp = temp * 10 + infixExpr[i] - '0';
//			}
//			postfixExpr[k++] = temp;
//		}
//		else if (ch == '(')
//			push(s, ch);
//		else if (ch == ')')
//		{
//			while ( getTop(s) != '(' )
//			{
//				pop(s, &e);
//				postfixExpr[k++] =  -e;
//			}
//			pop(s, &e);
//		}
//		else
//		{
//			while (!isempty(s) && osp[ch] <= isp[(int)getTop(s)])
//			{
//				pop(s, &e);
//				postfixExpr[k++] =  -e;
//			}
//			push(s, ch);
//		}
//	}
//	while (!isempty(s))
//	{
//		pop(s, &e);
//		postfixExpr[k++] =  -e;
//	}
//}
//float calculatepostfixExpr(float postfixExpr[], Stack* s,int k)
//{
//	ElementType e;
//	float ch, op1=0, op2=0;
//	for (int i = 0; i < k; i++)
//	{
//		ch = postfixExpr[i];
//		if (ch == -'+' || ch == -'-' || ch == -'*' || ch == -'%' || ch == -'/')
//		{
//			pop(s, &op2);
//			pop(s, &op1);
//			switch ((int)ch)
//			{
//			case(-'+'):push(s, (float)op1 + op2); break;
//			case(-'-'):push(s, (float)op1 - op2); break;
//			case(-'*'):push(s, (float)op1 * op2); break;
//			case(-'/'):push(s, (float)op1 / op2); break;
//			case(-'%'):push(s, (int)op1 % (int)op2); break;
//			}
//		}
//		else
//			push(s, ch);
//	}
//	return getTop(s);
//}
//int main()
//{
//	char infixExpr[100] = { 0 };
//	while (gets_s(infixExpr) != NULL)
//	{
//		Stack s;
//		initstack(&s, 100);
//		ElementType postfixExpr[100] = { 0 };
//		int len = strlen(infixExpr);
//		infixExprTopostfixExpr(&s, infixExpr, postfixExpr, len);
//		clearstack(&s);
//		float res = calculatepostfixExpr(postfixExpr, &s, k);
//		printf("%.3f\n", res);
//	}
//	return 0;
//}

//A
//#include <stdio.h>
//typedef int ElementType;
//typedef struct {
//	int i, j;
//	ElementType e;
//}Triple;
//typedef struct {
//	Triple data[101];
//}Martix;
//void createMartix(Martix* m)
//{
//	int k = 1;
//	int a, b, c;
//	while (scanf("%d,%d,%d", &a, &b, &c) != EOF && (a != -1 && b != -1 && c != -1))
//	{
//		m->data[k].i = a;
//		m->data[k].j = b;
//		m->data[k].e = c;
//		k++;
//	}
//	m->data[0].i = m->data[0].j = 1000;
//	m->data[0].e = k - 1;
//}
//void printMartix(Martix m)
//{
//	if (m.data[0].e == 0)
//		printf("No non-zero number exists!");
//	else
//	{
//		for (int i = 1; i <= m.data[0].e; i++)
//			printf("%d,%d,%d\n", m.data[i].i, m.data[i].j,m.data[i].e);
//	}
//}
//void transposeMartix(Martix m, Martix* t)
//{
//	t->data[0].i = t->data[0].j = 1000;
//	t->data[0].e = m.data[0].e;
//	int num[1000] = { 0 };
//	int startingpos[1000] = { 0 };
//	for (int i = 1; i <= m.data[0].e; i++)
//		num[m.data[i].j]++;
//	startingpos[0] = 1;
//	for (int k = 1; k < m.data[0].j; k++)
//		startingpos[k] = startingpos[k - 1] + num[k - 1];
//	for (int i = 1; i <= m.data[0].e; i++)
//	{
//		int tPos;
//		tPos = startingpos[m.data[i].j]++;
//		t->data[tPos].i = m.data[i].j;
//		t->data[tPos].j = m.data[i].i;
//		t->data[tPos].e = m.data[i].e;
//	}
//}
//void mulMartix(Martix a, Martix b, Martix* c)
//{
//	int num = 0;
//	int row = a.data[1].i, column = b.data[1].i;
//	int row_index = 1, column_index = 1;
//	int aPos = 1, bPos = 1, cPos = 1;
//	while (1)
//	{
//		//判断b是否还在原来一列
//		if (b.data[bPos].i != column && bPos != b.data[0].e + 1)
//		{
//			if (num != 0)
//			{
//				c->data[cPos].i = row;
//				c->data[cPos].j = column;
//				c->data[cPos++].e = num;
//			}
//			num = 0;
//			aPos = row_index;
//			column = b.data[bPos].i;
//			column_index = bPos;
//		}
//		//判断b是否遍历完
//		else if (bPos == b.data[0].e + 1)
//		{
//			if (num != 0)
//			{
//				c->data[cPos].i = row;
//				c->data[cPos].j = column;
//				c->data[cPos++].e = num;
//			}
//			num = 0;
//			bPos = 1;
//			while (a.data[aPos].i == row)
//			{
//				aPos++;
//			}
//			row = a.data[aPos].i;
//			row_index = aPos;
//			column = b.data[bPos].i;
//			column_index = bPos;
//		}
//		if ((aPos == a.data[0].e + 1) && bPos == 1)
//			break;
//		if (a.data[aPos].j == b.data[bPos].j)
//			num += a.data[aPos++].e * b.data[bPos++].e;
//		else if (a.data[aPos].j < b.data[bPos].j)
//		{
//			if (a.data[aPos + 1].i != row)
//			{
//				aPos = row_index;
//				bPos++;
//			}
//			else
//			    aPos++;
//		}
//		else
//			bPos++;
//	}
//	c->data[0].e = cPos - 1;
//}
//int main()
//{
//	Martix a, b,bT,c;
//	createMartix(&a);
//	createMartix(&b);
//	transposeMartix(b, &bT);
//	mulMartix(a, bT, &c);
//	printMartix(c);
//}

//E
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[1000], newstr[1000] = { 0 };
//	int k = 0;
//	gets_s(s);
//	int len = strlen(s);
//	int alpha_cnt = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if ('a' <= s[i] && s[i] <= 'z')
//			alpha_cnt++;
//	}
//	int cnt = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if ('a' <= s[i] && s[i] <= 'z')
//		{
//			newstr[k++] = s[i];
//			cnt++;
//		}
//		if (cnt == alpha_cnt / 2)
//			break;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		if ('0' <= s[i] && s[i] <= '9')
//			newstr[k++] = s[i];
//	}
//	cnt = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if ('a' <= s[i] && s[i] <= 'z'&&cnt< alpha_cnt /2)
//			cnt++;
//		else if ('a' <= s[i] && s[i] <= 'z' && cnt >= alpha_cnt/ 2)
//			newstr[k++] = s[i];
//	}
//	printf("%s", newstr);
//	return 0;
//}