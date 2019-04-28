#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int num = 0, temp = 0, floor = 0;
	cin >> num;
	int* list = new int[num];
	for (int i = 0; i < num; ++i)
	{
		cin >> list[i];
	}
	for (int i = 0; i < num; ++i)
	{
		if (list[i] - floor >= 0)
		{
			temp = temp + (list[i] - floor) * 6 + 5;
		}
		else
		{
			temp = temp + (floor - list[i]) * 4 + 5;
		}
		floor = list[i];
	}
	cout << temp;
	return 0;
}
