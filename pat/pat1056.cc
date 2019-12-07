/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1056.cc
*   创 建 者：D
*   创建日期：2019年12月06日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int fat;
	int rank;
};

node buf[1001];
int list1[1001], list2[1001];

void deal(int *lista, int* listb, int G, int num)
{
	int max = 0, j = 0, count = num / G * G == num ? num / G : num / G + 1;
	if (num == 1)
	{
		buf[lista[0]].rank = 1;
		return;
	}
	for (int i = 0; i < num; ++i)
	{
		if (i % G == 0)
		{
			if (max)listb[j++] = max;
			max = lista[i];
		}
		else
		{
			if (buf[lista[i]].fat > buf[max].fat)
			{
				buf[max].rank = count + 1;
				max = lista[i];
			}
			else
			{
				buf[lista[i]].rank = count + 1;
			}
		}
	}
	listb[j++] = max;
	if (j)
		deal(listb, lista, G, j);
}

int main()
{
	int P, G, temp;
	scanf("%d %d", &P, &G);
	for (int i = 0; i < P; ++i)
	{
		scanf("%d", &temp);
		buf[i].fat = temp;
	}
	for (int i = 0; i < P; ++i)
	{
		scanf("%d", &temp);
		list1[i] = temp;
	}
	deal(list1, list2, G, P);
	printf("%d", buf[0].rank);
	for (int i = 1; i < P; ++i)
	{
		printf(" %d", buf[i].rank);
	}
	return 0;
}
