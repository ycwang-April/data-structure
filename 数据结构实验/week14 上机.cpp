//A
//#include <stdio.h>
//#include <stdlib.h>
//int BinarySearch(int arr[], int num,int n)
//{
//	int cnt = 0;
//	int low = 0, high = n - 1;
//	while (low <= high)
//	{
//		int mid = (low + high) / 2;
//		cnt++;
//		if (arr[mid] == num)
//			break;
//		else if (arr[mid] < num)
//			low = mid + 1;
//		else
//			high = mid - 1;
//	}
//	return cnt;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		int C = 0;
//		int* arr;
//		arr = (int*)malloc(sizeof(int*) * n);
//		for (int i = 0; i < n; i++)
//			scanf("%d", &arr[i]);
//		for (int i = 0; i < n; i++)
//			C += BinarySearch(arr, arr[i], n);
//		float res = (float)C / n;
//		printf("%.2f\n", res);
//	}
//	return 0;
//}

//B
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[101] = { 0 };
//	while (gets(s) != NULL)
//	{
//		char max_char = 'A';
//		int len = strlen(s);
//		for (int i = 0; i < len; i++)
//		{
//			if (s[i] > max_char)
//				max_char = s[i];
//		}
//		for (int i = 0; i < len; i++)
//		{
//			printf("%c", s[i]);
//			if (s[i] == max_char)
//				printf("(max)");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//C
//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElementType;
//typedef struct BiNode{
//	ElementType data;
//	struct BiNode* lchild, * rchild;
//}BiNODE,*BiTree;
//void initBiTree(BiTree* t)
//{
//	*t = NULL;;
//}
//void InsertBST(BiTree* t, ElementType e)
//{
//	if (*t == NULL)
//	{
//		BiNODE* p;
//		p = (BiNODE*)malloc(sizeof(BiNODE));
//		if (!p)
//			exit(-1);
//		*t = p;
//		(*t)->data = e;
//		(*t)->lchild = (*t)->rchild = NULL;
//	}
//	else if (e < (*t)->data)
//		InsertBST(&(*t)->lchild, e);
//	else
//		InsertBST(&(*t)->rchild, e);
//}
//int SearchBST(BiTree t, ElementType e)
//{
//	if (t->data == e)
//		return 1;
//	else if (e < t->data)
//		return SearchBST(t->lchild, e) + 1;
//	else
//		return SearchBST(t->rchild, e) + 1;
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		BiTree t;
//		initBiTree(&t);
//		for (int i = 0; i < n; i++)
//		{
//			ElementType e;
//			scanf("%d", &e);
//			InsertBST(&t, e);
//		}
//		int Search_num;
//		scanf("%d", &Search_num);
//		int ans = SearchBST(t, Search_num);
//		printf("%d\n", ans);
//	}
//	return 0;
//}


//D
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef struct {
//	int Code;
//	char book[30];
//}ElementType;
//typedef struct {
//	ElementType* data;
//	int size;
//}List;
//void BinarySearchList(List l, int key)
//{
//	int low = 0, high = l.size - 1;
//	int found = 0;
//	while (low <= high)
//	{
//		int mid = (low + high) / 2;
//		if (key == l.data[mid].Code)
//		{
//			found = 1;
//			printf("%s\n", l.data[mid].book);
//			break;
//		}
//		else if (key < l.data[mid].Code)
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//	if (found == 0)
//		printf("Not Found\n");
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	List l;
//	l.data = (ElementType*)malloc(sizeof(ElementType) * n);
//	if (!l.data)
//		exit(-1);
//	l.size = n;
//	for (int i = 0; i < n; i++)
//		scanf("%d%*c%s%*c", &l.data[i].Code, l.data[i].book);
//	int m;
//	scanf("%d",&m);
//	while (m--)
//	{
//		int key;
//		scanf("%d", &key);
//		BinarySearchList(l, key);
//	}
//	return 0;
//}