/**************************************************
	> File Name:  Sword_55_1_TreeDepth.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 03:39
**************************************************/

// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#include <cstdio>
#include "../Inc/Sword_BinaryTree.h"

int TreeDepth(const BinaryTreeNode *pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int lhs = TreeDepth(pRoot->m_pLeft);
	int rhs = TreeDepth(pRoot->m_pRight);

	return 1 + (lhs > rhs ? lhs : rhs);
}

// ====================测试代码====================
void Test(const char *testName, const BinaryTreeNode *pRoot, int expected)
{
	int result = TreeDepth(pRoot);
	if (expected == result)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test1()
{
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, nullptr, pNode6);
	ConnectTreeNodes(pNode5, pNode7, nullptr);

	Test("Test1", pNode1, 4);

	DestroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode5, nullptr);

	Test("Test2", pNode1, 5);

	DestroyTree(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	Test("Test3", pNode1, 5);

	DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
	Test("Test4", pNode1, 1);

	DestroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
	Test("Test5", nullptr, 0);
}

int main(int argc, char *argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}
