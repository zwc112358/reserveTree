// 重建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>

struct TreeNode
{
	int m_value;
	TreeNode* m_left;
	TreeNode* m_right;

	TreeNode() :m_value(0), m_left(nullptr), m_right(nullptr) {};
	TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr)
		:m_value(value), m_left(left), m_right(right) {};
};
bool restoreTree(int* pre, int* mid, int length, TreeNode* treeRootNode)
{
	if (pre == nullptr || mid == nullptr || treeRootNode == nullptr)
		return false;

	if (length == 0)
		return true;

	bool re = false;
	treeRootNode->m_value = pre[0];
	int leftLen = 0;
	for (; leftLen < length; ++leftLen)
	{
		if (mid[leftLen] == pre[0])
			break;
	}

	if (leftLen >= length)
	{
		return false;
	}
		//return false;

	if (leftLen != 0)
	{
		TreeNode* treeLeft = new TreeNode();
		treeRootNode->m_left = treeLeft;
		if (!restoreTree(&pre[1], &mid[0], leftLen, treeLeft)) return false;
	}

	if (length - 1 - leftLen != 0)
	{
		TreeNode* treeRight = new TreeNode();
		treeRootNode->m_right = treeRight;
		if (!restoreTree(&pre[1 + leftLen], &mid[leftLen + 1], (length - 1 - leftLen), treeRight)) return false;
	}
	return true;
};

//前序遍历
void preOrder(TreeNode* rootNode)
{
	if (rootNode != nullptr)
	{
		std::cout << rootNode->m_value << "\t";
		preOrder(rootNode->m_left);
		preOrder(rootNode->m_right);
	}
}


//中序遍历
void inOrder(TreeNode* rootNode)
{
	if (rootNode != nullptr)
	{
		inOrder(rootNode->m_left);
		std::cout << rootNode->m_value << "\t";
		inOrder(rootNode->m_right);
	}
}

//后序遍历
void postOrder(TreeNode* rootNode)
{
	if (rootNode != nullptr)
	{
		postOrder(rootNode->m_left);
		postOrder(rootNode->m_right);
		std::cout << rootNode->m_value << "\t";
	}
}
int main()
{
	int pre[8] = { 1,2,4,7,3,5,6,8 };
	int mid[8] = { 4,7,2,1,5,3,8,6 };
	TreeNode* treeRootNode = new TreeNode();
	if (restoreTree(pre, mid, 8, treeRootNode))
	{
		preOrder(treeRootNode);
		std::cout << std::endl;
		inOrder(treeRootNode);
		std::cout << std::endl;
		postOrder(treeRootNode);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "input error! \n";
	}



	int pre1[1] = { 1 };
	int mid1[1] = { 1 };
	TreeNode* treeRootNode1 = new TreeNode();
	if (restoreTree(pre1, mid1, 1, treeRootNode1))
	{
		preOrder(treeRootNode1);
		std::cout << std::endl;
		inOrder(treeRootNode1);
		std::cout << std::endl;
		postOrder(treeRootNode1);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "input error! \n";
	}


	
	int pre2[1] = { 1 };
	int mid2[1] = { 2 };
	TreeNode* treeRootNode2 = new TreeNode();
	if (restoreTree(pre2, mid2, 1, treeRootNode2))
	{
		preOrder(treeRootNode2);
		std::cout << std::endl;
		inOrder(treeRootNode2);
		std::cout << std::endl;
		postOrder(treeRootNode2);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "input error! \n";
	}


	int pre3[2] = { 1 ,2};
	int mid3[2] = { 2 ,2};
	TreeNode* treeRootNode3 = new TreeNode();
	if (restoreTree(pre3, mid3, 2, treeRootNode3))
	{
		preOrder(treeRootNode3);
		std::cout << std::endl;
		inOrder(treeRootNode3);
		std::cout << std::endl;
		postOrder(treeRootNode3);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "input error! \n";
	}
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
