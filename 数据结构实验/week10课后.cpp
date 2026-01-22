////A
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define INFINITY 142857
//typedef struct {
//	int weight;
//	int parent, lchild, rchild;
//}HNODE,*HuffmanTree;
//typedef char** HuffmanCode;
//void SelectMinTwo(HuffmanTree ht, int n, int* s1, int* s2)
//{
//	int x1, x2;
//	int w1, w2;
//	w1 = w2 = INFINITY;
//	x1 = x2 = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (ht[i].parent == 0)
//		{
//			if (ht[i].weight < w1)
//			{
//				w2 = w1;
//				x2 = x1;
//				w1 = ht[i].weight;
//				x1 = i;
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
//HuffmanTree CreateHuffmanTree( int n)
//{
//	HuffmanTree ht;
//	int min_index1,min_index2;
//	ht = (HNODE*)malloc(sizeof(HNODE) * (2 * n));
//	if (!ht)
//		exit(-1);
//	for (int i = 1; i < 2 * n; i++)
//		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &ht[i].weight);
//	for (int i = n + 1; i < 2 * n; i++)
//	{
//		SelectMinTwo(ht, i - 1, &min_index1, &min_index2);
//		ht[min_index1].parent = ht[min_index2].parent = i;
//		ht[i].lchild = min_index1;
//		ht[i].rchild = min_index2;
//		ht[i].weight = ht[min_index1].weight + ht[min_index2].weight;
//	}
//	return ht;
//}
//HuffmanCode CreateHuffmanCode(HuffmanTree ht,int n)
//{ 
//	HuffmanCode hc;
//	int parent, child, start;
//	hc = (HuffmanCode)malloc(sizeof(char*) * (n + 1));
//	if (!hc)
//		exit(-1);
//	char* cd = (char*)malloc(sizeof(char) * n);
//	if (!cd)
//		exit(-1);
//	cd[n - 1] = '\0';
//	for (int i = 1; i <= n; i++)
//	{
//		child = i;
//		parent = ht[child].parent;
//		start = n - 1;
//		while (parent != 0)
//		{
//			start--;
//			if (child == ht[parent].lchild)
//				cd[start] = '0';
//			else
//				cd[start] = '1';
//			child = parent;
//			parent = ht[child].parent;
//		}
//		hc[i] = (char*)malloc(sizeof(char) * (n - start));
//		strcpy(hc[i], &cd[start]);
//	}
//	return hc;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	HuffmanTree ht = NULL;
//	HuffmanCode hc = NULL;
//	ht=CreateHuffmanTree(n);
//	hc=CreateHuffmanCode(ht, n);
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//		sum += ht[i].weight * strlen(hc[i]);
//	printf("%d", sum);
//	return 0;
//}

