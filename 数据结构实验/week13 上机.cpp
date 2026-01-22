////A
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxNum 21
//#define ERROR -1
//#define INFINITY 142857
//typedef char ElementType;
//typedef int EdgeType;
//typedef struct {
//	ElementType vex[MaxNum];
//	EdgeType edge[MaxNum][MaxNum];
//	int vexNum, edgeNum;
//}Graph;
//int LocateVex(Graph* g, ElementType u)
//{
//	for (int i = 1; i <= g->vexNum; i++)
//	{
//		if (g->vex[i] == u)
//			return i;
//	}
//	return ERROR;
//}
//void InsertEdge(Graph* g, ElementType u, ElementType v, EdgeType w)
//{
//	int i = LocateVex(g, u);
//	int j = LocateVex(g, v);
//	if (i == ERROR || j == ERROR)
//		exit(-1);
//	g->edge[i][j] = g->edge[j][i] = w;
//	g->edgeNum += 2;
//}
//void CreateGraph(Graph* g)
//{
//	g->edgeNum = g->vexNum = 0;
//	int vexNum, edgeNum;
//	scanf("%d%*c", &vexNum);
//	for (int i = 1; i <= vexNum; i++)
//	{
//		scanf("%c%*c", &g->vex[i]);
//		g->vexNum++;
//	}
//	for (int i = 1; i <= g->vexNum; i++)
//		for (int j = 1; j <= g->vexNum; j++)
//			g->edge[i][j] = INFINITY;
//	scanf("%d%*c", &edgeNum);
//	for (int i = 0; i < edgeNum; i++)
//	{
//		char a, b;
//		int weight;
//		scanf("%c,%c:%d%*c", &a, &b, &weight);
//		int m = LocateVex(g, a);
//		int n = LocateVex(g, b);
//		g->edge[m][n] = g->edge[n][m] = weight;
//		g->edgeNum++;
//	}
//}
//void Prime(Graph* g,ElementType u)
//{
//	int res = 0;
//	struct {
//		int minCost;
//		int adjvex;
//	}dist[MaxNum];
//	int m = LocateVex(g, u);
//	if (m == ERROR)
//		exit(-1);
//	dist[m].minCost = 0;
//	for (int i = 1; i <= g->vexNum; i++)
//	{
//		if (i != m)
//		{
//			dist[i].minCost = g->edge[m][i];
//			dist[i].adjvex = m;
//		}
//	}
//	for (int i = 1; i < g->vexNum; i++) //剩余n-1个点
//	{
//		int min = INFINITY, k;
//		for (int j = 1; j <= g->vexNum; j++)
//		{
//			if (dist[j].minCost && dist[j].minCost < min)
//			{
//				min = dist[j].minCost;
//				k = j;
//			}
//		}
//		if (g->vex[dist[k].adjvex] > g->vex[k])
//			printf("%c,%c:%d\n", g->vex[k], g->vex[dist[k].adjvex],dist[k].minCost);
//		else
//	    	printf("%c,%c:%d\n", g->vex[dist[k].adjvex], g->vex[k], dist[k].minCost);
//		res += dist[k].minCost;
//		dist[k].minCost = 0;
//		for (int j = 1; j <= g->vexNum; j++)
//		{
//			if (dist[j].minCost && g->edge[k][j] < dist[j].minCost)
//			{
//				dist[j].minCost = g->edge[k][j];
//				dist[j].adjvex = k;
//			}
//		}
//	}
//	printf("\n%d", res);
//}
//int visited[MaxNum] = { 0 };
//void dfs(Graph g,ElementType u)
//{
//	int m = LocateVex(&g, u);
//	if (m == ERROR)
//		exit(-1);
//	visited[m] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (!visited[i] && g.edge[m][i] < INFINITY)
//			dfs(g, g.vex[i]);
//	}
//}
//int main()
//{
//	int judge = 1;
//	Graph g;
//	CreateGraph(&g);
//	dfs(g, g.vex[1]);
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (visited[i] == 0)
//		{
//			judge = 0;
//			break;
//		}
//	}
//	if (judge == 0)
//		printf("ERROR");
//	else
//		Prime(&g, g.vex[1]);
//	return 0;
//}

