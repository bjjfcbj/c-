/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1021.cc
*   创 建 者：D
*   创建日期：2019年10月07日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int num;
	vector<int> adja;

	node() = default;
};

int components(vector<node>& vec)
{
	int count = 0;
	vector<int> sign(static_cast<int>(vec.size() + 1));
	for (auto v : vec)
	{
		if (sign[v.num] == 0)
		{
			queue<int> que;
			que.push(v.num);
			sign[v.num] = 1;
			while (!que.empty())
			{
				for (auto i : vec[que.front()].adja)
				{
					if (sign[i] == 0)
					{
						que.push(i);
						sign[i] = 1;
					}
				}
				que.pop();
			}
			count += 1;
		}
	}
	return count;
}

int deepfun(vector<node>& vec, int num)
{
	int length = 1, last = num, now = num;
	vector<int> sign(static_cast<int>(vec.size()));
	queue<int> que;
	que.push(num);
	sign[num] = 1;
	while (!que.empty())
	{
		now = que.front();
		for (auto i : vec[now].adja)
		{
			if (sign[i] != 1)
			{
				que.push(i);
				sign[i] = 1;
			}
		}
		if (now == last)
		{
			last = que.back();
			length += 1;
		}
		que.pop();
	}
	return length;
}

void deal(vector<node>& vec)
{
	int deep = -1, temp, haha;
	vector<int> res;
	if (components(vec) != 1)cout << "Error: " << components(vec) << " components" << endl;
	else
	{
		for (auto v : vec)
		{
			temp = deepfun(vec, v.num);
			if (deep != -1 && deep < temp)
			{
				deep = temp;
				res.clear();
				res.push_back(v.num);
			}
			else if (deep == -1 || deep == temp)
			{
				deep = temp;
				res.push_back(v.num);
			}
		}
		for (auto r : res)
		{
			cout << r + 1 << endl;
		}
	}
}

int main()
{
	int N, a, b;
	cin >> N;
	vector<node> nodevec(static_cast<unsigned long>(N));
	for (int i = 0; i < N; ++i)
	{
		nodevec[i].num = i;
	}
	while (--N)
	{
		cin >> a >> b;
		nodevec[a - 1].adja.push_back(b - 1);
		nodevec[b - 1].adja.push_back(a - 1);
	}
	deal(nodevec);
	return 0;
}
