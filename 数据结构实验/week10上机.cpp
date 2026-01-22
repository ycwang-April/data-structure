//A
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct {
//	int parent;
//	int lchild, rchild;
//	ElementType data;
//}BiNODE,*BiTree;
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	BiTree t;
//	t = (BiNODE*)malloc(sizeof(BiNODE) * (n+1));
//	for (int i = 1; i <= n; i++)
//	{
//		int l, r;
//		t[i].data = i;
//		scanf("%d%d",&l,&r);
//		t[i].lchild = l;
//		t[i].rchild = r;
//		if (l != 0)
//			t[l].parent = i;
//		if (r != 0)
//			t[r].parent = i;
//	}
//	t[1].parent = -1;
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int current=i;
//		int cnt = 1 ;
//		while (t[current].parent != -1)
//		{
//			cnt++;
//			current = t[current].parent;
//		}
//		if (cnt > max)
//			max = cnt;
//	}
//	printf("%d %d",max, t[n].lchild);
//	return 0;
//}

//B
//#include <stdio.h>
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
//void CreateBiTree(BiTree* t)
//{
//	char ch;
//	ch = getchar();
//	if (ch == '#')
//		*t = NULL;
//	else
//	{
//		*t = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!t)
//			exit(-1);
//		(*t)->data = ch;
//		CreateBiTree(&(*t)->lchild);
//		CreateBiTree(&(*t)->rchild);
//	}
//}
//void InOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		InOrderTraverse(t->lchild);
//		putchar(t->data);
//		InOrderTraverse(t->rchild);
//	}
//}
//int main()
//{
//	BiTree t;
//	initBiTree(&t);
//	CreateBiTree(&t);
//	InOrderTraverse(t);
//}

//C
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//TreeNode* createNode(int data) {
//    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//    newNode->data = data;
//    newNode->left = newNode->right = NULL;
//    return newNode;
//}
//TreeNode* insert(TreeNode* root, int data) {
//    if (root == NULL) {
//        return createNode(data);
//    }
//    if (data < root->data) {
//        root->left = insert(root->left, data);
//    }
//    else if (data > root->data) {
//        root->right = insert(root->right, data);
//    }
//    return root;
//}
//void search(TreeNode* root, int target, int* count) {
//    if (root == NULL) {
//        return;
//    }
//    (*count)++;
//    if (*count > 1) {
//        printf("->");
//    }
//    printf("%d", root->data);
//    if (target < root->data) {
//        search(root->left, target, count);
//    }
//    else if (target > root->data) {
//        search(root->right, target, count);
//    }
//}
//void freeTree(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    freeTree(root->left);
//    freeTree(root->right);
//    free(root);
//}
//int main() {
//    int T;
//    scanf("%d", &T);
//
//    while (T--) {
//        TreeNode* root = NULL;
//        int num;
//        while (1) {
//            scanf("%d", &num);
//            if (num == -1) {
//                break;
//            }
//            root = insert(root, num);
//        }
//        int target;
//        scanf("%d", &target);
//        int count = 0;
//        search(root, target, &count);
//        printf("\n%d\n", count);
//        freeTree(root);
//    }
//    return 0;
//}


//D
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char ElementType;
//typedef struct BiNode {
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE,*BiTree;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;
//}
//BiTree pres_ins_CreateBiTree(char pres[],int i,char ins[],int j, int n)
//{
//	BiNODE* t = NULL;
//	if (n <= 0)
//		return NULL;
//	char d = pres[i];
//	t = (BiNODE*)malloc(sizeof(BiNODE));
//	t->data = d;
//	t->lchild = t->rchild = NULL;
//	int p = 0;
//	for (int a = j; a < j+n; a++)
//	{
//		if (ins[a] == d)
//		{
//			p = a;
//			break;
//		}
//	}
//	int k = p - j;
//	t->lchild = pres_ins_CreateBiTree(pres, i + 1, ins, j, k);
//	t->rchild = pres_ins_CreateBiTree(pres, i + k + 1, ins, p + 1,n - k - 1);
//	return t;
//}
//void PostOrderTraverse(BiTree t)
//{
//	if (t)
//	{
//		PostOrderTraverse(t->lchild);
//		PostOrderTraverse(t->rchild);
//		putchar(t->data);
//	}
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		BiTree t;
//		initBiTree(&t);
//		getchar();
//		char pres[101] = { 0 };
//		char ins[101] = { 0 };
//		scanf("%s%s", pres, ins);
//		t=pres_ins_CreateBiTree(pres, 0, ins, 0, strlen(pres));
//		PostOrderTraverse(t);
//		printf("\n");
//	}
//	return 0;
//}