//B
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char s[100] = { 0 };
//		gets_s(s);
//		int sum = 0;
//		int depth = 0;
//		int len = strlen(s);
//		for (int i = 0; i < len; i++)
//		{
//			if ('A' <= s[i] && s[i] <= 'Z' && depth != 0)
//				sum += depth;
//			else if (s[i] == '(')
//				depth++;
//			else if (s[i] == ')')
//				depth--;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//C
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_N 35
//
//int score[MAX_N];
//int dp[MAX_N][MAX_N];
//int root[MAX_N][MAX_N];
//int ans[MAX_N];
//int pos;
//
//void pre_order(int i, int j) {
//    if (i > j) return;
//    int k = root[i][j];
//    ans[pos++] = k;
//    pre_order(i, k - 1);
//    pre_order(k + 1, j);
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &score[i]);
//    }
//
//    // 初始化dp数组和root数组
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (i == j) {
//                dp[i][i] = score[i];
//                root[i][i] = i;
//            }
//            else if (i > j) {
//                dp[i][j] = 1;
//            }
//            else {
//                dp[i][j] = 0; // 初始化为0，后续计算最大值
//            }
//        }
//    }
//
//    // 动态规划填表
//    for (int l = 2; l <= n; l++) { // 区间长度
//        for (int i = 1; i + l <= n  + 1; i++) {
//            int j = i + l - 1;
//            dp[i][j] = 0; // 确保从0开始比较
//            for (int k = i; k <= j; k++) {
//                int left = (k > i) ? dp[i][k - 1] : 1;
//                int right = (k < j) ? dp[k + 1][j] : 1;
//                int current = left * right + score[k];
//                if (current > dp[i][j] /*|| (current == dp[i][j] && k < root[i][j])*/) {
//                    dp[i][j] = current;
//                    root[i][j] = k;
//                }
//            }
//        }
//    }
//
//    // 输出最高加分
//    printf("%d\n", dp[1][n]);
//
//    // 构造前序遍历序列
//    pos = 0;
//    pre_order(1, n);
//
//    // 输出前序序列
//    for (int i = 0; i < pos; i++) {
//        printf("%d", ans[i]);
//        if (i < pos - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}


//C2
//#include <stdio.h>
//#define NUM 30
//int pos;
//void PreOrderTraverse(int i, int j,int root[NUM][NUM],int ans[NUM])
//{
//	if (i > j)
//		return;
//	int k = root[i][j];
//	ans[pos++] = k;
//	PreOrderTraverse(i, k - 1, root,ans);
//	PreOrderTraverse(k + 1, j, root,ans);
//}
//int main()
//{
//	int score[NUM] = { 0 };
//	int dp[NUM][NUM] = { 0 };
//	int root[NUM][NUM] = { 0 };
//	int ans[NUM] = { 0 };
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &score[i]);
//	for (int i=1;i<=n;i++)
//		for (int j = 1; j <= n; j++)
//		{
//			if (i == j)
//			{
//				dp[i][j] = score[i];
//				root[i][j] = i;           //记得初始化root数组
//			}
//		}
//	for (int len=2;len<=n;len++)
//		for (int i = 1; i <= n; i++)
//		{
//			int j = i + len - 1;
//			for (int k = i; k <= j; k++)
//			{
//				int lchild = (k > i) ? dp[i][k - 1] : 1;
//				int rchild = (k < j) ? dp[k+1][j] : 1;
//				int current = lchild * rchild + score[k];
//				if (current > dp[i][j])
//				{
//					dp[i][j] = current;
//					root[i][j] = k;
//				}
//			}
//		}
//	printf("%d\n", dp[1][n]);
//	PreOrderTraverse(1, n, root,ans);
//	for (int i = 0; i < pos; i++)
//	{
//		printf("%d", ans[i]);
//		if (i != pos - 1)
//			printf(" ");
//	}
//	return 0;
//}

//D
//#include <stdio.h>
//#include <stdlib.h>
//typedef char ElementType;
//typedef struct  BiNode {
//	ElementType data;
//	int lchild, rchild;
//}BiNODE,*BiTree;
//void PreOrderTraverse(BiTree t,int i)
//{
//	putchar(t[i].data);
//	if (t[i].lchild)
//		PreOrderTraverse(t, t[i].lchild);
//	if (t[i].rchild)
//		PreOrderTraverse(t,t[i].rchild);
//}
//void InOrderTraverse(BiTree t,int i)
//{
//	if (t[i].lchild)
//		InOrderTraverse(t, t[i].lchild);
//	putchar(t[i].data);
//	if (t[i].rchild)
//		InOrderTraverse(t, t[i].rchild);
//}
//void PostOrderTraverse(BiTree t,int i)
//{
//	if (t[i].lchild)
//		PostOrderTraverse(t, t[i].lchild);
//	if (t[i].rchild)
//		PostOrderTraverse(t, t[i].rchild);
//	putchar(t[i].data);
//}
//int main()
//{
//	int c;
//	scanf("%d", &c);
//	for (int i = 1; i <= c; i++)
//	{
//		int n;
//		scanf("%d", &n);
//		getchar();
//		BiTree t;
//		t = (BiTree)malloc(sizeof(BiNODE) * (n+1));
//		if (!t)
//			exit(-1);
//		for (int i = 1; i <= n; i++)
//			scanf("%c%d%d%*c", &t[i].data, &t[i].lchild, &t[i].rchild);
//		printf("Case %d:\n",i);
//		PreOrderTraverse(t, 1);
//		printf("\n");
//		InOrderTraverse(t, 1);
//		printf("\n");
//		PostOrderTraverse(t, 1);
//		printf("\n");
//	}
//	return 0;
//}