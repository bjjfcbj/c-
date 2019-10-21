/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1030.cc
*   创 建 者：D
*   创建日期：2019年10月18日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int dis, cost;
vector<int> path;

struct hwaynode
{
	int city;
	int distance;
	int cost;

	hwaynode() = default;
	hwaynode(int c, int d, int co): city(c), distance(d), cost(co) {}
};

struct citynode
{
	int num;
	vector<hwaynode> linked;
};

void dfs(vector<citynode>& vec, int* sign, int d, int cur, int len, int cos, vector<int>& temp)
{
	sign[cur] = 1;
	temp.push_back(cur);
	if (cur == d)
	{
		if (dis && ((dis == len && cost > cos) || dis > len))
		{
			dis = len;
			cost = cos;
			path = temp;
		}
		else if (!dis)
		{
			dis = len;
			cost = cos;
			path = temp;

		}
		sign[cur] = 0;
		temp.pop_back();
		return;
	}
	else
	{
		for (auto&v : vec[cur].linked)
		{
			if (!sign[v.city])
			{
				dfs(vec, sign, d, v.city, len + v.distance, cos + v.cost, temp);
			}
		}
	}
	sign[cur] = 0;
	temp.pop_back();
}

void deal(vector<citynode> vec, int s, int d)
{
	dis = 0, cost = 0;
	int *sign = (int*)malloc(vec.size() * sizeof(int));
	memset(sign, 0, vec.size());
	vector<int> temp;
	dfs(vec, sign, d, s, 0, 0, temp);
	for (int i = 0; i < path.size(); ++i)
	{
		if (i)
		{
			printf(" %d", path[i]);
		}
		else printf("%d", path[i]);
	}
	printf(" %d %d\n", dis, cost);
}

int main()
{
	int N, M, S, D, c1, c2;
	scanf("%d %d %d %d\n", &N, &M, &S, &D);
	vector<citynode> citis(N);
	for (int i = 0; i < N; ++i)
	{
		citis[i].num = i;
	}
	while (M--)
	{
		scanf("%d %d %d %d", &c1, &c2, &dis, &cost);
		citis[c1].linked.push_back(hwaynode(c2, dis, cost));
		citis[c2].linked.push_back(hwaynode(c1, dis, cost));
	}
	deal(citis, S, D);
	return 0;
}
