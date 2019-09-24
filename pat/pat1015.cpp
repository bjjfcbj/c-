#include <bits/stdc++.h>

using namespace std;

/*
Author:D
Description:None
Date:2019.09.22,22,11
*/

int isprime(int num)
{
	if (num < 2)return 0;
	int i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)return 0;
		++i;
	}
	return 1;
}

void deal(int N, int D)
{
	vector<int> vec;
	int temp = 0;
	while (N)
	{
		vec.push_back(N % D);
		N /= D;
	}
	for (int i = vec.size(), j = 0; i > 0; ++j, --i)
	{
		temp += vec[j] * pow(D, i - 1);
	}
	if (isprime(temp))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

int main()
{
	int N = 0, D = 0;
	while (1)
	{
		cin >> N;
		if (N < 0)break;
		cin >> D;
		if (isprime(N))
		{
			deal(N, D);
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
