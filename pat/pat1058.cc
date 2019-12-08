/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1058.cc
*   创 建 者：D
*   创建日期：2019年12月08日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned int a, b, c, e, f, d, temp;
	scanf("%d.%d.%d %d.%d.%d\n", &a, &b, &c, &d, &e, &f);
	b += (c + f) / 29;
	c = (c + f) % 29;
	a += (b + e) / 17;
	b = (b + e) % 17;
	a = (a + d);
	printf("%d.%d.%d\n", a, b, c);
	return 0;
}
