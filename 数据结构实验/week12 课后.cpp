////A
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxNum 100
//#define INFINITY 142857
//typedef struct {
//	int vex[MaxNum];
//	int edge[MaxNum][MaxNum];
//	int vexNum, edgeNum;
//}Graph;
//void Prim(Graph* g)
//{
//	int MinDistance = 0;
//	struct {
//		int minCost;
//		int adjvex;
//	}dist[MaxNum];
//	dist[1].minCost = 0;
//	for (int i = 2; i <= g->vexNum; i++)
//	{
//		dist[i].minCost = g->edge[i][1];
//		dist[i].adjvex = 1;
//	}
//	for (int t = 1; t < g->vexNum; t++)
//	{
//		int min = INFINITY;
//		int k=0;
//		for (int i = 1; i <= g->vexNum; i++)
//		{
//			if (dist[i].minCost != 0 && dist[i].minCost < min)
//			{
//				min = dist[i].minCost;
//				k = i;
//			}
//		}
//		MinDistance += dist[k].minCost;
//		dist[k].minCost = 0;
//		for (int i = 1; i <= g->vexNum; i++)
//		{
//			if (dist[i].minCost != 0 && g->edge[i][k] < dist[i].minCost)
//			{
//				dist[i].minCost = g->edge[i][k];
//				dist[i].adjvex = k;
//			}
//		}
//	}
//	printf("%d\n", MinDistance);
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//		Graph g;
//		g.vexNum = n;
//		g.edgeNum = (n * (n - 1)) / 2;
//		for (int i = 1; i <= n; i++)
//			g.vex[i] = i;
//		for (int i = 1; i <= g.vexNum; i++)
//			for (int j = 1; j <= g.vexNum; j++)
//				g.edge[i][j] = INFINITY;
//		for (int i = 0; i < g.edgeNum; i++)
//		{
//			int a, b, w;
//			scanf("%d%d%d", &a, &b, &w);
//			g.edge[a][b] = g.edge[b][a] = w;
//		}
//		//创建图
//
//		Prim(&g);
//	}
//	return 0;
//}

//B
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxVexNum 1000
//typedef struct {
//	int vex[MaxVexNum];
//	int **edge;
//	int degree[MaxVexNum];
//	int vexNum, edgeNum;
//}Graph;
//void dfs(Graph g, int visited[], int start)
//{
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (g.edge[start][i] && !visited[i])
//		{
//			visited[i] = 1;
//			dfs(g, visited, i);
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	while (scanf("%d%d",&n,&m)!=EOF && n!=0)
//	{
//		Graph g;
//		g.vexNum = n;
//		g.edgeNum = m;
//		g.edge = (int**)malloc(sizeof(int*) * (n + 1));
//		for (int i = 1; i <= n; i++)
//			g.edge[i] = (int*)malloc(sizeof(int) * (n + 1));
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			g.vex[i] = i;
//			g.degree[i] = 0;
//		}
//		for (int i = 1; i <= g.vexNum; i++)
//			for (int j = 1; j <= g.vexNum; j++)
//				g.edge[i][j] = 0;
//		for (int i = 0; i < g.edgeNum; i++)
//		{
//			int a, b;
//			scanf("%d%d", &a, &b);
//			g.edge[a][b] = g.edge[b][a] = 1;
//			g.degree[a]++;
//			g.degree[b]++;
//		}
//		int Judge1 = 1;
//		int visited[MaxVexNum] = { 0 };
//		visited[1] = 1;
//		dfs(g, visited, 1);
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (visited[i] == 0)
//				Judge1 = 0;
//		}
//		int Judge2 = 1;
//		for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (g.degree[i] % 2 != 0)
//				Judge2 = 0;
//		}
//		if (Judge1 && Judge2)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}

