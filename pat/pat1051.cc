/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1051.cc
*   创 建 者：D
*   创建日期：2019年12月01日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int buf[1001];

void deal(int* buf, int num, int lim)
{
	int sign = buf[0], size = 1;
	for (int i = 1; i < num; ++i)
	{
		if (buf[i] > sign)
		{
			sign = buf[i];
			size = 1;
		}
		else
		{
			if (buf[i] > buf[i - 1])
			{
				printf("NO\n");
				return;
			}
			else
			{
				size += 1;
				if (size > lim)
				{
					printf("NO\n");
					return;
				}
			}
		}
	}
	printf("YES\n");
}

int main()
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	while (K--)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", buf + i);
		}
		deal(buf, N, M);
	}
	return 0;
}
