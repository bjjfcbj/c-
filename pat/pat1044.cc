/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1044.cc
*   创 建 者：D
*   创建日期：2019年11月22日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int beg;
	int end;
	int sum;

	node() = default;
	node(int z, int a, int b): beg(z), end(a), sum(b) {}
};

int main()
{
	char sign = 0;
	int N, M, temp, num = 0, count = 0;
	scanf("%d %d", &N, &M);
	int* list = (int*)malloc(sizeof(int) * N);
	vector<node> vec;
	while (N--)
	{
		scanf("%d", &temp);
		list[num++] = temp;
	}
	for (int i = 0, j = -1; i < num && j < num; ++i)
	{
		if (j == num - 1 && count < M)
			break;
		while (count < M && j < num)
		{
			++j;
			count += list[j];
		}
		if (count == M)
		{
			if (sign)
			{
				vec.push_back(node(i + 1, j + 1, count));
			}
			else
			{
				sign = 1;
				vec.clear();
				vec.push_back(node(i + 1, j + 1, count));
			}
		}
		else
		{
			if (!sign)
			{
				if (vec.empty())
					vec.push_back(node(i + 1, j + 1, count));
				else
				{
					if (vec.begin()->sum > count)
					{
						vec.clear();
						vec.push_back(node(i + 1, j + 1, count));
					}
					else if (vec.begin()->sum == count)
						vec.push_back(node(i + 1, j + 1, count));
				}
			}
		}
		count -= list[i];
	}
	for (auto a : vec)
	{
		printf("%d-%d\n", a.beg, a.end);
	}
	return 0;
}
