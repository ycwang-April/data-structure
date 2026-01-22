//D
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define INFINITY 142857
//typedef struct HFNode {
//	int weight;
//	int parent, lchild, rchild;
//}HFNODE,*HuffmanTree;
//typedef char** HuffmanCode;
//void SelectMinTwo(HuffmanTree ht, int n, int* s1, int* s2)
//{
//	int w1, w2;
//	int x1, x2;
//	w1 = w2 = INFINITY;
//	x1 = x2 = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!ht[i].parent)
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
//HuffmanTree CreateHuffmanTree(int n)
//{
//	HuffmanTree ht;
//	ht = (HFNODE*)malloc(sizeof(HFNODE) * (2 * n));
//	if (!ht)
//		exit(-1);
//	for (int i = 1; i < 2*n; i++)
//	    ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &ht[i].weight);
//	for (int i = n + 1; i < 2 * n; i++)
//	{
//		int s1, s2;
//		SelectMinTwo(ht, i-1 , &s1, &s2);
//		ht[s1].parent = ht[s2].parent = i;
//		ht[i].lchild = s1;
//		ht[i].rchild = s2;
//		ht[i].weight = ht[s1].weight + ht[s2].weight;
//	}
//	return ht;
//}
//HuffmanCode CreateHuffmanCode(HuffmanTree ht, int n)
//{
//	HuffmanCode hc;
//	hc = (char**)malloc(sizeof(char*) * (n + 1));
//	if (!hc)
//		exit(-1);
//	char* cd;
//	cd = (char*)malloc(sizeof(char) * n);
//	if (!cd)
//		exit(-1);
//	cd[n - 1] = '\0';
//	for (int i = 1; i <= n; i++)
//	{
//		int start = n - 1;
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
//		HuffmanCode hc;
//		float ave = 0;
//		ht = CreateHuffmanTree(n);
//		hc = CreateHuffmanCode(ht, n);
//		for (int i = 1; i <= n; i++)
//			ave += strlen(hc[i]);
//		ave /= n;
//		printf("%.3f\n", ave);
//		free(hc);
//		free(ht);
//	}
//	return 0;
//}


//A
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef char ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE,*BiTree;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;
//}
//void CreateBiTree(BiTree *t,char** str)
//{
//	char ch;
//	ch = **str;
//	(*str)++;
//	if (ch == '#')
//		*t = NULL;
//	else
//	{
//		*t = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!t)
//			exit(-1);
//		(*t)->data = ch;
//		CreateBiTree(&(*t)->lchild, str);
//		CreateBiTree(&(*t)->rchild, str);
//	}
//}
//int BiTreeDepth(BiTree t)
//{
//	if (t == NULL)
//		return 0;
//	int m, n;
//	m = BiTreeDepth(t->lchild) + 1;
//	n = BiTreeDepth(t->rchild) + 1;
//	if (m > n)
//		return m;
//	else
//		return n;
//}
//int main()
//{
//	int t;
//	scanf("%d%*c", &t);
//	while (t--)
//	{
//		BiTree t;
//		initBiTree(&t);
//		char s[100] = { 0 };
//		gets_s(s);
//		char* str = s;
//		CreateBiTree(&t, &str);
//		int lans = BiTreeDepth(t->lchild);
//		int rans = BiTreeDepth(t->rchild);
//		int ans=lans+rans;
//		printf("%d\n", ans);
//	}
//	return 0;
//}



