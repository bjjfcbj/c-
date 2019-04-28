#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int ka, kb;
	vector<pair<int, double> > a, b;
	cin >> ka;
	int tmp = ka;
	int c;
	double d;
	while (tmp--)
	{
		cin >> c >> d;
		a.push_back(make_pair(c, d)); //多项式a
	}
	cin >> kb;
	tmp = kb;
	while (tmp--)
	{
		cin >> c >> d;
		b.push_back(make_pair(c, d)); //多项式b
	}

	map<int, double> map;
	for (int i = 0; i < ka; i++)
	{
		for (int j = 0; j < kb; j++)
		{
			int exp = a[i].first + b[j].first; //指数相加
			map[exp] += a[i].second * b[j].second; //底数相乘
			if (map[exp] == 0)
				map.erase(exp);
		}
	}
	cout << map.size();
	for (auto it = map.rbegin(); it != map.rend(); ++it)
	{
		printf(" %d %0.1f", (*it).first, (*it).second);
	}

	return 0;
}
