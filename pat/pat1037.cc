/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1037.cc
*   创 建 者：D
*   创建日期：2019年11月02日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

long long deal(vector<int>& a, vector<int>& b, int sign)
{
	int a1, b1, t1 = a.size() - 1, t2 = b.size() - 1;
	long long temp = 0;
	if (sign)
	{
		a1 = t1;
		b1 = t2;
		while (a1 >= 0 && b1 >= 0)
		{
			temp += a[a1--] * b[b1--];
		}
	}
	else
	{
		a1 = 0;
		b1 = 0;
		while (a1 <= t1 && b1 <= t2)
		{
			temp += a[a1++] * b[b1++];
		}
	}
	return temp;
}

int main()
{
	int C, temp;
	vector<int> veca_p, veca_n, vecb_p, vecb_n;
	cin >> C;
	while (C--)
	{
		cin >> temp;
		if (temp < 0)
			veca_n.push_back(temp);
		else
			veca_p.push_back(temp);
	}
	cin >> C;
	while (C--)
	{
		cin >> temp;
		if (temp < 0)
			vecb_n.push_back(temp);
		else
			vecb_p.push_back(temp);
	}
	sort(veca_n.begin(), veca_n.end());
	sort(veca_p.begin(), veca_p.end());
	sort(vecb_n.begin(), vecb_n.end());
	sort(vecb_p.begin(), vecb_p.end());
	cout << deal(veca_n, vecb_n, 0) + deal(veca_p, vecb_p, 1) << endl;
	return 0;
}
