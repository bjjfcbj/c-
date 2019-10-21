/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1031.cc
*   创 建 者：D
*   创建日期：2019年10月21日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

char buf[81];

using namespace std;


int main()
{
	int n, m;
	scanf("%s", buf);
	n = (strlen(buf) + 2) / 3;
	m = strlen(buf) - 2 * n;
	for (int i = 0; i < n - 1; ++i)
	{
		printf("%c", buf[i]);
		for (int j = 0; j < m; ++j)
		{
			printf(" ");
		}
		printf("%c\n", buf[strlen(buf) - i - 1]);
	}
	for (int i = n - 1; i < n + m + 1; ++i)
	{
		printf("%c", buf[i]);
	}
	printf("\n");
	return 0;
}
