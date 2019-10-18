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

long sone[NUM];

using namespace std;

int main()
{
	int N, s1 = 0, len = 0, med = 0, i = 0;
	long temp;
	scanf("%d", &N);
	len += N;
	while (N--)
	{
		scanf("%ld", &temp);
		sone[s1++] = temp;
	}
	scanf("%d", &N);
	len += N;
	len = (len + 1) / 2;
	while (N--)
	{
		scanf("%ld", &temp);
		while (i < s1 && sone[i] < temp)
		{
			med += 1;
			if (med == len)
			{
				printf("%ld\n", sone[i]);
				break;
			}
			i += 1;
		}
		med += 1;
		if (med == len)
		{
			printf("%ld\n", temp);
			break;
		}
	}
	while (med < len)
	{
		med += 1;
		if (med == len)
		{
			printf("%ld\n", sone[i]);
			break;
		}
		i += 1;
	}
	return 0;
}
