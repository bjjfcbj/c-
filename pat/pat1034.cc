/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1034.cc
*   创 建 者：D
*   创建日期：2019年10月25日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
unordered_map<string, int> timecount;
unordered_map<string, vector<string> > link;
map<string, int> out;
map<string, bool> flag;
int idx, allweight;
string st;

void dfs(string str)
{
	flag[str] = true;
	allweight += timecount[str];

	if (timecount[str] > timecount[st]) st = str;
	for (int i = 0; i < link[str].size(); i++)
	{
		if (!flag[link[str][i]])
		{
			dfs(link[str][i]);
		}
	}
	idx++;
}

int main()
{
	cin >> n >> k;
	char a[5], b[5];
	int time;
	while (n--)
	{
		scanf("%s %s %d", a, b, &time);
		string aa = string(a), bb = string(b);
		if (timecount.find(aa) == timecount.end()) timecount[aa] = 0;
		if (timecount.find(bb) == timecount.end()) timecount[bb] = 0;
		timecount[aa] += time;
		timecount[bb] += time;

		link[aa].push_back(bb);
		link[bb].push_back(aa);

		flag[aa] = false;
		flag[bb] = false;
	}

	for (auto it = flag.begin(); it != flag.end(); it++)
	{
		if (it->second == false)
		{
			idx = 0;
			allweight = 0;
			st = it->first;
			dfs(st);
			if (idx > 2 && allweight / 2 > k)
				out[st] = idx;
		}
	}

	cout << out.size() << endl;
	for (auto it = out.begin(); it != out.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
