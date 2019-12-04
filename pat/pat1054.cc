/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1054.cc
*   创 建 者：D
*   创建日期：2019年12月04日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int M, N, temp, max = -1, res;
	scanf("%d %d", &M, &N);
	map<int, int> map;
	while (N--)
	{
		for (int i = 0; i < M; ++i)
		{
			scanf("%d", &temp);
			map[temp] += 1;
		}
	}
	for (auto& m : map)
	{
		if (max < m.second)
		{
			max = m.second;
			res = m.first;
		}
	}
	printf("%d\n", res);
	return 0;
}
