#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &sign, vector<vector<int>> vec, int num)
{
	sign[num] = 1;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (sign[i] == 0 && vec[num][i] == 1)
		{
			dfs(sign, vec, i);
		}
	}
}

int highway_need(int len, int key, vector<vector<int>> &vec, vector<int> &sign)
{
	int count = 0;
	sign.clear();
	sign.resize(len);
	sign[key] = 1;
	for (int i = 0; i < len; ++i)
	{
		if (sign[i] == 0)
		{
			dfs(sign, vec, i);
			count += 1;
		}
	}
	return count - 1;
}

int main()
{
	int N = 0, M = 0, K = 0, t1 = 0, t2 = 0, num = 0;
	cin >> N >> M >> K;
	vector<vector<int>> vec(N);
	vector<int> k_num(K);
	vector<int> sign;
	for (int i = 0; i < N; ++i)
	{
		vec[i].resize(N);
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> t1 >> t2;
		vec[t1 - 1][t2 - 1] = 1;
		vec[t2 - 1][t1 - 1] = 1;
	}
	for (int i = 0; i < K; ++i)
	{
		cin >> k_num[i];
	}
	for (int i = 0; i < K; ++i)
	{
		cout << highway_need(N, k_num[i] - 1, vec, sign) << '\n';
	}
	return 0;
}