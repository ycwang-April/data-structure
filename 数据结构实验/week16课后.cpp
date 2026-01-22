////A
//#include <stdio.h>
//#include <string.h>
//void insert(char s[], char c, int pos, int len)
//{
//	int pos2 = pos - 1;
//	for (int i = len - 1; i > pos2; i--)
//		s[i + 1] = s[i];
//	s[pos2 + 1] = c;
//}
//int main()
//{
//	char s[50] = { 0 };
//	gets_s(s);
//	getchar();
//	int cnt[128] = { 0 };
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//		cnt[s[i]]++;
//	char c;
//	int pos;
//	int num = len;
//	while (1)
//	{
//		scanf("%c%d%*c%*c", &c, &pos);
//		insert(s, c, pos, len);
//		num++;
//		len++;
//		cnt[c]++;
//		if (cnt[c] >= 3)
//		{
//			num -= cnt[c];
//			for (int i = 0; i < len; i++)
//			{
//				if (s[i] == c)
//					s[i] = 0;
//			}
//		}
//		if (num == 0)
//		{
//			printf("You win!\n");
//			break;
//		}
//		for (int i = 0; i < len; i++)
//		{
//			if (s[i] != 0)
//				printf("%c", s[i]);
//		}
//		printf("\n\n");
//	}
//	return 0;
//}

//B
//#include <stdio.h>
//#include <string.h>
//void insert(char s[], char c, int pos, int len)
//{
//	int pos2 = pos - 1;
//	for (int i = len - 1; i > pos2; i--)
//		s[i + 1] = s[i];
//	s[pos2 + 1] = c;
//}
//int main()
//{
//	char s[50] = { 0 };
//	gets_s(s);
//	getchar();
//	int cnt[128] = { 0 };
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//		cnt[s[i]]++;
//	char c;
//	int pos;
//	int num = len;
//	while (1)
//	{
//		scanf("%c%d%*c%*c", &c, &pos);
//		if (c == '@')
//		{
//			for (int i = 0; i < len; i++)
//			{
//				if (cnt[s[i]] >= 3 && s[i]!= 0)
//				{
//					char temp = s[i];
//					num -= cnt[temp];
//					for (int i = 0; i < len; i++)
//					{
//						if (s[i] == temp)
//							s[i] = 0;
//					}
//				}
//			}
//		}
//		else if (c == '#')
//		{
//			s[pos - 1] = s[pos - 2];
//			cnt[s[pos - 2]]++;
//			char temp = s[pos - 1];
//			if (cnt[temp] >= 3 )
//			{
//				num -= cnt[temp];
//				for (int i = 0; i < len; i++)
//				{
//					if (s[i] == temp)
//						s[i] = 0;
//				}
//			}
//		}
//		else
//		{
//			insert(s, c, pos, len);
//			num++;
//			len++;
//			cnt[c]++;
//			if (cnt[c] >= 3)
//			{
//				num -= cnt[c];
//				for (int i = 0; i < len; i++)
//				{
//					if (s[i] == c)
//						s[i] = 0;
//				}
//			}
//		}
//		if (num == 0)
//		{
//			printf("You win!\n");
//			break;
//		}
//		for (int i = 0; i < len; i++)
//		{
//			if (s[i] != 0)
//				printf("%c", s[i]);
//		}
//		printf("\n\n");
//	}
//	return 0;
//}

//D
//#include <stdio.h>
//#include <stdlib.h>
//int compare(const void* a, const void* b)
//{
//	int* pa = (int*)a;
//	int* pb = (int*)b;
//	int** ppa = &pa;
//	int** ppb = &pb;
//	return **ppa - **ppb;
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int* a;
//		a = (int*)malloc(sizeof(int) * n);
//		if (!a)
//			exit(-1);
//		for (int i = 0; i < n; i++)
//			scanf("%d", &a[i]);
//		qsort(a, n, sizeof(int), compare);
//		for (int i = 0; i < n; i++)
//		{
//			printf("%d", a[i]);
//			if (i != n - 1)
//				printf(" ");
//			else
//				printf("\n");
//		}
//	}
//	return 0;
//}

//E
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct {
//	int *vex;
//	int **edge;
//	int vexNum, edgeNum;
//}Graph;
//void DFS(Graph g ,int visited[],int p)
//{
//	visited[p] = 1;
//	for (int i = 1; i <= g.vexNum; i++)
//	{
//		if (g.edge[p][i] && !visited[i])
//			DFS(g, visited, i);
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		Graph g;
//		int n, m;
//		scanf("%d%d", &n, &m);
//		g.vexNum = n;
//		g.edgeNum = m;
//		g.vex = (int*)malloc(sizeof(int) * (n+1));
//		for (int i = 1; i <= n; i++)
//			g.vex[i] = i;
//		g.edge = (int**)malloc(sizeof(int*) * (n + 1));
//		for (int i = 1; i <= n; i++)
//			g.edge[i] = (int*)malloc(sizeof(int) * (n+1));
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				g.edge[i][j] = 0;
//		for (int i = 0; i < m; i++)
//		{
//			int a, b;
//			scanf("%d%d", &a, &b);
//			g.edge[a][b] = g.edge[b][a] = 1;
//		}
//
//		int *visited;
//		visited = (int*)malloc(sizeof(int) * (n+1));
//		for (int i = 1; i <= n; i++)
//			visited[i] = 0;
//		DFS(g, visited, 1);
//		int judge = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			if (visited[i] == 0)
//				judge = 0;
//		}
//		if (judge)
//			printf("yes\n");
//		else
//			printf("no\n");
//	}
//	return 0;
//}