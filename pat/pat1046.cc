/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1046.cc
*   创 建 者：D
*   创建日期：2019年11月27日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, temp, temp1, temp2, count = 0, sum = 0;
	cin >> N;
	vector<int> vec;
	while (N--)
	{
		cin >> temp;
		vec.push_back(temp);
		count += temp;
	}
	cin >> M;
	while (M--)
	{
		sum = 0;
		cin >> temp1 >> temp2;
		if (temp1 > temp2)
		{
			temp = temp1;
			temp1 = temp2;
			temp2 = temp;
		}
		for (int i = temp1 - 1; i < temp2 - 1; ++i)
		{
			sum += vec[i];
		}
		cout << (2 * sum > count ? count - sum : sum) << endl;
	}
	return 0;
}
