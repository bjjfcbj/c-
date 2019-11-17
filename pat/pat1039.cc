/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1039.cc
*   创 建 者：D
*   创建日期：2019年11月17日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int gra[][2500];

int main()
{
	int N, K, course, num;
	char stu[5];
	scanf("%d %d", &N, &K);
	map<string, vector<int>> map;
	while (K--)
	{
		scanf("%d %d", &course, &num);
		while (num--)
		{
			scanf("%s", stu);
			map[stu].push_back(course);
		}
	}
	while (num--)
	{
		scanf("%s", stu);
		printf("%s", stu);
		printf("%ld", map[stu].size());
		for (auto& v : map[stu])
		{
			printf(" %d", v);
		}
		printf("\n");
	}
	return 0;
}
