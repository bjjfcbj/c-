/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1042.cc
*   创 建 者：D
*   创建日期：2019年11月20日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int order[54], torder[54], card[54];

void copy(int* a, int*b, int len)
{
	for (int i = 0; i < len; ++i)
	{
		b[i] = a[i];
	}
}

void printcard(int a)
{
	switch (a / 13)
	{
	case 0:
		printf("S%d", a % 13 + 1);
		break;
	case 1:
		printf("H%d", a % 13 + 1);
		break;
	case 2:
		printf("C%d", a % 13 + 1);
		break;
	case 3:
		printf("D%d", a % 13 + 1);
		break;
	case 4:
		printf("J%d", a % 13 + 1);
		break;
	}
}

int main()
{
	int N, temp;
	scanf("%d", &N);
	for (int i = 0; i < 54; ++i)
	{
		card[i] = i;
	}
	for (int i = 0; i < 54; ++i)
	{
		scanf("%d", &temp);
		order[i] = temp - 1;
	}
	while (N--)
	{
		for (int i = 0; i < 54; ++i)
		{
			torder[order[i]] = card[i];
		}
		copy(torder, card, 54);
	}
	printcard(card[0]);
	for (int i = 1; i < 54; ++i)
	{
		printf(" ");
		printcard(card[i]);
	}
	return 0;
}
