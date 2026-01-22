//A
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct {
//	int parent;
//	int lchild, rchild;
//	int degree;
//}BiNode,*BiTree;
//int main()
//{
//	int n, root;
//	int isCompleteBiTree = 1;
//	scanf("%d%d", &n, &root);
//	BiTree t;
//	t = (BiNode*)malloc(sizeof(BiNode) * (n + 1));
//	if (!t)
//		exit(-1);
//	for (int i = 1; i <= n; i++)
//		t[i].parent = t[i].lchild = t[i].rchild = t[i].degree = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if (a == root || t[a].parent != 0)
//		{
//			if (!t[a].lchild)
//			{
//				t[a].lchild = b;
//				t[b].parent = a;
//				t[a].degree++;
//			}
//			else
//			{
//				t[a].rchild = b;
//				t[b].parent = a;
//				t[a].degree++;
//			}
//		}
//		else
//		{
//			if (!t[b].lchild)
//			{
//				t[b].lchild = a;
//				t[a].parent = b;
//				t[b].degree++;
//			}
//			else
//			{
//				t[b].rchild = a;
//				t[a].parent = b;
//				t[b].degree++;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (t[i].degree == 1)
//		{
//			isCompleteBiTree = 0;
//			break;
//		}
//	}
//	if (isCompleteBiTree == 1)
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//}


//B
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define INFINITY 142857
//typedef struct HNode {
//	int parent;
//	int lchild, rchild;
//	int weight;
//}HNODE,*HuffmanTree;
//typedef char** HuffmanCode;
//void SelectMinTwo(HuffmanTree ht, int n, int* s1, int* s2)
//{
//	int x1, x2;
//	int w1, w2;
//	x1 = x2 = 0;
//	w1 = w2 = INFINITY;
//	for (int i = 1; i <= n; i++)
//	{
//		if (ht[i].parent == 0)
//		{
//			if (ht[i].weight < w1)
//			{
//				w2 = w1;
//				x2 = x1;
//				x1 = i;
//				w1 = ht[i].weight;
//			}
//			else if (ht[i].weight < w2)
//			{
//				w2 = ht[i].weight;
//				x2 = i;
//			}
//		}
//	}
//	if (x1)
//		*s1 = x1;
//	if (x2)
//		*s2 = x2;
//}
//HuffmanTree CreateHuffmanTree(int n)
//{
//	int s1, s2;
//	HuffmanTree ht;
//	ht = (HNODE*)malloc(sizeof(HNODE) * (2 * n));
//	if (!ht)
//		exit(-1);
//	for (int i = 1; i <= 2*n-1; i++)
//		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &ht[i].weight);
//	for (int i = n + 1; i <= 2 * n - 1; i++)
//	{
//		SelectMinTwo(ht, i - 1, &s1, &s2);
//		ht[i].lchild = s1;
//		ht[i].rchild = s2;
//		ht[s1].parent = ht[s2].parent = i;
//		ht[i].weight = ht[s1].weight + ht[s2].weight;
//	}
//	return ht;
//}
//HuffmanCode CreateHuffmanCode(HuffmanTree ht, int n)
//{
//	HuffmanCode hc;
//	hc = (HuffmanCode)malloc(sizeof(char*) * (n + 1));
//	if (!hc)
//		exit(-1);
//	char* cd;
//	cd = (char*)malloc(sizeof(char) * n);
//	if (!cd)
//		exit(-1);
//	int start;
//	cd[n - 1] = '\0';
//	for (int i = 1; i <= n; i++)
//	{
//		start = n - 1;
//		int child = i;
//		int parent = ht[child].parent;
//		while (parent)
//		{
//			start--;
//			if (ht[parent].lchild == child)
//				cd[start] = '0';
//			else
//				cd[start] = '1';
//			child = parent;
//			parent = ht[child].parent;
//		}
//		hc[i] = (char*)malloc(sizeof(char) * (n - start));
//		strcpy(hc[i], &cd[start]);
//	}
//	free(cd);
//	return hc;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		HuffmanTree ht;
//		ht = CreateHuffmanTree(n);
//		HuffmanCode hc;
//		hc = CreateHuffmanCode(ht, n);
//		int WPL = 0;
//		for (int i = 1; i <= n; i++)
//			WPL += strlen(hc[i]) * ht[i].weight;
//		printf("%d\n", WPL);
//	}
//	return 0;
//}


//C
//#include <stdio.h>
//#include <stdlib.h>
//#define INFINITY 142857
//typedef struct {
//	int parent;
//}TNODE,*Tree;
//typedef struct {
//	int a, b;
//	int visited;
//}Relation,*PC;
//Tree CreateTree(int root,PC edge,int n)
//{
//	Tree t;
//	t = (TNODE*)malloc(sizeof(TNODE) * (n + 1));
//	if (!t)
//		exit(-1);
//	for (int i = 1; i <= n; i++)
//		t[i].parent = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 1; j <= n - 1; j++)
//		{
//			if (edge[j].a == root && !edge[j].visited)
//			{
//				t[edge[j].b].parent = root;
//				edge[j].visited = 1;
//			}
//			else if (edge[j].b == root && !edge[j].visited)
//			{
//				t[edge[j].a].parent = root;
//				edge[j].visited = 1;
//			}
//			else if (t[edge[j].a].parent != 0 && !edge[j].visited)
//			{
//				t[edge[j].b].parent = edge[j].a;
//				edge[j].visited = 1;
//			}
//			else if (t[edge[j].b].parent != 0 && !edge[j].visited)
//			{
//				t[edge[j].a].parent = edge[j].b;
//				edge[j].visited = 1;
//			}
//		}
//	}
//	return t;
//}
//int TreeHeight(Tree t, int n)
//{
//	int maxheight = 0;
//	int height;
//	for (int i = 1; i <= n; i++)
//	{
//		height = 1;
//		int parent = t[i].parent;
//		while (parent != 0)
//		{
//			height++;
//			parent = t[parent].parent;
//		}
//		if (height > maxheight)
//			maxheight = height;
//	}
//	return maxheight;
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int minNode = INFINITY;
//		int maxHeight = 0;
//		PC edge;
//		Tree t;
//		edge = (PC)malloc(sizeof(Relation) * n);
//		if (!edge)
//			exit(-1);
//		for (int i = 1; i <= n-1; i++)
//			scanf("%d%d", &edge[i].a, &edge[i].b);
//		for (int root = 1; root <= n; root++)
//		{
//			for (int i = 1; i <= n - 1; i++) 
//				edge[i].visited = 0;
//			int height = 0;
//			t = CreateTree(root, edge, n);
//			height = TreeHeight(t, n);
//			if (height > maxHeight)
//			{
//				maxHeight = height;
//				minNode = root;
//			}
//		}
//		printf("%d %d\n", minNode, maxHeight);
//	}
//	return 0;
//}


//D
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int maxdepth = 1, depth = 1;
//	int maxwidth = 0;
//	int width[100] = { 0 };
//	char s[100] = { 0 };
//	gets_s(s);
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '(')
//			depth++;
//		else if (s[i] == ')')
//			depth--;
//		if (depth > maxdepth)
//			maxdepth = depth;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '(')
//			depth++;
//		else if (s[i] == ')')
//			depth--;
//		else if ('A' <= s[i] && s[i] <= 'Z')
//			width[depth]++;
//	}
//	for (int i = 1; i <= maxdepth; i++)
//	{
//		if (width[i] > maxwidth)
//			maxwidth = width[i];
//	}
//	printf("%d %d", maxdepth, maxwidth);
//	return 0;
//}