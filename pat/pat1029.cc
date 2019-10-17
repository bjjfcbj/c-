/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1029.cc
*   创 建 者：D
*   创建日期：2019年10月16日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

#define NUM 200001

long sone[NUM], stwo[NUM];

using namespace std;

int deal(long *s1, long *s2, int s1_s, int len1, int s2_s, int len2, int r, int l)
{
}

int main()
{
	int N, s1 = 0, s2 = 0, right = 0, left = 0;
	long temp;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%ld", &temp);
		sone[s1++] = temp;
	}
	scanf("%d", &N);
	while (N--)
	{
		scanf("%ld", &temp);
		stwo[s2++] = temp;
	}
	return 0;
}
