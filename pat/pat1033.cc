/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1033.cc
*   创 建 者：D
*   创建日期：2019年10月22日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int dis;
	float pri;

	node() = default;
	node(int a, float b): dis(a), pri(b) {}

	bool operator<(node& n)
	{
		return this->dis < n.dis;
	}
};

int main()
{
	int C, D, L, N, d;
	float P;
	vector<node> vec;
	scanf("%d %d %d %d", &C, &D, &L, &N);
	while (N--)
	{
		scanf("%f %d", &P, &d);
		vec.push_back(node(d, P));
	}
	sort(vec.begin(), vec.end());
	/*
	 *
	 */
	return 0;
}
