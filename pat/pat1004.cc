#include <cstdlib>
#include <iostream>

using namespace std;

int static max_lv = 0;

struct treenode
{
	int parent;
	int nl_sign;
	treenode()
	{
		parent = -1;
		nl_sign = 0;
	}
};

int readnode()
{
	int num = 0;
	char a, b;
	cin >> a >> b;
	num = (a - 48) * 10 + b - 48;
	return num;
}

void lv_count(treenode* list, int* sign, int length)
{
	int count, lv;
	for (int i = length - 1; i > -1; --i)
	{
		count = i;
		lv = 0;
		while (count != 0)
		{
			count = list[count].parent;
			++lv;
		}
		if (list[i].nl_sign == 0)
		{
			sign[lv] += 1;
		}
		max_lv = max_lv > lv ? max_lv : lv;
	}
}

int main()
{
	int M = 0, N = 0, K = 0;
	cin >> M >> N;
	treenode* list = new treenode[M];
	list[0].parent = -1;
	int* sign = new int[M];
	int temp, p_node;
	for (int i = 0; i < N; ++i)
	{
		temp = readnode();
		list[temp - 1].nl_sign = 1;
		p_node = temp;
		cin >> K;
		for (int j = 0; j < K; ++j)
		{
			temp = readnode();
			list[temp - 1].parent = p_node - 1;
		}
	}
	lv_count(list, sign, M);
	for (int i = 0; i <= max_lv; ++i)
	{
		if (i != max_lv)
		{
			cout << sign[i] << " ";
		}
		else
		{
			cout << sign[i];
		}
	}
	return 0;
}
