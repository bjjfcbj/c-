#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

bool ispalindromic(int N, int b)
{
	int temp;
	vec.clear();
	while (N)
	{
		temp = N % b;
		vec.push_back(temp);
		N /= b;
	}
	for (int i = 0; 2 * i <= vec.size(); ++i)
	{
		if (vec[i] != vec[vec.size() - 1 - i])return false;
	}
	return true;
}

int main()
{
	int N, b;
	cin >> N >> b;
	if (ispalindromic(N, b))
	{
		cout << "Yes" << endl;
		for (int i = vec.size() - 1; i >= 0; --i)
		{
			if (i != 0)cout << vec[i] << ' ';
			else cout << vec[i];
		}
	}
	else
	{
		cout << "No" << endl;
		for (int i = vec.size() - 1; i >= 0; --i)
		{
			if (i != 0)cout << vec[i] << ' ';
			else cout << vec[i];
		}
	}
	return 0;
}