//B
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxVexNum 21
//#define MaxEdgeNum 101
//#define ERROR -1
//#define INFINITY 142857
//typedef char ElementType;
//typedef int EdgeType;
//typedef struct {
//	ElementType vex[MaxVexNum];
//	EdgeType edge[MaxVexNum][MaxVexNum];
//	int vexNum, edgeNum;
//}Graph;
//struct edgeinfo {
//	int head, tail;
//	int cost;
//}edge[MaxEdgeNum];
//int vexSet[MaxVexNum];
//void swap(struct edgeinfo* a, struct edgeinfo* b)
//{
//	struct edgeinfo temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int compare(const void* a, const void* b)
//{
//	struct edgeinfo* pa = (struct edgeinfo*)a;
//	struct edgeinfo* pb = (struct edgeinfo*)b;
//	return pa->cost - pb->cost;
//}
//int LocateVex(Graph* g, ElementType u)
//{
//	for (int i = 1; i <= g->vexNum; i++)
//	{
//		if (g->vex[i] == u)
//			return i;
//	}
//	return ERROR;
//}
//void InsertEdge(Graph* g, ElementType u, ElementType v, EdgeType w)
//{
//	int i = LocateVex(g, u);
//	int j = LocateVex(g, v);
//	if (i == ERROR || j == ERROR)
//		exit(-1);
//	g->edge[i][j] = g->edge[j][i] = w;
//	g->edgeNum += 2;
//}
//void CreateGraph(Graph* g)
//{
//	g->edgeNum = g->vexNum = 0;
//	int vexNum, edgeNum;
//	scanf("%d%*c", &vexNum);
//	for (int i = 1; i <= vexNum; i++)
//	{
//		scanf("%c%*c", &g->vex[i]);
//		g->vexNum++;
//	}
//	for (int i = 1; i <= g->vexNum; i++)
//		for (int j = 1; j <= g->vexNum; j++)
//			g->edge[i][j] = INFINITY;
//	scanf("%d%*c", &edgeNum);
//	for (int i = 0; i < edgeNum; i++)
//	{
//		char a, b;
//		int weight;
//		scanf("%c,%c:%d%*c", &a, &b, &weight);
//		int m = LocateVex(g, a);
//		int n = LocateVex(g, b);
//		g->edge[m][n] = g->edge[n][m] = weight;
//		g->edgeNum++;
//	}
//}
//void Kruskal(Graph* g)
//{
//	int res = 0;
//	int k = 0;
//	//初始化辅助数组
//	for (int i = 1; i <= g->vexNum; i++)
//		vexSet[i] = i;
//	for (int i=1;i<=g->vexNum;i++)
//		for (int j = i + 1; j <= g->vexNum; j++)
//		{
//			edge[k].head = i;
//			edge[k].tail = j;
//			edge[k++].cost = g->edge[i][j];
//		}
//	//排序
//	qsort(edge, k , sizeof(struct edgeinfo), compare);
//	for (int i = 0; i <= k; i++)
//	{
//		int vs1, vs2;
//		vs1 = vexSet[edge[i].head];
//		vs2 = vexSet[edge[i].tail];
//		if (vs1 != vs2)
//		{
//			if (g->vex[edge[i].head] > g->vex[edge[i].tail])
//				printf("%c,%c:%d\n", g->vex[edge[i].tail], g->vex[edge[i].head],edge[i].cost);
//			else
//				printf("%c,%c:%d\n", g->vex[edge[i].head], g->vex[edge[i].tail], edge[i].cost);
//			res += edge[i].cost;
//			for (int j = 1; j <= g->vexNum; j++)
//			{
//				if (vexSet[j] == vs2)
//					vexSet[j] = vs1;
//			}
//		}
//	}
//	printf("\n%d", res);
//}
//int visited[MaxVexNum] = { 0 };
//void dfs(Graph g, ElementType u)
//{
//	int m = LocateVex(&g, u);
//	if (m == ERROR)
//		exit(-1);
//	visited[m] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (!visited[i] && g.edge[m][i] < INFINITY)
//			dfs(g, g.vex[i]);
//	}
//}
//int main()
//{
//	int judge = 1;
//	Graph g;
//	CreateGraph(&g);
//	dfs(g, g.vex[1]);
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (visited[i] == 0)
//		{
//			judge = 0;
//			break;
//		}
//	}
//	if (judge == 0)
//		printf("ERROR");
//	else
//		Kruskal(&g);
//	return 0;
//}


