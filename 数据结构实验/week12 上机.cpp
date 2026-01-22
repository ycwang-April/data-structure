////A
//#include <stdio.h>
//typedef struct {
//	int x, y;
//}Point;
//int judge = 0;
//void dfs(Point start,Point end,char maze[5][5],int visited[5][5])
//{
//	if (start.x == end.x && start.y == end.y)
//	{
//		judge = 1;
//		printf("YES\n");
//		return;
//	}
//	if (judge == 1)
//		return;
//	if (start.x < 4 && !visited[start.x + 1][start.y] && maze[start.x + 1][start.y] == '.')
//	{
//		start.x++;
//		visited[start.x][start.y] = 1;
//		dfs(start,end, maze, visited);
//		start.x--;
//	}
//	if (start.y < 4 && !visited[start.x][start.y+1] && maze[start.x][start.y+1] == '.')
//	{
//		start.y++;
//		visited[start.x][start.y] = 1;
//		dfs(start, end, maze, visited);
//		start.y--;
//	}
//	if (start.x > 0 && !visited[start.x - 1][start.y] && maze[start.x - 1][start.y] == '.')
//	{
//		start.x--;
//		visited[start.x][start.y] = 1;
//		dfs(start, end, maze, visited);
//		start.x++;
//	}
//	if (start.y > 0 && !visited[start.x][start.y -1 ] && maze[start.x][start.y-1] == '.')
//	{
//		start.y--;
//		visited[start.x][start.y] = 1;
//		dfs(start, end, maze, visited);
//		start.y++;
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		judge = 0;
//		Point start, end;
//		scanf("%d%d%d%d%*c", &start.x, &start.y, &end.x, &end.y);
//		char maze[5][5];
//		int visited[5][5] = { 0 };
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 5; j++)
//				scanf("%c", &maze[i][j]);
//			getchar();
//		}
//		visited[start.x][start.y] = 1;
//		dfs(start, end, maze, visited);
//		if (judge == 0)
//			printf("NO\n");
//	}
//	return 0;
//}


//C
//#include <stdio.h>
//#define MaxVexNum 20
//typedef struct {
//	int vex[MaxVexNum];
//	int edge[MaxVexNum][MaxVexNum];
//	int vexNum, edgeNum;
//}Graph;
//void dfs(Graph g, int visited[], int start)
//{
//	for (int i = 0; i < g.vexNum; i++)
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
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		Graph g;
//		g.vexNum = n;
//		for (int i = 0; i < n; i++)
//			g.vex[i] = i;
//		for (int i=0;i<n;i++)
//			for (int j=0;j<n;j++)
//			{
//				scanf("%d", &g.edge[i][j]);
//				g.edgeNum++;
//			}
//		int Judge = 1;
//		for (int i = 0; i < n; i++)
//		{
//			int visited[MaxVexNum] = { 0 };
//			visited[i] = 1;
//			dfs(g, visited, i);
//			int judge = 1;
//			for (int i = 0; i < n; i++)
//			{
//				if (visited[i] == 0)
//					judge = 0;
//			}
//			if (judge == 0)
//				Judge = 0;
//		}
//		if (Judge == 0)
//			printf("NO\n");
//		else
//			printf("YES\n");
//	}
//	return 0;
//}


//D
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxVexNum 1000
//typedef struct{
//	int vex[MaxVexNum];
//	int **edge;
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
//	int n;
//	while (scanf("%d", &n) != EOF && n != 0)
//	{
//		int cnt = 0;
//		int m;
//		scanf("%d", &m);
//		Graph g;
//		g.edge = (int**)malloc(sizeof(int*) * (n + 1));
//		for (int i = 1; i <= n; i++)
//			g.edge[i] = (int*)malloc(sizeof(int) * (n + 1));
//		for (int i = 1; i <= n; i++)
//			g.vex[i] = i;
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				g.edge[i][j] = 0;
//		int a, b;
//		for (int i = 0; i < m; i++)
//		{
//			scanf("%d%d", &a, &b);
//			g.edge[a][b] = g.edge[b][a] = 1;
//		}
//		g.vexNum = n;
//		g.edgeNum = 2 * m;
//		//CreateGraph
//
//		int visited[MaxVexNum] = { 0 };
//	    for (int i = 1; i <= g.vexNum; i++)
//		{
//			if (!visited[i])
//			{
//				dfs(g, visited, i);
//				cnt++;
//			}
//		}
//		printf("%d\n", cnt - 1);
//	}
//	return 0;
//}


//B 
//欧拉图：要求图为连通图且每个顶点的度为2
//                                                  