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

struct person
{
	char Name[20];
	int Age, Net_Worth;
	bool operator<(person p)
	{
		if (Net_Worth != p.Net_Worth)
			return Net_Worth > p.Net_Worth;
		else if (Age != p.Age)
			return Age < p.Age;
		else
			return strcmp(Name, p.Name) <= 0;
	}
};
int main()
{
	int N, K;
	vector<person> vv, v;
	person p;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d", p.Name, &p.Age, &p.Net_Worth);
		vv.push_back(p);
	}
	sort(vv.begin(), vv.end());//在读入所有记录后就排序，不然局部排序会超时
	int M, Amin, Amax;
	bool flag = false;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		flag = false;
		for (int k = 0, count = 0; k < vv.size() && count < M; k++) //对记录进行筛选，注意M表示最多输出的个数
		{
			if (vv[k].Age >= Amin && vv[k].Age <= Amax)
			{
				printf("%s %d %d\n", vv[k].Name, vv[k].Age, vv[k].Net_Worth);
				count++;
				flag = true;
			}
		}
		if (!flag)
			printf("None\n");
	}
	return 0;
}
