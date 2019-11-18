/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1040.cc
*   创 建 者：D
*   创建日期：2019年11月18日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

char buf[1001];

int deal(int pos, int len)
{
	int temp = 0;
	for (int i = 0; i < pos && pos + i < len; ++i)
	{
		if (buf[pos + i] == buf[pos - 1 - i])temp += 2;
		else break;
	}
	return temp;
}

int cdeal(int pos, int len)
{
	int temp = 1;
	for (int i = 1; i < pos && pos + i < len; ++i)
	{
		if (buf[pos + i] == buf[pos - i])temp += 2;
		else break;
	}
	return temp;
}

int main()
{
	char c;
	int len = 0, max = -1, temp;
	while (scanf("%c", &c) != EOF)
	{
		buf[len++] = c;
	}
	for (int i = 0; i < len; ++i)
	{
		temp = deal(i, len);
		max = max < temp ? temp : max;
		temp = cdeal(i, len);
		max = max < temp ? temp : max;
	}
	printf("%d\n", max);
	return 0;
}
