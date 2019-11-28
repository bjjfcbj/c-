/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1047.cc
*   创 建 者：D
*   创建日期：2019年11月28日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K, C, temp;
	char na[5] = {0};
	scanf("%d %d", &N, &K);
	vector<string> vec;
	vector<vector<string>> map(K);
	while (N--)
	{
		scanf("%s %d", na, &C);
		while (C--)
		{
			scanf("%d", &temp);
			map[temp - 1].push_back(na);
		}
	}
	for (int i = 0; i < K; ++i)
	{
		printf("%d %ld\n", i + 1, map[i].size());
		sort(map[i].begin(), map[i].end());
		for (auto n : map[i])
		{
			printf("%s\n", n.c_str());
		}
	}
	return 0;
}
