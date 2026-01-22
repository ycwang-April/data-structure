//C
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXNUM 31
//#define INFINITY 142857
//typedef int ElementType;
//typedef struct {
//	int vex[MAXNUM];
//	int edge[MAXNUM][MAXNUM];
//	int vexNum, edgeNum;
//}Graph;
//typedef struct {
//	int* data;
//	int front, rear;
//	int maxsize;
//}Queue;
//void initQueue(Queue* q, int maxsize)
//{
//	q->data = (int*)malloc(sizeof(int) * maxsize);
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
//int isEmpty(Queue q)
//{
//	if (q.front == q.rear)
//		return 1;
//	else
//		return 0;
//}
//void ToplogicalOrder(Graph g, int topOrder[])
//{
//	int k = 0;
//	int inDegree[MAXNUM] = { 0 };
//	int visited[MAXNUM] = { 0 };
//	Queue q;
//	initQueue(&q, 100);
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		for (int j = 1; j <= g.vexNum; j++)
//		{
//			if (g.edge[j][i] < INFINITY)
//				inDegree[i]++;
//		}
//	}
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (inDegree[i] == 0)
//		{
//			EnQueue(&q, i);
//			visited[i] = 1;
//		}
//	}
//	while (!isEmpty(q))
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
//				EnQueue(&q, i);
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
//	while (scanf("%d%d", &n, &m) != EOF)
//	{
//		//´´½¨Í¼
//		Graph g;
//		g.vexNum = n;
//		g.edgeNum = m;
//		for (int i = 1; i <= n; i++)
//			g.vex[i] = i;
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				g.edge[i][j] = INFINITY;
//		for (int i = 0; i < m; i++)
//		{
//			int a, b, w;
//			scanf("%d%d%d", &a, &b, &w);
//			g.edge[a][b] = w;
//		}
//		int topOrder[MAXNUM] = { 0 };
//		ToplogicalOrder(g, topOrder);
//		CriticalPath(g, topOrder);
//	}
//	return 0;
//}


//A
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int calculate(char s[])
//{
//	int len = strlen(s);
//	int cnt = 0;
//	for (int i = 0; i < len; i++)
//	{
//		char pivot = s[i];
//		for (int j = i + 1; j < len; j++)
//		{
//			if (pivot > s[j])
//				cnt++;
//		}
//	}
//	return cnt;
//}
//int main()
//{
//	int n, m;
//	int* nx_num;
//	while (scanf("%d%d", &n, &m) != EOF)
//	{
//		getchar();
//		char s[100][51] = { 0 };
//		nx_num = (int*)malloc(sizeof(int) * m);
//		for (int i = 0; i < m; i++)
//		{
//			gets_s(s[i]);
//			nx_num[i] = calculate(s[i]);
//		}
//		for (int i=0;i<m-1;i++)
//			for (int j = 0; j < m - 1 - i; j++)
//			{
//				if (nx_num[j] > nx_num[j + 1])
//				{
//					int Temp = nx_num[j];
//					nx_num[j] = nx_num[j + 1];
//					nx_num[j + 1] = Temp;
//					char temp[51] = { 0 };
//					strcpy(temp, s[j]);
//					strcpy(s[j], s[j+1]);
//					strcpy(s[j + 1], temp);
//				}
//			}
//		for (int i = 0; i < m; i++)
//			printf("%s\n", s[i]);
//	}
//	return 0;
//}