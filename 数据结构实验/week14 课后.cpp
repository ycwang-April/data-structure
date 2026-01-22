//A
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	scanf("%s", s);
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == 'M')
//			printf("Monday\n");
//		else if (s[i] == 'W')
//			printf("Wednesday\n");
//		else if (s[i] == 'F')
//			printf("Friday\n");
//		else if (s[i] == 'T' && s[i + 1] == 'u')
//		{
//			i++;
//			printf("Tuesday\n");
//		}
//		else if (s[i] == 'T' && s[i + 1] == 'h')
//		{
//			printf("Thursday\n");
//			i++;
//		}
//		else if (s[i] == 'S' && s[i + 1] == 'a')
//		{
//			i++;
//			printf("Saturday\n");
//		}
//		else if (s[i] == 'S' && s[i + 1] == 'u')
//		{
//			printf("Sunday\n");
//			i++;
//		}
//		else if (s[i] == 'Y')
//			break;
//		else
//			printf("Wrong data\n");
//	}
//	return 0;
//}


//B
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int compare(const void* a, const void* b)
//{
//	int* pa = (int*)a;
//	int* pb = (int*) b;
//	return *pa - *pb;
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int* arr;
//		arr = (int*)malloc(sizeof(int) * n);
//		if (!arr)
//			exit(-1);
//		for (int i = 0; i < n; i++)
//			scanf("%d", &arr[i]);
//		qsort(arr, n, sizeof(int), compare);
//		int odd_sum = 0;
//		int even_sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if ((i + 1) % 2 == 1)
//				odd_sum += arr[i];
//			else
//				even_sum += arr[i];
//		}
//		printf("%d\n", abs(odd_sum - even_sum));
//	}
//	return 0;
//}


//C
//#include <stdio.h>
//#include <string.h>
//#define HTSIZE 11
//typedef int ElementType;
//ElementType HashTable[HTSIZE] = { 0 };
//int Hashfunc(int key)
//{
//	return key % 11;
//}
//int main()
//{
//	char name[25];
//	while (gets_s(name) != NULL)
//	{
//		int key = 0;
//		int len = strlen(name);
//		for (int i = 0; i < len; i++)
//		{
//			if ('A' <= name[i] && name[i] <= 'Z')
//				key = key * 100 + name[i] - 64;
//		}
//		int address = Hashfunc(key);
//		if (HashTable[address] == 0)
//		{
//			printf("%d\n", address);
//			HashTable[address] = 1;
//		}
//		else
//		{
//			while (HashTable[address] == 1)
//				address = (address + 1) % HTSIZE;
//			HashTable[address] = 1;
//			printf("%d\n", address);
//		}
//	}
//	return 0;
//}

//D
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct BiNode{
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE,*BiTree;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;;
//}
//void InsertBST(BiTree* t, ElementType e)
//{
//	if (*t == NULL)
//	{
//		BiNODE* p;
//		p = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!p)
//			exit(-1);
//		*t = p;
//		(*t)->data = e;
//		(*t)->lchild = (*t)->rchild = NULL;
//	}
//	else if (e < (*t)->data)
//		InsertBST(&(*t)->lchild, e);
//	else
//		InsertBST(&(*t)->rchild, e);
//}
//int SearchBST(BiTree t, ElementType e)
//{
//	if (t->data == e)
//	{
//		printf("%d", e);
//		return 1;
//	}
//	else if (e < t->data)
//	{
//		printf("%d->", t->data);
//		return SearchBST(t->lchild, e) + 1;
//	}
//	else
//	{
//		printf("%d->", t->data);
//		return SearchBST(t->rchild, e) + 1;
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		BiTree t;
//		initBiTree(&t);
//		int num;
//		while (1)
//		{
//			scanf("%d", &num);
//			if (num == -1)
//				break;
//			InsertBST(&t, num);
//		}
//		int Search_num;
//		scanf("%d", &Search_num);
//		int cnt=SearchBST(t, Search_num);
//		printf("\n%d\n", cnt);
//	}
//	return 0;
//}


//E
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXNUM 100
//#define INFINITY 142857
//typedef struct {
//	int vex[MAXNUM];
//	int edge[MAXNUM][MAXNUM];
//	int vexNum, edgeNum;
//}Graph;
//void CreateGraph(Graph* g, int n)
//{
//	g->vexNum = n;
//	g->edgeNum = 0;
//	for (int i = 1; i <= n; i++)
//		g->vex[i] = i;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//		{
//			scanf("%d", &g->edge[i][j]);
//			if (g->edge[i][j])
//				g->edgeNum++;
//			if (i == j)
//				g->edge[i][j] = INFINITY;
//		}
//}
//void Prim(Graph g)
//{
//	int found[MAXNUM] = { 0 };
//	int dist[MAXNUM];
//	found[1] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//		dist[i] = g.edge[1][i];
//	for (int j = 0; j < g.vexNum - 1; j++)
//	{
//		int min = INFINITY;
//		int k = 1;
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (dist[i] < min && !found[i])
//			{
//				min = dist[i];
//				k = i;
//			}
//		}
//		found[k] = 1;
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (!found[i] && g.edge[k][i] < dist[i])
//				dist[i] = g.edge[k][i];
//		}
//	}
//	int max = 0;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (dist[i] < INFINITY && dist[i] > max)
//			max = dist[i];
//	}
//	printf("%d\n", max);
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		Graph g;
//		int n;
//		scanf("%d", &n);
//		CreateGraph(&g, n);
//		Prim(g);
//	}
//	return 0;
//}