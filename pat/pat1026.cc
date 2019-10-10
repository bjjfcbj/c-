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
	int mark = 0;

	bool operator<(table& t)
	{
		return sec < t.sec;
	}
};

void deal(vector<table>& vec_t, vector<node>& vec_n)
{
	int turn = 0, ha = 0;
	vector<int> sign(vec_n.size(), 0);
	while (turn != vec_n.size())
	{
		ha = 0;
		sort(vec_t.begin(), vec_t.end());
		if (vec_t[0].sec > 56700)
		{
			turn += 1;
			break;
		}
		if (vec_t[0].vip)
		{
			for (int i = turn; i < vec_n.size() && vec_n[i].sec <= vec_t[0].sec; ++i)
			{
				if (vec_n[i].vip && !sign[i])
				{
					sign[i] = 1;
					vec_n[i].server = vec_t[i].sec;
					vec_t[0].sec = vec_n[i].server + vec_n[i].cost * 60;
					vec_t[0].num += 1;
					ha = 1;
					break;
				}
			}
			if (!ha && !sign[turn])
			{
				vec_n[turn].server = vec_n[turn].sec < vec_t[0].sec ? vec_t[0].sec : vec_n[turn].sec;
				vec_t[0].sec = vec_n[turn].server + vec_n[turn].cost * 60;
				vec_t[0].num += 1;
			}
		}
		else
		{
			if (!sign[turn])
			{
				vec_n[turn].server = vec_n[turn].sec < vec_t[0].sec ? vec_t[0].sec : vec_n[turn].sec;
				vec_t[0].sec = vec_n[turn].server + vec_n[turn].cost * 60;
				vec_t[0].num += 1;
			}
		}
		turn += 1;
	}
}

void printtime(int a)
{
	int temp;
	temp = a / 3600;
	a %= 3600;
	cout << setw(2) << setfill('0') << temp << ':';
	temp = a / 60;
	a %= 60;
	cout << setw(2) << setfill('0') << temp << ':';
	cout << setw(2) << setfill('0') << a << ' ';
}

bool nodecmp(node& a, node& b)
{
	return a.server < b.server;
}

bool tablecmp(table& a, table&b)
{
	return a.mark < b.mark;
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
	for (int i = 0; i < tab.size(); ++i)
	{
		tab[i].mark = i;
	}
	cin >> K;
	while (K--)
	{
		cin >> h;
		tab[h].vip = 1;
	}
	sort(vec.begin(), vec.end());
	deal(tab, vec);
	sort(vec.begin(), vec.end(), nodecmp);
	sort(tab.begin(), tab.end(), tablecmp);
	for (auto& v : vec)
	{
		if (v.server)
		{
			printtime(v.sec);
			printtime(v.server);
			cout << (v.server - v.sec + 30) / 60 << endl;
		}
	}
	for (auto& t : tab)
	{
		cout << t.num << ' ';
	}
	return 0;
}
