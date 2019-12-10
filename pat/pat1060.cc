/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1060.cc
*   创 建 者：D
*   创建日期：2019年12月09日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

char buf1[110], buf2[110], res1[110], res2[110];
int lg1, lg2;

void deal(char *a, char* b, int N, int* lg)
{
	int pos = -1, fnz = -1, len = strlen(a);
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == '.')
			pos = i;
		if (fnz == -1 && a[i] > '0')
			fnz = i;
	}
	if (pos == -1)pos = len;
	*lg = pos > fnz ? (pos - fnz) : (pos - fnz + 1);
	if (fnz == -1)
	{
		for (int i = 0; i < N; ++i)
		{
			b[i] = '0';
		}
		b[N] = 0;
		*lg = 0;
	}
	else
	{
		for (int i = 0, j = fnz; i < N; ++i, ++j)
		{
			if (j < len)
			{
				if (a[j] != '.')
					b[i] = a[j];
				else
					--i;
			}
			else
				b[i] = '0';
		}
		b[N] = 0;
	}
}

int main()
{
	int N;
	scanf("%d %s %s", &N, buf1, buf2);
	deal(buf1, res1, N, &lg1);
	deal(buf2, res2, N, &lg2);
	if (!strcmp(res1, res2) && lg1 == lg2)
	{
		printf("YES 0.%s", res1);
		printf("*10^%d", lg1);
	}
	else
	{
		printf("NO 0.%s", res1);
		printf("*10^%d", lg1);
		printf(" 0.%s", res2);
		printf("*10^%d", lg2);
	}
	return 0;
}
