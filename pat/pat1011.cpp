#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	double temp = 0, max = -1, result = 1;
	string s;
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 1; i < 4; ++i)
		{
			cin >> temp;
			if (temp > max)
			{
				max = temp;
				n = i;
			}
		}
		if (n == 1)s += "W ";
		if (n == 2)s += "T ";
		if (n == 3)s += "L ";
		result *= max;
	}
	cout << s;
	printf("%.2f", result * 1.3 - 2);
	return 0;
}
