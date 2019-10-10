/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1023.cc
*   创 建 者：D
*   创建日期：2019年10月09日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int doublenum(char* a, char *b, int k)
{
	int sign = 0;
	for (int i = k - 1; i >= 0; --i)
	{
		b[i] = (a[i] - 48) * 2 % 10 + sign + 48;
		sign = (a[i] - 48) * 2 / 10;
	}
	if (sign == 1)return k + 1;
	return k;
}

bool df_permu(char* a, char* b, int k)
{
	char c[10];
	for (int i = 0; i < 10; ++i)
	{
		c[i] = 0;
	}
	for (int i = 0; i <= k; ++i)
	{
		c[a[i] - 48] += 1;
	}
	for (int i = 0; i <= k; ++i)
	{
		c[b[i] - 48] -= 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (c[i] != 0)return false;
	}
	return true;
}

int main()
{
	char buf[25], res[25];
	cin.getline(buf, 21);
	int len = doublenum(buf, res, strlen(buf));
	if (len != strlen(buf))
	{
		cout << "No" << endl << '1';
		for (int i = 0; i <= strlen(buf); ++i)
		{
			cout << res[i];
		}
	}
	else
	{
		if (df_permu(buf, res, len))
		{
			cout << "Yes" << endl;
			for (int i = 0; i <= strlen(buf); ++i)
			{
				cout << res[i];
			}
		}
		else
		{
			cout << "No" << endl;
			for (int i = 0; i <= strlen(buf); ++i)
			{
				cout << res[i];
			}
		}
	}
	return 0;
}
