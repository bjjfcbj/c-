/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1036.cc
*   创 建 者：D
*   创建日期：2019年11月01日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	string name;
	string id;
};

int main()
{
	int N, gra_f = -1, gra_m = 101, rec;
	char sign, name[15], id[15];
	node female, male;
	cin >> N;
	while (N--)
	{
		scanf("%s %c %s %d", name, &sign, id, &rec);
		if (sign == 'F')
		{
			if (rec > gra_f)
			{
				gra_f = rec;
				female.name = string(name);
				female.id = string(id);
			}
		}
		else
		{
			if (rec < gra_m)
			{
				gra_m = rec;
				male.name = string(name);
				male.id = string(id);
			}
		}
	}
	if (gra_f >= 0)
		cout << female.name << ' ' << female.id << endl;
	else
		cout << "Absent" << endl;
	if (gra_m <= 100)
		cout << male.name << ' ' << male.id << endl;
	else
		cout << "Absent" << endl;
	if (gra_m > 100 || gra_f < 0)
		cout << "NA" << endl;
	else
		cout << gra_f - gra_m << endl;
	return 0;
}
