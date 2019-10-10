#include <bits/stdc++.h>

using namespace std;

struct node
{
	int seceond;
	int cost = 0;

	node() = default;
	node(int s, int c): seceond(s), cost(c) {}

	bool operator<(node& n)
	{
		return seceond < n.seceond;
	}
};

int deal(vector<node>& vec, vector<int>& vec_k)
{
	int min, num, res = 0;
	sort(vec.begin(), vec.end());
	for (auto v : vec)
	{
		min = vec_k[0];
		num = 0;
		for (int i = 0; i < vec_k.size(); ++i)
		{
			if (min > vec_k[i])
			{
				min = vec_k[i];
				num = i;
			}
		}
		if (vec_k[num] > v.seceond)
		{
			res = res + vec_k[num] - v.seceond;
			vec_k[num] += v.cost;
		}
		else
		{
			vec_k[num] = v.seceond + v.cost;
		}
	}
	return res;
}

int main()
{
	int N, K, temp, a, b, c;
	char d;
	vector<node> vec_c;
	cin >> N >> K;
	vector<int> vec_k(K, 28800);
	while (N--)
	{
		cin >> a >> d >> b >> d >> c >> temp;
		if (a * 3600 + b * 60 + c <= 61200)
		{
			vec_c.push_back(node(a * 3600 + b * 60 + c, temp * 60));
		}
	}
	if (vec_c.size())
	{
		cout << fixed << setprecision(1) << deal(vec_c, vec_k) / 60.0 / vec_c.size() << endl;
	}
	else
	{
		cout << "0.0" << endl;
	}
	return 0;
}
