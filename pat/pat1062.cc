/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1062.cc
*   创 建 者：D
*   创建日期：2019年12月11日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	char id[9];
	int virtue, talent, sign;
} node;

int cmp(const void* c, const void* d)
{
	node* a = (node*)c;
	node* b = (node*)d;
	if (a->sign == b->sign)
	{
		if (a->virtue + a->talent == b->virtue + b->talent)
		{
			if (a->virtue == b->virtue)
			{
				return strcmp(a->id, b->id);
			}
			else
				return b->virtue - a->virtue;
		}
		else
			return (b->virtue + b->talent) - (a->virtue + a->talent);
	}
	else
		return a->sign - b->sign;
}

void deal(node* list, int a, int H)
{
	if (list[a].virtue >= H)
	{
		if (list[a].talent >= H)
			list[a].sign = 1;
		else
			list[a].sign = 2;
	}
	else
	{
		if (list[a].virtue >= list[a].talent)
			list[a].sign = 3;
		else
			list[a].sign = 4;
	}
}

int main()
{
	int N, L, H, i, j;
	node list[100010];
	scanf("%d %d %d", &N, &L, &H);
	for (i = 0, j = 0; i < N; ++i)
	{
		scanf("%s %d %d", list[j].id, &list[j].virtue, &list[j].talent);
		if (list[j].virtue >= L && list[j].talent >= L)
		{
			deal(list, j, H);
			++j;
		}
	}
	qsort(list, j, sizeof(node), cmp);
	printf("%d\n", j);
	for (int k = 0; k < j; ++k)
	{
		printf("%s %d %d\n", list[k].id, list[k].virtue, list[k].talent);
	}
	return 0;
}
