/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1024.cc
*   创 建 者：D
*   创建日期：2019年10月09日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

bool ispalindromic(vector<int>& vec)
{
	for (int i = 0; i <= vec.size() / 2; ++i)
	{
		if (vec[i] != vec[vec.size() - 1 - i])return false;
	}
	return true;
}

void work(vector<int>& vec)
{
	int sign = 0, t = 0;
	vector<int> temp = vec;
	for (int i = 0; i < vec.size(); ++i)
	{
		t = vec[i] + temp[vec.size() - 1 - i] + sign;
		vec[i] = t % 10;
		sign = t / 10;
	}
	if (sign)vec.push_back(1);
}

void prinvec(vector<int>& vec)
{
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		cout << vec[i];
	}
}

void deal(vector<int>& vec, int K)
{
	for (int i = 0; i <= K; ++i)
	{
		if (ispalindromic(vec))
		{
			prinvec(vec);
			cout << endl << i << endl;
			return;
		}
		if (i != K)work(vec);
	}
	prinvec(vec);
	cout << endl << K << endl;
}

int main()
{
	int K, temp;
	long N;
	cin >> N >> K;
	vector<int> vec;
	while (N)
	{
		temp = N % 10;
		vec.push_back(temp);
		N /= 10;
	}
	deal(vec, K);
	return 0;
}
