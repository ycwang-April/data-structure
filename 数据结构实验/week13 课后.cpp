//C
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxVexNum 21
//#define ERROR -1
//typedef char ElementType;
//typedef int EdgeType;
//typedef struct {
//	ElementType vex[MaxVexNum];
//	EdgeType edge[MaxVexNum][MaxVexNum];
//	int vexNum, edgeNum;
//}Graph;
//int LocateVex(Graph g, ElementType u)
//{
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (g.vex[i] == u)
//			return i;
//	}
//	return ERROR;
//}
//int visited1[MaxVexNum] = { 0 };
//int visited2[MaxVexNum] = { 0 };
//void dfs(Graph g, ElementType u)
//{
//	int k = LocateVex(g, u);
//	visited1[k] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (!visited1[i] && g.edge[k][i])
//			dfs(g, g.vex[i]);
//	}
//}
//void DFS(Graph g, ElementType u)
//{
//	int k = LocateVex(g, u);
//	visited2[k] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (!visited2[i] && g.edge[k][i])
//		{
//			if (g.vex[k] < g.vex[i])
//				printf("%c,%c\n", g.vex[k], g.vex[i]);
//			else
//				printf("%c,%c\n", g.vex[i], g.vex[k]);
//			DFS(g, g.vex[i]);
//		}
//	}
//}
//int main()
//{
//	Graph g;
//	int vexNum, edgeNum;
//	scanf("%d%*c", &vexNum);
//	g.vexNum = vexNum;
//	for (int i = 1; i <= vexNum; i++)
//		scanf("%c%*c", &g.vex[i]);
//	scanf("%d%*c", &edgeNum);
//	g.edgeNum = edgeNum;
//	for (int i = 1; i <= g.vexNum; i++)
//		for (int j = 1; j <= g.vexNum; j++)
//			g.edge[i][j] = 0;
//	for (int i = 0; i < edgeNum; i++)
//	{
//		ElementType u, v;
//		scanf("%c,%c", &u, &v);
//		getchar();
//		int m = LocateVex(g, u);
//		int n = LocateVex(g, v);
//		if (m == ERROR || n == ERROR)
//			exit(-1);
//		g.edge[m][n] = g.edge[n][m] = 1;
//	}
//	dfs(g, g.vex[1]);
//	int judge = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (visited1[i] == 0)
//		{
//			judge = 0;
//			break;
//		}
//	}
//	if (judge == 0)
//		printf("ERROR");
//	else
//    	DFS(g,g.vex[1]);
//	return 0;
//}

//A
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxVexNum 21
//#define ERROR -1
//typedef char ElementType;
//typedef struct {
//	ElementType* data;
//	int front, rear;
//	int maxsize;
//}Queue;
//typedef int EdgeType;
//typedef struct {
//	ElementType vex[MaxVexNum];
//	EdgeType edge[MaxVexNum][MaxVexNum];
//	int vexNum, edgeNum;
//}Graph;
//void InitQueue(Queue* q, int maxsize)
//{
//	q->data = (ElementType*)malloc(sizeof(ElementType) * (maxsize));
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//}
//void EnQueue(Queue* q, ElementType u)
//{
//	q->data[q->rear] = u;
//	q->rear = (q->rear + 1) % q->maxsize;
//}
//void DeQueue(Queue* q, ElementType* u)
//{
//	*u = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//}
//int isEmpty(Queue *q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//int LocateVex(Graph g, ElementType u)
//{
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (g.vex[i] == u)
//			return i;
//	}
//	return ERROR;
//}
//int visited1[MaxVexNum] = { 0 };
//int visited2[MaxVexNum] = { 0 };
//void dfs(Graph g, ElementType u)
//{
//	int k = LocateVex(g, u);
//	visited1[k] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (!visited1[i] && g.edge[k][i])
//			dfs(g, g.vex[i]);
//	}
//}
//void BFS(Queue* q, Graph g, ElementType u)
//{
//	int i = LocateVex(g, u);
//	visited2[i] = 1;
//	EnQueue(q, u);
//	while (!isEmpty(q))
//	{
//		ElementType u;
//		int k;
//		DeQueue(q, &u);
//		k = LocateVex(g, u);
//		if (k == ERROR)
//			exit(-1);
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (!visited2[i] && g.edge[k][i])
//			{
//				if (g.vex[k]<g.vex[i])
//				    printf("%c,%c\n", g.vex[k], g.vex[i]);
//				else
//					printf("%c,%c\n", g.vex[i], g.vex[k]);
//				EnQueue(q, g.vex[i]);
//				visited2[i] = 1;
//			}
//		}
//	}
//}
//int main()
//{
//	Queue q;
//	InitQueue(&q, 100);
//	Graph g;
//	int vexNum, edgeNum;
//	scanf("%d%*c", &vexNum);
//	g.vexNum = vexNum;
//	for (int i = 1; i <= vexNum; i++)
//		scanf("%c%*c", &g.vex[i]);
//	scanf("%d%*c", &edgeNum);
//	g.edgeNum = edgeNum;
//	for (int i = 1; i <= g.vexNum; i++)
//		for (int j = 1; j <= g.vexNum; j++)
//			g.edge[i][j] = 0;
//	for (int i = 0; i < edgeNum; i++)
//	{
//		ElementType u, v;
//		scanf("%c,%c", &u, &v);
//		getchar();
//		int m = LocateVex(g, u);
//		int n = LocateVex(g, v);
//		if (m == ERROR || n == ERROR)
//			exit(-1);
//		g.edge[m][n] = g.edge[n][m] = 1;
//	}
//	dfs(g, g.vex[1]);
//	int judge = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (visited1[i] == 0)
//		{
//			judge = 0;
//			break;
//		}
//	}
//	if (judge == 0)
//		printf("ERROR");
//	else
//		BFS(&q, g, g.vex[1]);
//	return 0;
//}


