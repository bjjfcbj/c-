/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1026.cc
*   创 建 者：D
*   创建日期：2019年10月09日
*   描    述：有很多问题
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
	node(int s, int w, int v)
		: sec(s)
		, cost(w > 120 ? 120 : w)
		, vip(v)
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
	int temp = vec[0].sec;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i].vip && (vec[i].sec <= sec || vec[i].sec == temp))
		{
			return i;
		}
	}
	return -1;
}

int fvnode(vector<node>& vec, vector<int>& sign, int turn, int sec)
{
	int temp = vec[0].sec;
	for (int j = turn; j < vec.size(); ++j)
	{
		if (vec[j].vip && !sign[j] && (vec[j].sec <= sec || vec[j].sec == temp))return j;
	}
	return -1;
}

void deal(vector<table>& vec_t, vector<node>& vec_n, vector<node>& vip)
{
	int vipt = 0, vipn = 0;
	vector<int> sign(vec_n.size(), 0);
	for (int i = 0; i < vec_n.size() && vec_n[i].sec < 75600;)
	{
		sort(vec_t.begin(), vec_t.end());
		if (vec_t[0].sec >= 75600)return;
		if (vec_n[i].vip)
		{
			if (!sign[i])
			{
				vipt = fvtab(vec_t, vec_n[i].sec);
				if (vipt == -1)
				{
					vec_n[i].server = vec_n[i].sec < vec_t[0].sec ? vec_t[0].sec : vec_n[i].sec;
					vec_t[0].num += 1;
					vec_t[0].sec = vec_n[i].sec + vec_n[i].cost * 60;
				}
				else
				{
					sign[i] = 1;
					vec_n[i].server = vec_n[i].sec < vec_t[vipt].sec ? vec_t[vipt].sec : vec_n[i].sec;
					vec_t[vipt].num += 1;
					vec_t[vipt].sec = vec_n[i].sec + vec_n[i].cost * 60;
				}
			}
			i += 1;
		}
		else
		{
			if (!vec_t[0].vip)
			{
				vec_n[i].server = vec_n[i].sec < vec_t[0].sec ? vec_t[0].sec : vec_n[i].sec;
				vec_t[0].num += 1;
				vec_t[0].sec = vec_n[i].sec + vec_n[i].cost * 60;
				i += 1;
			}
			else
			{
				vipn = fvnode(vec_n, sign, i, vec_t[0].sec);
				if (vipn != -1)
				{
					sign[vipn] = 1;
					vec_n[vipn].server = vec_n[vipn].sec < vec_t[0].sec ? vec_t[0].sec : vec_n[vipn].sec;
					vec_t[0].num += 1;
					vec_t[0].sec = vec_n[vipn].sec + vec_n[vipn].cost * 60;
				}
				else
				{
					vec_n[i].server = vec_n[i].sec < vec_t[0].sec ? vec_t[0].sec : vec_n[i].sec;
					vec_t[0].num += 1;
					vec_t[0].sec = vec_n[i].sec + vec_n[i].cost * 60;
					i += 1;
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
	int N, M, K, h, m, s, w, v;
	char c;
	vector<node> vec;
	vector<node> vip;
	cin >> N;
	while (N--)
	{
		scanf("%d%c%d%c%d %d %d\n", &h, &c, &m, &c, &s, &w, &v);
		vec.push_back(node(h * 3600 + m * 60 + s, w, v));
		if (v)vip.push_back(node(h * 3600 + m * 60 + s, w, v));
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
