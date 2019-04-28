#include <cstdlib>
#include <iostream>

using namespace std;

static int sum = -1;

int ep_search(int s, int num, int* list, int& m)
{
	int temp = 0, end = s;
	m = 0;
	for (int i = s; i < num; ++i)
	{
		temp += list[i];
		if (m < temp)
		{
			m = temp;
			end = i;
		}
	}
	return end;
}

int main()
{
	int num = 0, s_p = -1, e_p = -1, temp_s = -1, temp_e = -1, t_sum = 0;
	cin >> num;
	int* list = new int[num];
	for (int i = 0; i < num; ++i)
	{
		cin >> list[i];
	}
	for (int i = 0; i < num; ++i)
	{
		if (list[i] >= 0)
		{
			if (i == 0)
			{
				s_p = i;
				e_p = ep_search(i, num, list, t_sum);
				sum = t_sum;
			}
			else if (list[i - 1] < 0)
			{
				temp_s = i;
				temp_e = ep_search(i, num, list, t_sum);
				if (t_sum > sum)
				{
					s_p = temp_s;
					e_p = temp_e;
					sum = t_sum;
				}
			}
		}
	}
	if (s_p == -1 && e_p == -1)
	{
		sum = 0;
		s_p = 0;
		e_p = num - 1;
	}
	cout << sum << " " << list[s_p] << " " << list[e_p];
	return 0;
}