//D
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXNUM 31
//#define INFINITY 142857
//typedef int ElementType;
//typedef struct {
//	ElementType* data;
//	int front, rear;
//	int maxsize;
//}Queue;
//void InitQueue(Queue* q, int maxsize)
//{
//	q->data = (ElementType*)malloc(sizeof(ElementType) * (maxsize));
//	if (!q->data)
//		exit(-1);
//	q->front = q->rear = 0;
//	q->maxsize = maxsize;
//}
//void EnQueue(Queue* q, ElementType u)
//{
//	q->data[q->rear] = u;
//	q->rear = (q->rear + 1) % q->maxsize;
//}
//void DeQueue(Queue* q, ElementType* u)
//{
//	*u = q->data[q->front];
//	q->front = (q->front + 1) % q->maxsize;
//}
//int isEmpty(Queue *q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
////typedef struct {
////	int* data;
////	int top;
////	int maxsize;
////}Stack;
////void InitStack(Stack* s,int maxsize)
////{
////	s->data = (int*)malloc(sizeof(int) * maxsize);
////	if (!s->data)
////		exit(-1);
////	s->top = 0;
////	s->maxsize = maxsize;
////}
////void Push(Stack* s, int u)
////{
////	s->data[s->top++] = u;
////}
////void Pop(Stack* s, int* u)
////{
////	*u = s->data[s->top];
////	s->top--;
////}
////int isempty(Stack s)
////{
////	if (s.top == 0)
////		return 1;
////	else
////		return 0;
////}
//typedef struct {
//	int vex[MAXNUM];
//	int edge[MAXNUM][MAXNUM];
//	int vexNum, edgeNum;
//}Graph;
//void toplogicalOrder (Graph g,int topOrder[])
//{
//	int inDegree[MAXNUM] = { 0 };
//	int visited[MAXNUM] = { 0 };
//	int k = 0;
//	Queue q;
//	InitQueue(&q, 100);
//	//计算入度
//	for (int i=1;i<=g.vexNum;i++)
//		for (int j = 1; j <= g.vexNum; j++)
//		{
//			if (g.edge[i][j] < INFINITY)
//				inDegree[j]++;
//		}
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (inDegree[i] == 0)
//		{
//			EnQueue(&q,g.vex[i]);
//			visited[i] = 1;
//		}
//	}
//	while (!isEmpty(&q))
//	{
//		ElementType u;
//		DeQueue(&q, &u);
//		topOrder[k++] = u;
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (g.edge[u][i] < INFINITY)
//				inDegree[i]--;
//			if (inDegree[i] == 0 && !visited[i])
//			{
//				EnQueue(&q, g.vex[i]);
//				visited[i] = 1;
//			}
//		}
//	}
//}
//void CriticalPath(Graph g,int topOrder[])
//{
//	int ans = 0;
//	int ve[MAXNUM] = { 0 };
//	int vl[MAXNUM] = { 0 };
//	for (int i = 1; i <= g.vexNum; i++)
//		vl[i] = INFINITY;
//	for (int i = 2; i <= g.vexNum; i++)
//	{
//		int k = topOrder[i - 1];
//		for (int j = 1; j <= g.vexNum; j++)
//		{
//			if (g.edge[j][k] < INFINITY && ve[j] + g.edge[j][k] > ve[k])
//				ve[k] = ve[j] + g.edge[j][k];
//		}
//	}
//	vl[g.vexNum] = ve[g.vexNum];
//	for (int i = g.vexNum - 1; i >= 1; i--)
//	{
//		int k = topOrder[i - 1];
//		for (int j = 1; j <= g.vexNum; j++)
//		{
//			if (g.edge[k][j] < INFINITY && vl[j] - g.edge[k][j] < vl[k])
//				vl[k] = vl[j] - g.edge[k][j];
//		}
//	}
//	int k = topOrder[0];
//	while (k != topOrder[g.vexNum - 1])
//	{
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (g.edge[k][i] < INFINITY && ve[k] == vl[i] - g.edge[k][i])
//			{
//				ans += g.edge[k][i];
//				k = i;
//				break;
//			}
//		}
//	}
//	printf("%d\n", ans);
//	k = topOrder[0];
//	while (k != topOrder[g.vexNum - 1])
//	{
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (g.edge[k][i] < INFINITY && ve[k] == vl[i] - g.edge[k][i])
//			{
//				printf("%d %d\n", k, i);
//				k = i;
//				break;
//			}
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	while (scanf("%d%d", &m, &n) != EOF)
//	{
//		Graph g;
//		for (int i = 1; i <= m; i++)
//			g.vex[i] = i;
//		g.vexNum = m;
//		for (int i = 1; i <= m; i++)
//			for (int j = 1; j <= m; j++)
//				g.edge[i][j] = INFINITY;
//		for (int i = 1; i <= n; i++)
//		{
//			int a, b, w;
//			scanf("%d%d%d", &a, &b, &w);
//			g.edge[a][b] = w;
//		}
//		int topOrder[MAXNUM] = { 0 };
//		toplogicalOrder(g, topOrder);
//		CriticalPath(g, topOrder);
//	}
//	return 0;
//}

//B
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int m, n;
//    while (scanf("%d %d", &m, &n) == 2)
//    {
//        double total;
//        if ((m % 2 != 0) && (n % 2 != 0))
//        {
//            // 当m和n均为奇数时，额外增加sqrt(2) - 1
//            total = m * n + sqrt(2) - 1;
//        }
//        else
//        {
//            total = m * n;
//        }
//        printf("%.2f\n", total);
//    }
//    return 0;
//}