/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1050.cc
*   创 建 者：D
*   创建日期：2019年11月30日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

char buf1[10001], sign[256];

int readio(char* buf)
{
	char c;
	int num = 0;
	while (scanf("%c", &c), c != '\n')
	{
		buf[num++] = c;
	}
	return num;
}

void intosign()
{
	char c;
	while (scanf("%c", &c), c != '\n')
	{
		sign[(unsigned int)c] = 1;
	}
}

int main()
{
	int N = readio(buf1);
	intosign();
	for (int i = 0; i < N; ++i)
	{
		if (sign[(unsigned int)buf1[i]])
			buf1[i] = 0;
	}
	for (int i = 0; i < N; ++i)
	{
		if (buf1[i])
			printf("%c", buf1[i]);
	}
	return 0;
}
