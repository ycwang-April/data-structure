////**D  1763 
//#include <string.h>
//#include <stdio.h>
//int main()
//{
//	char s[1000] = { 0 };
//	char num[100][100] = { 0 };
//	int k = 0, cnt = 0;
//	gets_s(s);
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		if ('0' <= s[i] && s[i] <= '9')
//		{
//			num[cnt][k++] = s[i];
//			if (i == len - 1)
//			{
//				cnt++;
//				k = 0;
//			}
//		}
//		else if (k != 0)
//		{
//			cnt++;
//			k = 0;
//		}
//	}
//	for (int i = 0; i < cnt; i++)
//	{
//		int len = strlen(num[i]);
//		int not0_index = 0;
//		while (not0_index < len && num[i][not0_index] == '0')
//		{
//			not0_index++;
//		}
//		if (not0_index == len )
//			printf("0");
//		else
//		{
//			for (int j = not0_index; j < len; j++)
//				printf("%c", num[i][j]);
//		}
//		printf("    ");
//	}
//	return 0;
//}
//错因：1.最后一个字符是数字还是字母要判断-影响cnt的值
//      2.数字前后对0的处理
//Example:000aw12345678900fe1aew0afe0034fgh0.2a
//前导0的处理：
//void processDigits(char* input) {
//	int length = strlen(input);
//	int start = 0;
//
//	// 寻找第一个非零字符的位置
//	while (start < length && input[start] == '0') {
//		start++;
//	}
//
//	// 处理全零的情况
//	if (start == length) {
//		input[0] = '0';
//		input[1] = '\0';
//		return;
//	}
//
//	// 移动有效字符到数组前端
//	int new_pos = 0;
//	for (int i = start; i < length; i++) {
//		input[new_pos++] = input[i];
//	}
//	input[new_pos] = '\0';
//}

//A
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node {
//	int data;
//	struct node* prior;
//	struct node* next;
//}Node,*List;
//void initlist(List* l)
//{
//	Node* s;
//	s = (Node*)malloc(sizeof(Node));
//	if (!s)
//		exit(-1);
//	s->next = NULL;
//	s->prior = NULL;
//	*l = s;
//}
//void addlist(List l)
//{
//	Node* p, * q = l;
//	int num;
//	while (scanf("%d", &num) != EOF)
//	{
//		p = (Node*)malloc(sizeof(Node));
//		p->data = num;
//		p->prior = NULL;
//		q->next = p;
//		q = p;
//	}
//	q->next = NULL;
//}
//void changelist(List l)
//{
//	Node* pre, * p;
//	for (pre = l, p = pre->next; p->next ; pre = pre->next, p = p->next)
//		p->prior = pre;
//	p->next = l;
//}
//void coutlist(List l)
//{
//	Node* p;
//	for (p = l->next; p != l; p = p->next)
//		printf("%d ", p->data);
//}
//int main()
//{
//	List l;
//	initlist(&l);
//	addlist(l);
//	changelist(l);
//	coutlist(l);
//	return 0;
//}

//E
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef struct node {
//	char name[21];
//	struct node* prior;
//	struct node* next;
//}Node,*List;
//void initlist(List* l)
//{
//	Node* s = (Node*)malloc(sizeof(Node));
//	if (!s)
//		exit(-1);
//	s->next = NULL;
//	s->prior = NULL;
//	*l = s;
//}
//void addelement(List l,char name[])
//{
//	Node* p = l->next, * q = l;
//	Node* t = (Node*)malloc(sizeof(Node));
//	strcpy(t->name, name);
//	if (!t)
//		exit(-1);
//	while (p && strcmp(t->name, p->name) > 0)
//	{
//		q = p;
//		p = p->next;
//	}
//	if (p != NULL)
//	{
//		t->next = p;
//		t->prior = q;
//		q->next = t;
//		p->prior = t;
//	}
//	else
//	{
//		p = t;
//		t->next = NULL;
//		t->prior = q;
//		q->next = t;
//	}
//}
//void deletelist(List l,char name[])
//{
//	Node* p=l->next;
//	while (p)
//	{
//		if (strcmp(name, p->name) == 0)
//		{
//			p->prior->next = p->next;
//			free(p);
//			break;
//		}
//		p = p->next;
//	}
//}
//void querylist(List l, char name[])
//{
//	int judge = 0;
//	Node* p;
//	for (p = l->next; p; p = p->next)
//	{
//		if (strcmp(name, p->name) == 0)
//		{
//			judge = 1;
//			break;
//		}
//	}
//	if (judge == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//}
//void coutlist(List l)
//{
//	Node* p;
//	for (p = l->next; p != NULL; p = p->next)
//		printf("%s\n", p->name);
//}
//int main()
//{
//	List l;
//	initlist(&l);
//	char operation[10] = { 0 };
//	while (scanf("%s",operation) != EOF)
//	{
//		char name[21] = { 0 };
//		if (strcmp(operation, "Add") == 0)
//		{
//			scanf("%s%*c", name);
//			addelement(l, name);
//		}
//		else if (strcmp(operation, "Delete") == 0)
//		{
//			scanf("%s%*c", name);
//			deletelist(l, name);
//		}
//		else if (strcmp(operation, "Query") == 0)
//		{
//			scanf("%s%*c", name);
//			querylist(l, name);
//		}
//		else if ((strcmp(operation, "Print") == 0))
//			coutlist(l);
//	}
//	return 0;
//}