//C
//#include <stdio.h>
//#include <string.h>
//void swap(char s1[],char s2[])
//{
//	char temp[15] = { 0 };
//	strcpy(temp, s1);
//	strcpy(s1, s2);
//	strcpy(s2, temp);
//}
//void bubblesort(char s[10][15],int n)
//{
//	for (int i=0;i<n-1;i++)
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			int len1 = strlen(s[j]);
//			int len2 = strlen(s[j + 1]);
//			if (len1 > len2)
//				swap(s[j], s[j + 1]);
//		}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int judge = 1;
//		int n;
//		scanf("%d", &n);
//		char s[10][15] = { 0 };
//		for (int i = 1; i <= n; i++)
//			scanf("%s%*c", s[i]);
//		bubblesort(s, n);
//		for (int i = 1; i <= n; i++)
//		{
//			int len1 = strlen(s[i]);
//			for (int j = i + 1; j <= n; j++)
//			{
//				int len2 = strlen(s[j]);
//				for (int k = 0; k <= len2 - len1; k++)
//				{
//					char temp[15] = { 0 };
//					strncpy(temp, s[j] + k, len1);
//					if (strcmp(temp, s[i]) == 0)
//					{
//						judge = 0;
//						break;
//					}
//				}
//			}
//			if (judge == 0)
//				break;
//		}
//		if (judge == 0)
//			printf("NO\n");
//		else
//			printf("YES\n");
//	}
//	return 0;
//}

//D
//#include <stdio.h>
//#define MaxNum 100
//#define INFINITY 142857
//typedef struct {
//	int vex[MaxNum];
//	int edge[MaxNum][MaxNum];
//	int vexNum, edgeNum;
//}Graph;
//void Dijkstra(Graph g)
//{
//	int found[MaxNum] = { 0 };
//	int dist[MaxNum];
//	for (int i = 1; i <= g.vexNum; i++)
//		dist[i] = g.edge[1][i];
//	found[1] = 1;
//	dist[1] = 0;
//	for (int i = 1; i < g.vexNum; i++)
//	{
//		int min = INFINITY;
//		int k;
//		for (int j = 1; j <= g.vexNum; j++)
//		{
//			if (!found[j] && dist[j] < min)
//			{
//				min = dist[j];
//				k = j;
//			}
//		}
//		found[k] = 1;
//		for (int j = 1; j <= g.vexNum; j++)
//		{
//			if (!found[j] && dist[k] + g.edge[k][j] < dist[j])
//				dist[j] = dist[k] + g.edge[k][j];
//		}
//	}
//	for (int i = 2; i <= g.vexNum; i++)
//		printf("%d\n", dist[i]);
//}
//int main()
//{
//	int vexNum, edgeNum;
//	while (scanf("%d%d", &vexNum, &edgeNum) != EOF)
//	{
//		Graph g;
//		g.vexNum = vexNum;
//		g.edgeNum = edgeNum;
//		for (int i = 1; i <= vexNum; i++)
//			g.vex[i] = i;
//		for (int i = 1; i <= g.vexNum; i++)
//			for (int j = 1; j <= g.vexNum; j++)
//				g.edge[i][j] = INFINITY;
//		for (int i = 1; i <= edgeNum; i++)
//		{
//			int a, b, w;
//			scanf("%d%d%d", &a, &b, &w);
//			g.edge[a][b] = g.edge[b][a] = w;
//		}
//		Dijkstra(g);
//	}
//}