//C
//Dijkstra算法的应用
//#include <stdio.h>
//#define MaxVexNum 101
//#define INFINITY 142857
//typedef enum{FALSE,TRUE} Boolean;
//typedef struct {
//	int vex[MaxVexNum];
//	int edge[MaxVexNum][MaxVexNum];
//	int vexNum, edgeNum;
//}Graph;
//void Dijkstra(Graph g, int sta, int end)
//{
//	Boolean found[MaxVexNum] = { FALSE };
//	int dist[MaxVexNum] = { 0 };
//	found[sta] = TRUE;
//	dist[sta] = 0;
//	for (int i = 1; i <= g.vexNum; i++)
//		dist[i] = g.edge[sta][i];
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
//		if (min != INFINITY)
//		{
//			found[k] = TRUE;
//			for (int j = 1; j <= g.vexNum; j++)
//			{
//				if (!found[j] && dist[k] + g.edge[k][j] < dist[j])
//					dist[j] = dist[k] + g.edge[k][j];
//			}
//		}
//	}
//	if (dist[end] < INFINITY)
//		printf("%d", dist[end]);
//	else
//		printf("-1");
//}
//int main()
//{
//	int n, sta, end;
//	scanf("%d%d%d", &n, &sta, &end);
//	Graph g;
//	g.edgeNum = 0;
//	g.vexNum = n;
//	for (int i = 1; i <= n; i++)
//		g.vex[i] = i;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			g.edge[i][j] = INFINITY;
//	for (int i = 1; i <= n; i++)
//	{
//		int k;
//		scanf("%d", &k);
//		g.edgeNum += k;
//		int a;
//		scanf("%d", &a);
//		g.edge[i][a] = 0;
//		for (int j = 1; j <= k - 1; j++)
//		{
//			scanf("%d", &a);
//			g.edge[i][a] = 1;
//		}
//	}
//	Dijkstra(g, sta, end);
//	return 0;
//}

//D
//#include <stdio.h>
//#define MaxNum 100
//typedef struct {
//	int edge[MaxNum][MaxNum];
//	int edgeNum;
//}Graph;
//int dp[MaxNum][MaxNum];
//int findmax(int a,int b,int c,int d)
//{
//	int max;
//	int m1, m2;
//	m1 = a > b ? a : b;
//	m2 = c > d ? c : d;
//	max = m1 > m2 ? m1 : m2;
//	return max;
//}
//int MaxPath(Graph g, int start_x, int start_y,int m, int n)
//{
//	if (dp[start_x][start_y] != -1)
//		return dp[start_x][start_y];
//	int a =0, b=0, c=0, d=0;
//	if (start_x > 0 && g.edge[start_x - 1][start_y] < g.edge[start_x][start_y])
//		a = MaxPath(g, start_x - 1, start_y,m, n) + 1;
//	if (start_x < m - 1 && g.edge[start_x + 1][start_y] < g.edge[start_x][start_y])
//		b = MaxPath(g, start_x + 1, start_y, m, n) + 1;
//	if (start_y > 0 && g.edge[start_x][start_y - 1] < g.edge[start_x][start_y])
//		c = MaxPath(g, start_x, start_y - 1, m, n) + 1;
//	if (start_y < n - 1 && g.edge[start_x][start_y + 1] < g.edge[start_x][start_y])
//		d = MaxPath(g, start_x, start_y + 1,m, n) + 1;
//	return dp[start_x][start_y]=findmax(a, b, c, d);
//}
//int main()
//{
//	int m, n;
//	while (scanf("%d%d", &m, &n) != EOF)
//	{
//		Graph g;
//		int max = 0,min=142857;
//		int max_index1, max_index2;
//		int min_index1, min_index2;
//		g.edgeNum = m * n;
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j < n; j++)
//			{
//				scanf("%d", &g.edge[i][j]);
//				dp[i][j] = -1;
//				if (g.edge[i][j] > max)
//				{
//					max = g.edge[i][j];
//					max_index1 = i;
//					max_index2 = j;
//				}
//			}
//		printf("%d\n", MaxPath(g, max_index1, max_index2,m, n) + 1);
//	}
//	return 0;
//}