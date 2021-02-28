/**************************************************
	> File Name:  Sword_68_CommonParentInTree.cpp
	> Author:     Leuckart
	> Time:       2020-02-28 04:40
**************************************************/

// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。

#include <iostream>
#include <deque>
#include "../Inc/Sword_Tree.h"
using namespace std;

bool GetNodePath(const TreeNode *pRoot, const TreeNode *pNode, deque<const TreeNode *> &path)
{
	if (pRoot == pNode)
	{
		path.push_back(pRoot);
		return true;
	}

	path.push_back(pRoot);

	vector<TreeNode *> child = pRoot->m_vChildren;
	for (size_t i = 0; i < child.size(); ++i)
		if (pRoot->m_vChildren[i] && GetNodePath(pRoot->m_vChildren[i], pNode, path))
			return true;

	path.pop_back();
	return false;
}

const TreeNode *GetLastCommonParent(const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2)
{
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	deque<const TreeNode *> path1;
	deque<const TreeNode *> path2;

	GetNodePath(pRoot, pNode1, path1);
	GetNodePath(pRoot, pNode2, path2);

	const TreeNode *pParent = nullptr;
	while (path1.front() == path2.front() &&
		   path1.front() != pNode1 &&
		   path2.front() != pNode2)
	{
		pParent = path1.front();
		path1.pop_front();
		path2.pop_front();
	}

	return pParent;
}

// ====================测试代码====================
void Test(const char *testName, const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2, TreeNode *pExpected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	const TreeNode *pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

	if ((pExpected == nullptr && pResult == nullptr) ||
		(pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
	TreeNode *pNode1 = CreateTreeNode(1);
	TreeNode *pNode2 = CreateTreeNode(2);
	TreeNode *pNode3 = CreateTreeNode(3);
	TreeNode *pNode4 = CreateTreeNode(4);
	TreeNode *pNode5 = CreateTreeNode(5);
	TreeNode *pNode6 = CreateTreeNode(6);
	TreeNode *pNode7 = CreateTreeNode(7);
	TreeNode *pNode8 = CreateTreeNode(8);
	TreeNode *pNode9 = CreateTreeNode(9);
	TreeNode *pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);

	Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
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
	TreeNode *pNode1 = CreateTreeNode(1);
	TreeNode *pNode2 = CreateTreeNode(2);
	TreeNode *pNode3 = CreateTreeNode(3);
	TreeNode *pNode4 = CreateTreeNode(4);
	TreeNode *pNode5 = CreateTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode2, pNode3);
	ConnectTreeNodes(pNode3, pNode4);
	ConnectTreeNodes(pNode4, pNode5);

	Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
	TreeNode *pNode1 = CreateTreeNode(1);
	TreeNode *pNode2 = CreateTreeNode(2);
	TreeNode *pNode3 = CreateTreeNode(3);
	TreeNode *pNode4 = CreateTreeNode(4);
	TreeNode *pNode5 = CreateTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode2, pNode3);
	ConnectTreeNodes(pNode3, pNode4);
	ConnectTreeNodes(pNode4, pNode5);

	TreeNode *pNode6 = CreateTreeNode(6);

	Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// 输入nullptr
void Test4()
{
	Test("Test4", nullptr, nullptr, nullptr, nullptr);
}

int main(int argc, char *argv[])
{
	Test1();
	Test2();
	//Test3();
	Test4();

	return 0;
}
