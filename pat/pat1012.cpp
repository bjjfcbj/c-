#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct stu_node
{
	int a, c, e, m;
	string id;

	stu_node() = default;
	stu_node(string s)
	{
		id = s;
		a = 0;
		c = 0;
		e = 0;
		m = 0;
	}

	void rank()
	{
		if (a <= c)
		{
			if (a <= m)
			{
				cout << (a <= e ? a : e);
				cout << (a <= e ? " A" : " E");
			}
			else
			{
				cout << (m <= e ? m : e);
				cout << (m <= e ? " M" : " E");
			}
		}
		else
		{
			if (c <= m)
			{
				cout << (c <= e ? c : e);
				cout << (c <= e ? " C" : " E");
			}
			else
			{
				cout << (m <= e ? m : e);
				cout << (m <= e ? " M" : " E");
			}
		}
	}
};

struct grade
{
	int score, num;
	grade() = default;
	grade(int s, int n)
	{
		score = s;
		num = n;
	}

	bool operator<(grade a)
	{
		return this->score > a.score;
	}
};

void inject(vector<stu_node> &stu, vector<grade> grade, int N, int type)
{
	int temp = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i == 0)
		{
			switch (type)
			{
			case 1:
				stu[grade[i].num].a = 1;
				break;
			case 2:
				stu[grade[i].num].c = 1;
				break;
			case 3:
				stu[grade[i].num].m = 1;
				break;
			case 4:
				stu[grade[i].num].e = 1;
				break;
			}
			temp += 1;
		}
		else
		{
			if (grade[i].score == grade[i - 1].score)
			{
				switch (type)
				{
				case 1:
					stu[grade[i].num].a = temp;
					break;
				case 2:
					stu[grade[i].num].c = temp;
					break;
				case 3:
					stu[grade[i].num].m = temp;
					break;
				case 4:
					stu[grade[i].num].e = temp;
					break;
				}
			}
			else
			{
				switch (type)
				{
				case 1:
					stu[grade[i].num].a = i + 1;
					break;
				case 2:
					stu[grade[i].num].c = i + 1;
					break;
				case 3:
					stu[grade[i].num].m = i + 1;
					break;
				case 4:
					stu[grade[i].num].e = i + 1;
					break;
				}
				temp = i + 1;
			}
		}
	}
}

void search(vector<stu_node> stu, string s, int type)
{
	for (auto i : stu)
	{
		if (i.id == s)
		{
			i.rank();
			if (type == 1)
			{
				cout << '\n';
			}
			return;
		}
	}
	cout << "N/A";
	if (type == 1)
	{
		cout << '\n';
	}
}

int main()
{
	int N = 0, M = 0;
	int score_c = 0, score_m = 0, score_e = 0, score_a = 0;
	string id;
	cin >> N >> M;
	vector<grade> a_g, c_g, e_g, m_g;
	vector<stu_node> stu;
	for (int i = 0; i < N; ++i)
	{
		cin >> id;
		stu.push_back(stu_node(id));
		cin >> score_c >> score_m >> score_e;
		score_a = (score_c + score_m + score_e) / 3 + 0.5;
		a_g.push_back(grade(score_a, i));
		c_g.push_back(grade(score_c, i));
		m_g.push_back(grade(score_m, i));
		e_g.push_back(grade(score_e, i));
	}
	sort(a_g.begin(), a_g.end());
	sort(c_g.begin(), c_g.end());
	sort(m_g.begin(), m_g.end());
	sort(e_g.begin(), e_g.end());
	inject(stu, a_g, N, 1);
	inject(stu, c_g, N, 2);
	inject(stu, m_g, N, 3);
	inject(stu, e_g, N, 4);
	for (int i = 0; i < M; ++i)
	{
		cin >> id;
		if (i != M - 1)
		{
			search(stu, id, 1);
		}
		else
		{
			search(stu, id, 0);
		}
	}
	return 0;
}
