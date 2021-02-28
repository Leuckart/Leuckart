/**************************************************
	> File Name:  Sword_55_2_BalancedBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 03:42
**************************************************/

// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

#include <cstdio>
#include <iostream>
#include "../Inc/Sword_BinaryTree.h"

int IsBalancedRecursive(const BinaryTreeNode *const pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int lhs = IsBalancedRecursive(pRoot->m_pLeft);
	int rhs = IsBalancedRecursive(pRoot->m_pRight);

	if (lhs >= 0 && rhs >= 0 && abs(lhs - rhs) <= 1)
		return 1 + (lhs > rhs ? lhs : rhs);

	return -1;
}

bool IsBalanced(const BinaryTreeNode *const pRoot)
{
	return IsBalancedRecursive(pRoot) >= 0;
}

// ====================测试代码====================
void Test(const char *testName, const BinaryTreeNode *pRoot, bool expected)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("Solution2 begins: ");
	if (IsBalanced(pRoot) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
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
	ConnectTreeNodes(pNode3, pNode6, pNode7);

	Test("Test1", pNode1, true);

	DestroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
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

	Test("Test2", pNode1, true);

	DestroyTree(pNode1);
}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         
//      4  5
//        /
//       6
void Test3()
{
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode5, pNode6, nullptr);

	Test("Test3", pNode1, false);

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
void Test4()
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

	Test("Test4", pNode1, false);

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
void Test5()
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

	Test("Test5", pNode1, false);

	DestroyTree(pNode1);
}

// 树中只有1个结点
void Test6()
{
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
	Test("Test6", pNode1, true);

	DestroyTree(pNode1);
}

// 树中没有结点
void Test7()
{
	Test("Test7", nullptr, true);
}

int main(int argc, char *argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}
