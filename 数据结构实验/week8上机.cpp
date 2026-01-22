//D
#include <stdio.h>
#include <string.h>
void getNext(char t[], int next[], int len)
{
	int j = 0;
	next[0] = 0;
	for (int i = 1; i < len; i++)
	{
		while (j > 0 && t[i] != t[j])
			j = next[j - 1];
		if (t[i] == t[j])
			j++;
		next[i] = j;
	}
}
int KMP_count(char s[], char t[], int next[],int len1,int len2)
{
	int cnt = 1;
	int i = 0, j = 0;
	while (i<len1 && j< len2)
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
				j = next[j - 1];
			else
				i++;
			cnt++;
		}
	}
	if (j >= len2)
		return cnt;
	else
		return 0;
}
int main()
{
	char s[500] = { 0 },t[100] = { 0 };
	int next[500] = { 0 };
	gets_s(s);
	gets_s(t);
	int len1 = strlen(s);
	int len2 = strlen(t);
	getNext(t, next, len2);
	printf("%d", KMP_count(s, t, next, len1, len2));
	return 0;
}

//E
//#include <stdio.h>
//#include <string.h>
//typedef struct {
//	int cnt;
//	int pos;
//}info;
//void getNext(char t[], int next[], int len)
//{
//	int j = 0;
//	next[0] = 0;
//	for (int i = 1; i < len; i++)
//	{
//		while (j > 0 && t[i] != t[j])
//			j = next[j - 1];
//		if (t[i] == t[j])
//			j++;
//		next[i] = j;
//	}
//}
//info KMP_count(char s[], char t[], int next[], int len1, int len2)
//{
//	info e;
//	int cnt = 1;
//	int i = 0, j = 0;
//	while (i < len1 && j < len2)
//	{
//		if (s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			if (j != 0)
//				j = next[j - 1];
//			else
//				i++;
//			cnt++;
//		}
//	}
//	if (j >= len2)
//		e.cnt = cnt;
//	else
//		e.cnt = 0;
//	e.pos = i - j;
//	return e;
//}
//int main()
//{
//	char s[500] = { 0 }, t[100] = { 0 };
//	int next[500] = { 0 };
//	gets_s(s);
//	gets_s(t);
//	int len1 = strlen(s);
//	int len2 = strlen(t);
//	getNext(t, next, len2);
//	info e = KMP_count(s, t, next, len1, len2);
//	printf("%d %d",e.cnt,e.pos+1);
//	return 0;
//}

//A
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	gets_s(s);
//	int len = strlen(s);
//	int depth = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '(')
//			depth++;
//		else
//			break;
//	}
//	printf("%d", depth);
//	return 0;
//}

//B
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int des_dep;
//	char str[100] = { 0 };
//	gets_s(str);
//	scanf("%d", &des_dep);
//	int len = strlen(str);
//	char ch;
//	int depth = 0;
//	for (int i = 0; i < len; i++)
//	{
//		ch = str[i];
//		if (ch == '(')
//			depth++;
//		else if (ch == ')')
//			depth--;
//		else
//		{
//			if (depth == des_dep)
//				printf("%c ", ch);
//		}
//	}
//	return 0;
//}

//C
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	char Element[100][20] = { 0 };
//	int Element_cnt = 0;
//	gets_s(s);
//	int len = strlen(s);
//	int index[100] = { 0 };
//	int index_cnt = 0;
//	int maxdepth = 0;
//	int depth = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '(')
//		{
//			depth++;
//			if (depth > maxdepth)
//				maxdepth = depth;
//		}
//		else if (s[i] == ')')
//			depth--;
//	}
//	int cnt = 1;
//	while(cnt <= maxdepth)
//	{
//		depth = 0;
//		for (int i = 1; i < len - 1; i++)
//		{
//			if (s[i] == '(')
//				depth++;
//			else if (s[i] == ')')
//				depth--;
//			if ((s[i]=='('||s[i]==')') && depth ==cnt)
//				index[index_cnt++] = i;
//			else if (s[i] == ',' && depth == cnt)
//				index[index_cnt++] = i;
//		}
//		index[index_cnt++] = len - 1;
//		for (int i = 0; i < index_cnt - 1; i++)
//		{
//			strncpy(Element[Element_cnt++], s + index[i] + 1, index[i + 1] - index[i] - 1);
//		}
//		s[]
//	}
//	printf("(");
//	for (int i = Element_cnt - 1; i >0 ; i--)
//	{
//		printf("%s,",Element[i]);
//	}
//	printf("%s)", Element[0]);
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char s[100] = { 0 };
//	gets_s(s);
//	int len = strlen(s);
//	for (int i = len-1; i >=0; i--)
//	{
//		if (s[i] == '(')
//			printf(")");
//		else if (s[i] == ')')
//			printf("(");
//		else
//			printf("%c", s[i]);
//	}
//	return 0;
//}