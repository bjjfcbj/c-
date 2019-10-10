#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<string, int> map;
	map["zau"] = 1;
	map["zaa"] = 1;
	map["uau"] = 1;
	map["hau"] = 1;
	map["aau"] = 1;
	for (auto i : map)cout << i.first << i.second << endl;
	return 0;
}
