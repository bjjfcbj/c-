/*================================================================
*   Copyright (C) 2019 D. All rights reserved.
*
*   文件名称：pat1043.cc
*   创 建 者：D
*   创建日期：2019年11月21日
*   描    述：
*
================================================================*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int num;
	char sign_left = 0;
	struct node* left = NULL;
	struct node* right = NULL;

	node() = default;
	node(int a): num(a) {}
};

bool bst_insert(node* root, int num)
{
	if (root->num > num)
	{
		if (root->sign_left)return false;
		if (!root->left)
		{
			root->left = new node(num);
			return true;
		}
		else
		{
			return bst_insert(root->left, num);
		}
	}
	else
	{
		root->sign_left = 1;
		if (!root->right)
		{
			root->right = new node(num);
			return true;
		}
		else
		{
			return bst_insert(root->right, num);
		}
	}
}

bool mbst_insert(node* root, int num)
{
	if (root->num <= num)
	{
		if (root->sign_left)return false;
		if (!root->left)
		{
			root->left = new node(num);
			return true;
		}
		else
		{
			return mbst_insert(root->left, num);
		}
	}
	else
	{
		root->sign_left = 1;
		if (!root->right)
		{
			root->right = new node(num);
			return true;
		}
		else
		{
			return mbst_insert(root->right, num);
		}
	}
}

void postorder(node* root, int height)
{
	if (root->left)postorder(root->left, height + 1);
	if (root->right)postorder(root->right, height + 1);
	if (height)printf("%d ", root->num);
	else printf("%d", root->num);
}

int main()
{
	char bst = 0, mbst = 0;
	int N, temp;
	scanf("%d", &N);
	scanf("%d", &temp);
	node* root = new node(temp);
	node* mroot = new node(temp);
	while (--N)
	{
		scanf("%d", &temp);
		if (!bst_insert(root, temp))bst = 1;
		if (!mbst_insert(mroot, temp))mbst = 1;
	}
	if (!bst)
	{
		printf("YES\n");
		postorder(root, 0);
	}
	else if (!mbst)
	{
		printf("YES\n");
		postorder(mroot, 0);
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
