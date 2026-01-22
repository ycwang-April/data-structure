////A
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	while (gets_s(s) != NULL)
//	{
//		int len = strlen(s);
//		for (int i=0;i<len/2-1;i++)
//			for (int j = 0; j < len / 2 - 1 - i; j++)
//			{
//				if (s[j] > s[j + 1])
//				{
//					char temp = s[j];
//					s[j] = s[j + 1];
//					s[j + 1] = temp;
//				}
//			}
//		if (len % 2 == 0)
//		{
//			for (int i = len / 2; i < len; i++)
//				printf("%c", s[i]);
//		}
//		else
//		{
//			for (int i = len / 2 + 1; i < len; i++)
//				printf("%c", s[i]);
//			printf("%c", s[len / 2]);
//		}
//		for (int i = 0; i < len / 2; i++)
//			printf("%c", s[i]);
//		printf("\n");
//	}
//	return 0;
//}

//B
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node{
//	int data;
//	struct node* next;
//}NODE,*List;
//void InitList(List* l)
//{
//	NODE* p;
//	p = (NODE*)malloc(sizeof(NODE));
//	if (!p)
//		exit(-1);
//	p->next = NULL;
//	*l = p;
//}
//void InsertList(List* l,int n)
//{
//	NODE* p, * q;
//	q = *l;
//	int num;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &num);
//		p = (NODE*)malloc(sizeof(NODE));
//		if (!p)
//			exit(-1);
//		p->data = num;
//		p->next = NULL;
//		q->next = p;
//		q = p;
//	}
//}
//void bubblesort(List l, int n)
//{
//	NODE* p, * q;
//	for (int i = 0; i < n - 1; i++)
//	{
//		q = l->next;
//		p = q->next;
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (q->data > p->data)
//			{
//				int temp = q->data;
//				q->data = p->data;
//				p->data = temp;
//			}
//			q = q->next;
//			p = q->next;
//		}
//	}
//}
//void PrintList(List l)
//{
//	NODE* p;
//	for (p = l->next; p->next; p = p->next)
//		printf("%d ", p->data);
//	printf("%d\n", p->data);
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		List l;
//		InitList(&l);
//		InsertList(&l, n);
//		bubblesort(l, n);
//		PrintList(l);
//	}
//	return 0;
//}

//C
//#include <stdio.h>
//void Qsort(int a[], int k)
//{
//	int low = 1;
//	int high = k - 1;
//	int pivot = a[k - 1];
//	while (low < high)
//	{
//		while (low < high && a[low] < pivot) low++;
//		a[high] = a[low];
//		while (low < high && a[high] >= pivot) high--;
//		a[low] = a[high];
//	}
//	a[low] = pivot;
//	for (int i = 1; i < k; i++)
//	{
//		if (i == k - 1)
//			printf("%d\n", a[i]);
//		else
//			printf("%d ", a[i]);
//	}
//}
//int main()
//{
//	int k = 1;
//	int a[10000] = { 0 };
//	int num;
//	while (scanf("%d", &num) != EOF)
//	{
//		if (num == -1)
//		{
//			Qsort(a, k);
//			k = 1;
//		}
//		else
//			a[k++] = num;
//	}
//	return 0;
//}


//D
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int cnt = 0;
//		int key, n;
//		scanf("%d%d", &key, &n);
//		int* a;
//		a = (int*)malloc(sizeof(int) * n);
//		if (!a)
//			exit(-1);
//		for (int i = 0; i < n; i++)
//			scanf("%d", &a[i]);
//		int low = 0, high = n - 1;
//		int mid;
//		int found = 0;
//		while (low <= high)
//		{
//			mid = (low + high) / 2;
//			cnt++;
//			if (a[mid] == key)
//			{
//				found = 1;
//				break;
//			}
//			else if (a[mid] < key)
//				low = mid + 1;
//			else
//				high = mid - 1;
//		}
//		if (found)
//			printf("%d\n", cnt);
//		else
//			printf("Not Found\n");
//	}
//	return 0;
//}