#include <bits/stdc++.h>

using namespace std;

/*
Author:D
Description:None
Date:2019.09.11
*/

static int global_time = 0;

struct node
{
	int num;
	int cost;
	int time = -1;

	node() = default;
	node(int n) : num(n), cost(n), time(-1){};
};

bool isempty(vector<queue<node *>> &vec)
{
	for (auto i : vec)
	{
		if (i.size() > 0)
			return 1;
	}
	return 0;
}

bool isfill(vector<queue<node *>> &vec, int num, int &min)
{
	int sign = 0, m = 10;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (m > vec[i].size())
		{
			m = vec[i].size();
			min = i;
		}
		sign += vec[i].size();
	}
	return sign >= num;
}

void fill_vec(vector<queue<node *>> &vec, vector<node> &vec_n, int &num, int size)
{
	int min = 0;
	while (num < vec_n.size() && !isfill(vec, size, min))
	{
		vec[min].push(&vec_n[num]);
		++num;
	}
}

void done(vector<queue<node *>> &vec_q)
{
	int min, sign = 0;
	for (auto &i : vec_q)
	{
		if (i.size() > 0)
		{
			if (!sign)
			{
				min = i.front()->num;
				sign = 1;
			}
			else
			{
				if (i.front()->num < min)
				{
					min = i.front()->num;
				}
			}
		}
	}
	for (auto &i : vec_q)
	{
		if (i.size() > 0)
		{
			i.front()->num -= min;
			i.front()->time = (i.front()->time == -1 ? global_time : i.front()->time);
			if (i.front()->num == 0)
			{
				i.pop();
			}
		}
	}
	global_time += min;
}

void deal(vector<queue<node *>> &vec, vector<node> &vec_n, int size)
{
	int num = 0;
	while (num < vec_n.size() || isempty(vec))
	{
		fill_vec(vec, vec_n, num, size);
		done(vec);
	}
}

void data_f(int t, int cost)
{
	if (t >= 540)
	{
		cout << "Sorry" << endl;
	}
	else
	{
		cout << setw(2) << setfill('0') << (t + cost) / 60 + 8 << ':' << setw(2) << setfill('0') << (t + cost) % 60 << endl;
	}
}

/*
END_TIME:2019.09.22,21,54
*/
int main(int argc, char const *argv[])
{
	int N = 0, M = 0, K = 0, Q = 0, temp = 0;
	cin >> N >> M >> K >> Q;
	vector<node> c_vec;
	vector<queue<node *>> vec_q{static_cast<unsigned long>(N)};
	while (K--)
	{
		cin >> temp;
		c_vec.push_back(node(temp));
	}

	deal(vec_q, c_vec, N * M);

	while (Q--)
	{
		cin >> temp;
		data_f(c_vec[temp - 1].time, c_vec[temp - 1].cost);
	}
	return 0;
}
