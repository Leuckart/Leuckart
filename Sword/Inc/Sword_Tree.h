/**************************************************
	> File Name:  Sword_Tree.h
	> Author:     Leuckart
	> Time:       2020-02-28 04:41
**************************************************/

#ifndef SWORD_TREE_H_
#define SWORD_TREE_H_

#include <cstdio>
#include <vector>

struct TreeNode
{
	int m_nValue;
	std::vector<TreeNode *> m_vChildren;
};

TreeNode *CreateTreeNode(int value);
void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild);
void PrintTreeNode(const TreeNode *pNode);
void PrintTree(const TreeNode *pRoot);
void DestroyTree(TreeNode *pRoot);

#endif
