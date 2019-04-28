#include <iostream>
#include <cstdlib>
using namespace std;

struct Lpoint
{
	int num = 0, city_n = 0, sign = 0;
};

static int cost = 0, count = 0, num = 0, s_place = 0, e_place = 0;
int city_num = 0, road_num = 0, temp1 = 0, temp2 = 0;

void d_search(Lpoint point, int c, int n, int* r_cost, Lpoint* lp)
{
	if (point.city_n == e_place)
	{
		if (cost == 0)
		{
			cost = c;
			count = 1;
			num = n;
		}
		else if (c < cost)
		{
			cost = c;
			count = 1;
			num = n;
		}
		else if (c == cost)
		{
			count += 1;
			num = n > num ? n : num;
		}
	}
	else
	{
		for (int rc = 0; rc < city_num; ++rc)
		{
			if (r_cost[point.city_n * city_num + rc] > 0 && lp[rc].sign != 1)
			{
				lp[rc].sign = 1;
				d_search(lp[rc], c + r_cost[point.city_n * city_num + rc], n + lp[rc].num, r_cost, lp);
				lp[rc].sign = 0;
			}
		}
	}
}

int main()
{
	cin >> city_num >> road_num >> s_place >> e_place;
	Lpoint* plist = new Lpoint[city_num];
	int* r_cost = new int[city_num * city_num];
	for (int i = 0; i < city_num; ++i)
	{
		plist[i].city_n = i;
		cin >> plist[i].num;
	}
	for (int i = 0; i < road_num; ++i)
	{
		cin >> temp1 >> temp2 >> r_cost[temp1 * city_num + temp2];
		r_cost[temp2 * city_num + temp1] = r_cost[temp1 * city_num + temp2];
	}
	plist[s_place].sign = 1;
	d_search(plist[s_place], 0, plist[s_place].num, r_cost, plist);
	cout << count << " " << num;
	return 0;
}
