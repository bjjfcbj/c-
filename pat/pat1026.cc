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
	int num = 0;

	node() = default;
	node(int s, int w, int v, int n)
		: sec(s)
		, cost(w > 120 ? 120 : w)
		, vip(v)
		, num(n)
	{
	}

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
		if (sec != t.sec)
			return sec < t.sec;
		else
			return mark < t.mark;
	}
};

int fvtab(vector<table>& vec, int sec)
{
	for (auto i = 0; i < vec.size(); ++i)
	{
		if (vec[i].vip && vec[i].sec <= sec)
		{
			return i;
		}
	}
	return -1;
}

void deal(vector<table>& vec_t, vector<node>& vec_n, vector<node>& vip)
{
	int sign[vec_n.size()] = {0}, vipt = 0;
	for (int i = 0; i < vec_n.size(); ++i)
	{
		if (vec_n[i].vip)
		{
			if (!sign[i])
			{
				vipt = fvtab(vec_t, vec_n[i].sec)
					if (vipt == -1) {

					}else{
						sign[vipt]=1;
					}
			}
		}
	}
}

void printtime(int a)
{
	printf("%02d:%02d:%02d ", a / 3600, a / 60 % 60, a % 60);
}

bool nodecmp(node& a, node& b)
{
	if (a.server != b.server)
		return a.server < b.server;
	else
		return a.sec < b.sec;
}

bool tablecmp(table& a, table& b)
{
	return a.mark < b.mark;
}

int main()
{
	int N, M, K, h, m, s, w, v, temp = 0;
	char c;
	vector<node> vec;
	vector<node> vip;
	cin >> N;
	while (N--)
	{
		scanf("%d%c%d%c%d %d %d\n", &h, &c, &m, &c, &s, &w, &v);
		vec.push_back(node(h * 3600 + m * 60 + s, w, v, temp));
		if (v)vip.push_back(node(h * 3600 + m * 60 + s, w, v, temp));
		temp += 1;
	}
	cin >> M;
	vector<table> tab(M);
	for (int i = 0; i < tab.size(); ++i)
	{
		tab[i].mark = i + 1;
	}
	cin >> K;
	while (K--)
	{
		cin >> h;
		tab[h - 1].vip = 1;
	}
	sort(vec.begin(), vec.end());
	sort(vip.begin(), vip.end());
	deal(tab, vec, vip);
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
	for (int i = 0; i < tab.size(); ++i)
	{
		if (i != tab.size() - 1)
			cout << tab[i].num << ' ';
		else
			cout << tab[i].num;
	}
	return 0;
}
