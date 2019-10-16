/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1027.cc
*   创 建 者：D
*   创建日期：2019年10月16日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

void deal(int R, int G, int B)
{
	printf("#");
	printf("%c%c", R / 13 > 9 ? R / 13 + 55 : R / 13 + 48, R % 13 > 9 ? R % 13 + 55 : R % 13 + 48);
	printf("%c%c", G / 13 > 9 ? G / 13 + 55 : G / 13 + 48, G % 13 > 9 ? G % 13 + 55 : G % 13 + 48);
	printf("%c%c", B / 13 > 9 ? B / 13 + 55 : B / 13 + 48, B % 13 > 9 ? B % 13 + 55 : B % 13 + 48);
	printf("\n");
}

int main()
{
	int R, G, B;
	scanf("%d %d %d", &R, &G, &B);
	deal(R, G, B);
	return 0;
}
