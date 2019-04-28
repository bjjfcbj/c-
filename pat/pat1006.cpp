#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int readtime()
{
	int time = 0;
	string temp;
	cin >> temp;
	for (char c : temp)
	{
		time *= 10;
		if (c >= 48 && c <= 57)
		{
			time += c - 48;
		}
	}
	return time;
}

int main()
{
	int p_num, in_t = 99999999, out_t = 0, temp_t = 0;
	string in_p, out_p, temp;
	cin >> p_num;
	for (int i = 0; i < p_num; ++i)
	{
		cin >> temp;
		temp_t = readtime();
		if (in_t > temp_t)
		{
			in_t = temp_t;
			in_p = temp;
		}
		temp_t = readtime();
		if (out_t < temp_t)
		{
			out_t = temp_t;
			out_p = temp;
		}
	}
	cout << in_p << " " << out_p;
	return 0;
}
