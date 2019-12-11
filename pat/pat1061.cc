/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1061.cc
*   创 建 者：D
*   创建日期：2019年12月10日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

char buf1[70], buf2[70];
char* data[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	int W = 0, D = 0, M = 0;
	scanf("%s %s", buf1, buf2);
	int len1 = strlen(buf1), len2 = strlen(buf2);
	for (int i = 0, j = 0; i < len1 && j < len2; ++i, ++j)
	{
		if (!W)
		{
			if (buf1[i] == buf2[j] && buf1[i] > 64 && buf1[i] < 72)
			{
				W = buf1[i] - 64;
			}
		}
		else
		{
			if (buf1[i] == buf2[j] && ((buf1[i] > 47 && buf1[i] < 58) || (buf1[i] > 64 && buf1[i] < 79)))
			{
				if (buf1[i] > 64)
				{
					D = buf1[i] - 55;
					break;
				}
				else
				{
					D = buf1[i] - 48;
					break;
				}
			}
		}
	}
	scanf("%s %s", buf1, buf2);
	len1 = strlen(buf1), len2 = strlen(buf2);
	for (int i = 0, j = 0; i < len1 && j < len2; ++i, ++j)
	{
		if (buf1[i] == buf2[j] && ((buf1[i] > 64 && buf1[i] < 91) || (buf1[i] > 96 && buf1[i] < 123)))
		{
			M = i;
			break;
		}
	}
	printf("%s %02d:%02d\n", data[W - 1], D, M);
	return 0;
}
