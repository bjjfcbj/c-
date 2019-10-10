/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1026.cc
*   创 建 者：D
*   创建日期：2019年10月09日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int sec;
	int cost;
	int vip;
	int server = 0;

	node() = default;
	node(int s, int w, int v): sec(s), cost(w), vip(v) {}

	bool operator<(node& n)
	{
		return sec < n.sec;
	}
};

struct table
{
	int sec = 28800;
	int num = 0;
	int vip = 0;
};

void deal(vector<table>& vec_t, vector<node>& vec_n)
{

}

int main()
{
	int N, M, K, h, m, s, w, v;
	char c;
	vector<node> vec;
	cin >> N;
	while (N--)
	{
		scanf("%d%c%d%c%d %d %d\n", &h, &c, &m, &c, &s, &w, &v);
		//if (h * 3600 + m * 60 + s < 75600)
		vec.push_back(node(h * 3600 + m * 60 + s, w, v));
	}
	cin >> M;
	vector<table> tab(M);
	cin >> K;
	while (K--)
	{
		cin >> h;
		tab[h].vip = 1;
	}
	sort(vec.begin(), vec.end());
	deal(tab, vec);
	return 0;
}
