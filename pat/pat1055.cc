/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1055.cc
*   创 建 者：D
*   创建日期：2019年12月05日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int worth;
	int age;
	char* name;

	node() = default;
	node(int a, char* b, int c): worth(a), name(b), age(c) {}
	bool operator<(node& n)
	{
		if (worth == n.worth)
		{
			if (age == n.age)
				return strcmp(name, n.name) <= 0;
			else
				return age < n.age;
		}
		else
			return worth > n.worth;
	}
};

vector<node> res;
vector<node> vecs[201];
char buf[10];

char* readbuf(int len)
{
	char* temp = (char*)malloc(len);
	for (int i = 0; i < len; ++i)
		temp[i] = buf[i];
	return temp;
}

void deal(int num, int age1, int age2, int k)
{
	res.clear();
	for (int i = age1; i <= age2; ++i)
	{
		for (auto v : vecs[i])
			res.push_back(v);
	}
	sort(res.begin(), res.end());
	int len = res.size();
	printf("Case #%d:\n", k);
	if (len)
	{
		for (int i = 0; i < num && i < len; ++i)
		{
			printf("%s %d %d\n", res[i].name, res[i].age, res[i].worth);
		}
	}
	else
	{
		printf("None\n");
	}
}

int main()
{
	int N, K, age, worth, num;
	scanf("%d %d", &N, &K);
	while (N--)
	{
		scanf("%s %d %d", buf, &age, &worth);
		vecs[age].push_back(node(worth, readbuf(strlen(buf)), age));
	}
	for (int i = 0; i < K; ++i)
	{
		scanf("%d %d %d", &num, &age, &worth);
		deal(num, age, worth, i + 1);
	}
	return 0;
}
