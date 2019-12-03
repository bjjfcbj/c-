/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1052.cc
*   创 建 者：D
*   创建日期：2019年12月02日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int adr;
	int key;
	int next;

	bool operator<(node& n)
	{
		return key < n.key;
	}
};

node buf1[100010];

int main()
{
	int N, adr, a, b, c, temp;
	vector<node> buf;
	scanf("%d %d", &N, &adr);
	temp = N;
	while (N--)
	{
		scanf("%d %d %d", &a, &b, &c);
		buf1[a].adr = a;
		buf1[a].key = b;
		buf1[a].next = c;
	}
	for (; adr != -1; adr = buf1[adr].next)
	{
		buf.push_back(buf1[adr]);
	}
	sort(buf.begin(), buf.end());
	temp = buf.size();
	if (temp)
	{
		printf("%d %05d\n", temp, buf[0].adr);
		for (int i = 0; i < temp - 1; ++i)
		{
			printf("%05d %d %05d\n", buf[i].adr, buf[i].key, buf[i + 1].adr);
		}
		printf("%05d %d %d\n", buf[temp - 1].adr, buf[temp - 1].key, -1);
	}
	else
	{
		printf("0 -1\n");
	}
	return 0;
}
