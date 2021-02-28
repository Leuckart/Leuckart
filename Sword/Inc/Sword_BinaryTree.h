/**************************************************
	> File Name:  Sword_BinaryTree.h
	> Author:     Leuckart
	> Time:       2020-02-15 15:22
**************************************************/

#ifndef SWORD_BINARYTREE_H_
#define SWORD_BINARYTREE_H_

#include <cstdio>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode *CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight);
void PrintTreeNode(const BinaryTreeNode *pNode);
void PrintTree(const BinaryTreeNode *pRoot);
void DestroyTree(BinaryTreeNode *pRoot);

#endif
