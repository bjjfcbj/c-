/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1041.cc
*   创 建 者：D
*   创建日期：2019年11月19日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int sign[10001], buf[100001];

int main()
{
	memset(sign, 0, sizeof(sign));
	int N, i = 0, temp;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &temp);
		buf[i++] = temp;
		sign[temp] += 1;
	}
	for (int j = 0; j < i; ++j)
	{
		if (sign[buf[j]] == 1)
		{
			printf("%d", buf[j]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