//B
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//typedef struct {
//    int max[3]; // R, G, B
//    int min[3];
//} NodeDP;
//
//int max3(int a, int b, int c) {
//    int max = a;
//    if (b > max) max = b;
//    if (c > max) max = c;
//    return max;
//}
//
//int min3(int a, int b, int c) {
//    int min = a;
//    if (b < min) min = b;
//    if (c < min) min = c;
//    return min;
//}
//
//void dfs(char s[], int* pos, NodeDP* dp)
//{
//    char c = s[(*pos)++];
//    if (c == '0')
//    {
//        dp->max[0] = dp->max[2] = 0;
//        dp->max[1] = 1;
//        dp->min[0] = dp->min[2] = 0;
//        dp->min[1] = 1;
//        return;
//    }
//
//    NodeDP ldp, rdp;
//    if (c == '1')
//    {
//        dfs(s, pos, &ldp);
//
//        for (int color = 0; color < 3; color++)
//        {
//            int current_green = (color == 1) ? 1 : 0;
//            int max_sum = -1;
//            int min_sum = 142857;
//            for (int child_color = 0; child_color < 3; child_color++)
//            {
//                if (child_color == color)    continue;
//                if (ldp.max[child_color] > max_sum)
//                    max_sum = ldp.max[child_color];
//                if (ldp.min[child_color] < min_sum)
//                    min_sum = ldp.min[child_color];
//            }
//            dp->max[color] = current_green + max_sum;
//            dp->min[color] = current_green + min_sum;
//        }
//    }
//    else if (c == '2') 
//    {
//        dfs(s, pos, &ldp);
//        dfs(s, pos, &rdp);
//        // 处理两个子节点的情况
//        for (int color = 0; color < 3; color++) {
//            int current_green = (color == 1) ? 1 : 0;
//            int max_total = -1;
//            int min_total = INT_MAX;
//            for (int left_color = 0; left_color < 3; left_color++) {
//                if (left_color == color) continue;
//                for (int right_color = 0; right_color < 3; right_color++) {
//                    if (right_color == color || right_color == left_color) continue;
//                    int sum_max = ldp.max[left_color] + rdp.max[right_color];
//                    int sum_min = ldp.min[left_color] + rdp.min[right_color];
//                    if (sum_max > max_total) {
//                        max_total = sum_max;
//                    }
//                    if (sum_min < min_total) {
//                        min_total = sum_min;
//                    }
//                }
//            }
//            dp->max[color] = current_green + max_total;
//            dp->min[color] = current_green + min_total;
//        }
//    }
//}
//
//int main() {
//    char s[10010];
//    while (scanf("%s",s) == 1) {
//        int pos = 0;
//        NodeDP root_dp;
//        dfs(s, &pos, &root_dp);
//        int max_green = max3(root_dp.max[0], root_dp.max[1], root_dp.max[2]);
//        int min_green = min3(root_dp.min[0], root_dp.min[1], root_dp.min[2]);
//        printf("%d %d\n", max_green, min_green);
//    }
//    return 0;
//}


//C
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	int parent, lchild, rchild;
//	int weight;
//	ElementType data;
//}BiNode,*BiTree;
//int SelectMax(int a, int b, int c,int d)
//{
//	int max,max1, max2;
//	max1 = a > b ? a : b;
//	max2 = c > d ? c : d;
//	max = max1 > max2 ? max1 : max2;
//	return max;
//}
//int MaxWeight(BiTree t, int n,int root)
//{
//	if (root == 0 || root > n)
//		return 0;
//	int a = t[root].weight;
//	int b = t[root].weight + MaxWeight(t, n, t[root].lchild);
//	int c=t[root].weight + MaxWeight(t, n, t[root].rchild);
//	int d = t[root].weight + MaxWeight(t, n, t[root].lchild) + MaxWeight(t, n, t[root].rchild);
//	return SelectMax(a, b, c, d);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	BiTree t;
//	int root_index = 0;
//	t = (BiTree)malloc(sizeof(BiNode) * (n + 1));
//	if (!t)
//		exit(-1);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &t[i].weight);
//		t[i].parent = t[i].lchild = t[i].rchild = 0;
//		t[i].data = i;
//	}
//	for (int i = 1; i <= n - 1;i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if (t[a].lchild == 0)
//			t[a].lchild = b;
//		else
//			t[a].rchild = b;
//		t[b].parent = a;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (t[i].parent == 0)
//		{
//			root_index = i;
//			break;
//		}
//	}
//	int ans=MaxWeight(t, n, root_index);
//	printf("%d", ans);
//	return 0;
//}