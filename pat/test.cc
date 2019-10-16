#include <bits/stdc++.h>

using namespace std;
#define INF 21*3600
#define MAX 10000
int CurrTime[MAX + 5];
int numTable[MAX + 5]; //桌子被玩的次数
//用户的结构体
struct Player
{
	int startTime;//到达的时间
	int waitTime;//等待的时间
	int playTime;//玩耍的时间
} VipPlayer[MAX + 5], OriPlayer[MAX + 5];
int n;//n个人
int k, m; //桌子的数量，vip桌子的数量
int cmp(Player a, Player b)
{
	return a.startTime < b.startTime;   //比较函数，快速排序
}
int VipNumber;//会员的人数
int OriNumber;//普通的人数
bool vipTag[MAX + 5]; //标记vip桌子
void printTime(int time)
{
	int hh, mm, ss;
	ss = time % 60;
	mm = time / 60 % 60;
	hh = time / 3600;
	printf("%02d:%02d:%02d ", hh, mm, ss);
}
int main()
{
	scanf("%d", &n);
	int hh, mm, ss, time, tag;
	VipNumber = 1;
	OriNumber = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int sum = hh * 3600 + mm * 60 + ss;
		scanf("%d%d", &time, &tag);
		if (time > 120) //如果超过两个小时，要进行限制
			time = 120;
		if (hh >= 21) continue; //如果超出营业时间，要进行限制
		if (tag) //如果是vip
		{
			VipPlayer[VipNumber].startTime = sum;
			VipPlayer[VipNumber].waitTime = 0;
			VipPlayer[VipNumber++].playTime = time;
		}
		else//如果不是
		{
			OriPlayer[OriNumber].startTime = sum;
			OriPlayer[OriNumber].waitTime = 0;
			OriPlayer[OriNumber++].playTime = time;
		}
	}
	scanf("%d%d", &k, &m); //输入桌子数量和vip桌子数量
	int xx;
	memset(vipTag, 0, sizeof(vipTag));
	memset(numTable, 0, sizeof(numTable));
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &xx);
		vipTag[xx] = 1;
	}
	//对普通和vip进行排序
	sort(VipPlayer + 1, VipPlayer + VipNumber, cmp);
	sort(OriPlayer + 1, OriPlayer + OriNumber, cmp);
	int i = 1, j = 1;
	int index = -1;
	for (int i = 1; i <= k; i++)
		CurrTime[i] = 8 * 3600;
	while (i < VipNumber || j < OriNumber)
	{
		int minTime = INF, VipTime = INF, OriTime = INF;
		for (int p = 1; p <= k; p++)
		{
			if (CurrTime[p] < minTime)
			{
				minTime = CurrTime[p];
				index = p;
			}
		}
		if (i > VipNumber && j > OriNumber)
			break;
		if (i < VipNumber)
		{
			VipTime = max(VipPlayer[i].startTime, minTime);
		}
		if (j < OriNumber)
		{
			OriTime = max(OriPlayer[j].startTime, minTime);
		}
		bool VipServe = true;
		if (VipTime > OriTime && OriTime < 21 * 3600)
		{
			VipServe = false;
		}
		else if (OriTime > VipTime && VipTime < 21 * 3600)
		{
			VipServe = true;
		}
		else if (OriTime == VipTime && OriTime < 21 * 3600)
		{
			if (vipTag[index] || (!vipTag[index] && VipPlayer[i].startTime < OriPlayer[j].startTime))
				VipServe = true;
			else
				VipServe = false;
		}
		else if (OriTime == 21 * 3600 && VipTime == 21 * 3600)
		{
			break;
		}
		//判断当前桌子可以为谁服务
		if (VipServe)
		{

			if (!vipTag[index])
			{
				for (int p = 1; p <= k; p++)
				{
					if (vipTag[p] && CurrTime[p] == minTime)
					{

						index = p;
					}
				}

			}
			VipPlayer[i].waitTime = VipTime;
			CurrTime[index] = VipTime + VipPlayer[i].playTime * 60;
			numTable[index]++;

			printTime(VipPlayer[i].startTime);
			printTime(VipPlayer[i].waitTime);
			printf("%d\n", (VipPlayer[i].waitTime - VipPlayer[i].startTime + 30) / 60);
			i++;
		}
		else
		{
			OriPlayer[j].waitTime = OriTime;
			CurrTime[index] = OriTime + OriPlayer[j].playTime * 60;
			numTable[index]++;

			printTime(OriPlayer[j].startTime);
			printTime(OriPlayer[j].waitTime);
			printf("%d\n", (OriPlayer[j].waitTime - OriPlayer[j].startTime + 30) / 60);
			j++;
		}
	}
	printf("%d", numTable[1]);
	for (int i = 2; i <= k; i++)
		printf(" %d", numTable[i]);
	printf("\n");
	return 0;
}
