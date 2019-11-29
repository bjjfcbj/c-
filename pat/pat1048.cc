/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1048.cc
*   创 建 者：D
*   创建日期：2019年11月29日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int vec[100001];

int cmp(const void* a, const void* b)
{
	int c = *(const int*)a;
	int d = *(const int*)b;
	if (c < d)return -1;
	if (c > d)return 1;
	return 0;
}

int main()
{
	int N, M, temp, num = 0, sign = 0, beg = 0;
	scanf("%d %d", &N, &M);
	while (N--)
	{
		scanf("%d", &temp);
		vec[num++] = temp;
	}
	qsort(vec, num, sizeof(int), cmp);
	while (vec[beg] + vec[num] > M)
	{
		++beg;
	}
	for (int i = beg; i < num; ++i)
	{
		while (vec[i] + vec[num - 1] > M)--num;
		for (int j = num - 1; j > i; --j)
		{
			if (vec[i] + vec[j] < M)break;
			if (vec[i] + vec[j] == M)
			{
				sign = 1;
				printf("%d %d\n", vec[i], vec[j]);
				break;
			}
		}
		if (sign)break;
	}
	if (!sign)
		printf("No Solution\n");
	return 0;
}
