#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, e;
	int b = 0, count = 0;
	getline(cin, a);
	for (char c : a)
	{
		b += c - 48;
	}
	if (b == 0)
	{
		cout << "zero";
		return 0;
	}
	while (b > 0)
	{
		e += b % 10;
		b /= 10;
	}
	for (int i = e.length() - 1; i >= 0; --i)
	{
		if (i != 0 )
		{
			switch (e[i])
			{
			case 0:
				cout << "zero";
				break;
			case 1:
				cout << "one";
				break;
			case 2:
				cout << "two";
				break;
			case 3:
				cout << "three";
				break;
			case 4:
				cout << "four";
				break;
			case 5:
				cout << "five";
				break;
			case 6:
				cout << "six";
				break;
			case 7:
				cout << "seven";
				break;
			case 8:
				cout << "eight";
				break;
			case 9:
				cout << "nine";
				break;
			}
			cout << " ";
		}
		else
		{
			switch (e[i])
			{
			case 0:
				cout << "zero";
				break;
			case 1:
				cout << "one";
				break;
			case 2:
				cout << "two";
				break;
			case 3:
				cout << "three";
				break;
			case 4:
				cout << "four";
				break;
			case 5:
				cout << "five";
				break;
			case 6:
				cout << "six";
				break;
			case 7:
				cout << "seven";
				break;
			case 8:
				cout << "eight";
				break;
			case 9:
				cout << "nine";
				break;
			}
		}
	}
	return 0;
}
