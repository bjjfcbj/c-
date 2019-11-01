/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1035.cc
*   创 建 者：D
*   创建日期：2019年11月01日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	string name;
	string password;

	node() = default;
	node(char* a, char* b): name(a), password(b) {}
} node;

int main()
{
	int N, sign = 0, count = 0, s;
	char name[15], buf[15];
	vector<node> vec;
	cin >> N;
	s = N;
	while (N--)
	{
		sign = 0;
		scanf("%s %s", name, buf);
		for (int i = 0; i < strlen(buf); ++i)
		{
			switch (buf[i])
			{
			case 49:
				buf[i] = '@';
				sign = 1;
				break;
			case 48:
				buf[i] = '%';
				sign = 1;
				break;
			case 108:
				buf[i] = 'L';
				sign = 1;
				break;
			case 79:
				buf[i] = 'o';
				sign = 1;
				break;
			}
		}
		if (sign)
		{
			count += 1;
			vec.push_back(node(name, buf));
		}
	}
	if (count)
	{
		cout << count << endl;
		for (auto a : vec)
		{
			cout << a.name << ' ' << a.password << endl;
		}
	}
	else
	{
		if (s == 1)
			cout << "There is " << s << " account and no account is modified" << endl;
		else
			cout << "There are " << s << " accounts and no account is modified" << endl;
	}
	return 0;
}
