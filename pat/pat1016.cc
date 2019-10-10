#include <bits/stdc++.h>

using namespace std;

struct date
{
	int day;
	int hour;
	int min;
	bool sign;

	date() = default;
	date(int d, int h, int m, int s): day(d), hour(h), min(m), sign(s) {}

	bool operator<(date& d)
	{
		if (d.day > day)return true;
		else if (d.day < day)return false;
		if (d.hour > hour)return true;
		else if (d.hour < hour)return false;
		if (d.min >= min)return true;
		return false;
	}
};

struct node
{
	string month;
	vector<date> vec{};

	node() = default;
	node(string m): month(m) {}
};

date readdata()
{
	char a, b, c, d, e, f;
	char s[10];
	scanf(":%c%c:%c%c:%c%c %s", &a, &b, &c, &d, &e, &f, s);
	return date((a - 48) * 10 + (b - 48), (c - 48) * 10 + (d - 48), (e - 48) * 10 + (f - 48), s[1] == 'n');
}

void pdate(date& a, date& b)
{
	cout << setw(2) << setfill('0') << a.day << ':' \
	     << setw(2) << setfill('0') << a.hour << ':'\
	     << setw(2) << setfill('0') << a.min << ' ' \
	     << setw(2) << setfill('0') << b.day << ':' \
	     << setw(2) << setfill('0') << b.hour << ':' \
	     << setw(2) << setfill('0') << b.min << ' ';
}

void deal(vector<int>& vec_cost, vector<date>& vec_date)
{
	int h = 0, sum = 0;
	double res = 0, count = 0;
	for (int i = 0; i < vec_date.size() - 1;)
	{
		if (vec_date[i].sign == true && vec_date[i + 1].sign == false)
		{
			sum = 0;
			h = (vec_date[i + 1].day - vec_date[i].day) * 24 + vec_date[i + 1].hour - vec_date[i].hour;
			for (int j = 0; j < h; ++j)
			{
				sum += vec_cost[(j + vec_date[i].hour) % 24] * 60;
			}
			res = (sum - vec_date[i].min * vec_cost[vec_date[i].hour] + vec_date[i + 1].min * vec_cost[vec_date[i + 1].hour]) * 0.01;
			pdate(vec_date[i], vec_date[i + 1]);
			h = h * 60 - vec_date[i].min + vec_date[i + 1].min;
			cout << h << " $" << fixed << setprecision(2) << res << endl;
			i += 1;
		}
		i += 1;
		count += res;
		res = 0;
	}
	cout << "Total amount: $" << fixed << setprecision(2) << count << endl;
}

bool test(vector<date>& date)
{
	sort(date.begin(), date.end());
	for (int i = 0; i < date.size() - 1; ++i)
	{
		if (date[i].sign == true && date[i + 1].sign == false)return true;
	}
	return false;
}

int main()
{
	int temp = 0;
	string str, mon;
	vector<int> vec_cost;
	map<string, node> map_c;
	for (int i = 0; i < 24; ++i)
	{
		cin >> temp;
		vec_cost.push_back(temp);
	}
	cin >> temp;
	while (temp--)
	{
		cin >> str;
		cin.width(2);
		cin >> mon;
		map_c[str].month = mon;
		map_c[str].vec.push_back(readdata());
	}

	for (auto& c : map_c)
	{
		if (test(c.second.vec))
		{
			cout << c.first << ' ' << c.second.month << endl;
			deal(vec_cost, c.second.vec);
		}
	}
	return 0;
}
