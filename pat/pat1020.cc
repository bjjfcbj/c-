/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1020.cc
*   创 建 者：D
*   创建日期：2019年10月06日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int num;
	node* left = NULL;
	node* right = NULL;

	node() = default;
} bnode;

void deal(vector<int>& post, vector<int>& in, int p_sta, int p_end, int i_sta, int i_end, node& n)
{
	if (i_sta > i_end || p_sta > p_end)return;
	if (p_sta == p_end)n.num = post[p_end];
	else
	{
		n.num = post[p_end];
		for (int i = i_sta; i <= i_end; ++i)
		{
			if (in[i] == post[p_end])
			{
				if (i + 1 <= i_end)
				{
					n.right = new node();
					deal(post, in, p_end - i_end + i, p_end - 1, i + 1, i_end, *n.right);
				}
				if (i_sta <= i - 1)
				{
					n.left = new node();
					deal(post, in, p_sta, p_sta + i - i_sta - 1, i_sta, i - 1, *n.left);
				}
				break;
			}
		}
	}
}

vector<int> level_order(node& n)
{
	vector<int> vec;
	queue<node> que;
	que.push(n);
	while (!que.empty())
	{
		vec.push_back(que.front().num);
		if (que.front().left != NULL)
		{
			que.push(*que.front().left);
		}
		if (que.front().right != NULL)
		{
			que.push(*que.front().right);
		}
		que.pop();
	}
	return vec;
}

int main()
{
	int N, temp, t;
	vector<int> post_o, in_o;
	cin >> N;
	t = 2 * N;
	while (t--)
	{
		cin >> temp;
		if (t >= N)post_o.push_back(temp);
		else in_o.push_back(temp);
	}
	deal(post_o, in_o, 0, post_o.size() - 1, 0, in_o.size() - 1, bnode);
	vector<int> v = level_order(bnode);
	for (int i = 0; i < v.size(); ++i)
	{
		if (i != v.size() - 1)cout << v[i] << ' ';
		else cout << v[i];
	}
	return 0;
}
