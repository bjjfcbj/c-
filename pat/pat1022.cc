/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1022.cc
*   创 建 者：D
*   创建日期：2019年10月08日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

void readline(string& s)
{
	s.clear();
	string temp;
	char c;
	while (c = getchar(), c != '\n' && c != EOF)
	{
		temp += c;
	}
	s = temp;
}

void sp_str(string& s, map<string, vector<string>>& map, string& id)
{
	string temp;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
		{
			temp.push_back(s[i]);
			if (i == s.size() - 1)map[temp].push_back(id);
		}
		else
		{
			map[temp].push_back(id);
			temp.clear();
		}
	}
}

void printvec(vector<string>& vec)
{
	sort(vec.begin(), vec.end());
	for (auto s : vec)
	{
		cout << s << endl;
	}
}

int main()
{
	int N, M, req;
	char buf[200];
	string id, temp;
	map<string, vector<string>> title, author, keyword, publisher, year;
	scanf("%d\n", &N);
	while (N--)
	{
		readline(id);
		readline(temp);
		title[temp].push_back(id);
		readline(temp);
		author[temp].push_back(id);
		readline(temp);
		sp_str(temp, keyword, id);
		readline(temp);
		publisher[temp].push_back(id);
		readline(temp);
		year[temp].push_back(id);
	}
	scanf("%d\n", &M);
	while (M--)
	{
		string s;
		if (M != 0)
		{
			readline(temp);
			req = temp[0] - 48;
			s = temp.substr(3);
		}else{
			cin.get(buf,200);
			temp=buf;
			req = temp[0] - 48;
			s = temp.substr(3);
		}
		switch (req)
		{
		case 1:
			if (title.count(s))
			{
				cout << temp << endl;
				printvec(title[s]);
			}
			else
			{
				cout << temp << endl;
				cout << "Not Found" << endl;
			}
			break;
		case 2:
			if (author.count(s))
			{
				cout << temp << endl;
				printvec(author[s]);
			}
			else
			{
				cout << temp << endl;
				cout << "Not Found" << endl;
			}
			break;
		case 3:
			if (keyword.count(s))
			{
				cout << temp << endl;
				printvec(keyword[s]);
			}
			else
			{
				cout << temp << endl;
				cout << "Not Found" << endl;
			}
			break;
		case 4:
			if (publisher.count(s))
			{
				cout << temp << endl;
				printvec(publisher[s]);
			}
			else
			{
				cout << temp << endl;
				cout << "Not Found" << endl;
			}
			break;
		case 5:
			if (year.count(s))
			{
				cout << temp << endl;
				printvec(year[s]);
			}
			else
			{
				cout << temp << endl;
				cout << "Not Found" << endl;
			}
			break;
		}
	}
	return 0;
}
