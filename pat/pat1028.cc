/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1028.cc
*   创 建 者：D
*   创建日期：2019年10月16日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int id;
	char* name;
	int grade;

	node() = default;
	node(int i, char *n, int g): id(i), name(n), grade(g) {}
} node;

bool cmp1(node& a, node& b)
{
	return a.id < b.id;
}

bool cmp2(node& a, node& b)
{
	if (!strcmp(a.name, b.name))return a.id < b.id;
	else return strcmp(a.name, b.name) > 0 ? false : true;
}

bool cmp3(node& a, node& b)
{
	if (a.grade == b.grade)return a.id < b.id;
	else return a.grade < b.grade;
}

int main()
{
	int N, C, id, grade;
	char *name;
	vector<node> vec;
	scanf("%d %d\n", &N, &C);
	while (N--)
	{
		name = (char*)malloc(9 * sizeof(char));
		scanf("%d %s %d", &id, name, &grade);
		vec.push_back(node(id, name, grade));
	}
	if (C == 1)
	{
		sort(vec.begin(), vec.end(), cmp1);
	}
	else if (C == 2)
	{
		sort(vec.begin(), vec.end(), cmp2);
	}
	else
	{
		sort(vec.begin(), vec.end(), cmp3);
	}
	for (auto v : vec)
	{
		printf("%06d %s %d\n", v.id, v.name, v.grade);
	}
	return 0;
}
