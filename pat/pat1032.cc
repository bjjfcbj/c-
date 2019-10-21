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

int sign[100001];

int main()
{
	int adr1, adr2, N, i, j, res = 100000;
	char k;
	memset(sign, 0, 100000);
	scanf("%d %d %d", &adr1, &adr2, &N);
	sign[adr1] = 1;
	sign[adr2] = 1;
	while (N--)
	{
		scanf("%d %c %d", &i, &k, &j);
		if (j != -1)sign[j] += 1;
		if (sign[j] == 2)res = j;
	}
	if (res != 100000)printf("%05d\n", res);
	else printf("-1\n");
	return 0;
}
