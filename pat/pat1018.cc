#include <bits/stdc++.h>

using namespace std;

int C, send_n = 0, back_n = 0, length = 0;
vector<int> path, temp;
map<int, int> sign;

struct node
{
	int num;
	map<int, int> n_map;

	node() = default;
};

void count(map<int, node>& map, vector<int>& path, int& send, int& back, int limit)
{
	int s = 0, b = 0, temp = 0;
	for (int i = 1; i < path.size(); ++i)
	{
		temp += map[path[i]].num - limit / 2;
		if (temp < 0 && s < -temp)
		{
			s = -temp;
		}
	}
	back = temp + s;
	send = s;
}

void dfs(map<int, node>& map, int total, int num, int len, int limit)
{
	int sen = 0, bac = 0;
	temp.push_back(total);
	sign[total] = 1;
	if (total == num)
	{
		if (length == 0 || length > len)
		{
			length = len;
			path = temp;
			count(map, path, send_n, back_n, limit);
		}
		else if (length == len && length != 0)
		{
			count(map, temp, sen, bac, limit);
			if (sen < send_n)
			{
				path = temp;
				count(map, path, send_n, back_n, limit);
			}
			else if (sen == send_n && bac < back_n)
			{
				path = temp;
				count(map, path, send_n, back_n, limit);
			}
		}
	}
	else
	{
		for (auto i : map[total].n_map)
		{
			if (sign[i.first] == 0)dfs(map, i.first, num, len + i.second, limit);
		}
	}
	temp.pop_back();
	sign[total] = 0;
}

void deal(map<int, node>& map, int num, int limit)
{
	dfs(map, 0, num, 0, limit);
	cout << send_n << " 0";
	for (auto i : path)
	{
		if (i != 0)cout << "->" << i;
	}
	cout << ' ' << back_n << endl;
}

int main()
{
	int S, M, N, temp = 0, temp2, cost;
	cin >> C >> N >> S >> M;
	map<int, node> map;
	while (++temp, N--)
	{
		cin >> map[temp].num;
		sign[temp] = 0;
	}
	while (M--)
	{
		cin >> temp >> temp2 >> cost;
		map[temp].n_map[temp2] = cost;
		map[temp2].n_map[temp] = cost;
	}
	deal(map, S, C);
	return 0;
}
