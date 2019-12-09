/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1059.cc
*   创 建 者：D
*   创建日期：2019年12月09日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

vector<long> vec;

bool isprime(long a)
{
	for (auto v : vec)
	{
		if (!a % v)
			return false;
	}
	vec.push_back(a);
	return true;
}

int main()
{
	long N, temp;
	scanf("%ld", &N);
	if (N == 1)
	{
		printf("1=1");
		return 0;
	}
	temp = N;
	vec.push_back(2);
	map<long, int> M;
	while (!(N % 2))
	{
		M[2] += 1;
		N /= 2;
	}
	for (long i = 3; i * i <= N; i += 2)
	{
		if (isprime(i))
		{
			while (!(N % i))
			{
				M[i] += 1;
				N /= i;
			}
		}
	}
	if (N > 1)M[N] = 1;
	printf("%ld=", temp);
	map<long, int>::iterator m;
	for (m = M.begin(); m != M.end(); ++m)
	{
		if (m != --M.end())
		{
			printf("%ld", m->first);
			if (m->second - 1)
				printf("^%d*", m->second);
			else
				printf("*");
		}
		else
		{
			printf("%ld", m->first);
			if (m->second - 1)
				printf("^%d", m->second);
		}
	}
	return 0;
}
