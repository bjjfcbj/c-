/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1025.cc
*   创 建 者：D
*   创建日期：2019年10月09日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	long long id = 0;
	int sco = 0;
	int frank = 0;
	int testpl = 0;
	int lrank = 0;

	node() = default;
	node(long long i, int s): id(i), sco(s) {}

	bool operator <(node& n)
	{
		if (sco > n.sco)return true;
		else if (sco == n.sco)return id < n.id;
		return false;
	}
};

int main()
{
	int N, K, sco, place = 0;
	long long id;
	vector<node> fina, local;
	cin >> N;
	while (place++, N--)
	{
		cin >> K;
		while (K--)
		{
			cin >> id >> sco;
			local.push_back(node(id, sco));
		}
		sort(local.begin(), local.end());
		local[0].lrank = 1;
		local[0].testpl = place;
		for (int i = 1; i < local.size(); ++i)
		{
			local[i].testpl = place;
			if (local[i].sco == local[i - 1].sco)
			{
				local[i].lrank = local[i - 1].lrank;
			}
			else
			{
				local[i].lrank = i + 1;
			}
		}
		for (auto l : local)
		{
			fina.push_back(l);
		}
		local.clear();
	}
	sort(fina.begin(), fina.end());
	fina[0].frank = 1;
	for (int i = 1; i < fina.size(); ++i)
	{
		if (fina[i].sco == fina[i - 1].sco)
		{
			fina[i].frank = fina[i - 1].frank;
		}
		else
		{
			fina[i].frank = i + 1;
		}
	}
	cout << fina.size() << endl;
	for (auto f : fina)
	{
		cout << setw(13) << setfill('0') << f.id << ' ' << f.frank << ' ' << f.testpl << ' ' << f.lrank << endl;
	}
	return 0;
}
