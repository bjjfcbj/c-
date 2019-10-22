/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1032.cc
*   创 建 者：D
*   创建日期：2019年10月21日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int data[100010], sign[100010];

void deal(int a1, int a2)
{
	for (int i = a1; data[i] != -1; i = data[i])sign[i] = 1;
	for (; a2 != -1 &&  !sign[a2]; a2 = data[a2]);
	if (a2 == -1)printf("-1\n");
	else printf("%05d\n", a2);
}

int main()
{
	int adr1, adr2, N, i, j;
	char k;
	scanf("%d %d %d", &adr1, &adr2, &N);
	memset(data, 0, 100010);
	memset(sign, 0, 100010);
	while (N--)
	{
		scanf("%d %c %d", &i, &k, &j);
		data[i] = j;
	}
	deal(adr1, adr2);
	return 0;
}
