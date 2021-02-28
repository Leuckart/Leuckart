/**************************************************
	> File Name:  Sword_18_01_DeleteNodeInList.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 14:25
**************************************************/

// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

#include <iostream>
#include <cassert>
#include <cstdio>
#include "../Inc/Sword_List.h"
using namespace std;

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if (!pListHead || !*pListHead || !pToBeDeleted)
		return;

	if (*pListHead == pToBeDeleted)
	{
		*pListHead = pToBeDeleted->m_pNext;
		delete pToBeDeleted;
	}
	else if (pToBeDeleted->m_pNext)
	{
		pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
		ListNode *pTmp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
		delete pTmp;
	}
	else
	{
		ListNode *pNext = *pListHead;
		while (pNext && pNext->m_pNext != pToBeDeleted)
			pNext = pNext->m_pNext;

		if (pNext)
		{
			pNext->m_pNext = nullptr;
			delete pToBeDeleted;
		}
	}
}

// ====================测试代码====================
void Test(ListNode *pListHead, ListNode *pNode)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	printf("The node to be deleted is: \n");
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
	ListNode *pNode1 = CreateListNode(1);
	ListNode *pNode2 = CreateListNode(2);
	ListNode *pNode3 = CreateListNode(3);
	ListNode *pNode4 = CreateListNode(4);
	ListNode *pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
	ListNode *pNode1 = CreateListNode(1);
	ListNode *pNode2 = CreateListNode(2);
	ListNode *pNode3 = CreateListNode(3);
	ListNode *pNode4 = CreateListNode(4);
	ListNode *pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
	ListNode *pNode1 = CreateListNode(1);
	ListNode *pNode2 = CreateListNode(2);
	ListNode *pNode3 = CreateListNode(3);
	ListNode *pNode4 = CreateListNode(4);
	ListNode *pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
	ListNode *pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
	Test(nullptr, nullptr);
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
