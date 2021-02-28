/**************************************************
	> File Name:  Sword_List.h
	> Author:     Leuckart
	> Time:       2020-02-15 15:13
**************************************************/

#ifndef SWORD_LIST_H_
#define SWORD_LIST_H_

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *CreateListNode(int value);
void ConnectListNodes(ListNode *pCurrent, ListNode *pNext);
void PrintListNode(ListNode *pNode);
void PrintList(ListNode *pHead);
void DestroyList(ListNode *pHead);
void AddToTail(ListNode **pHead, int value);
void RemoveNode(ListNode **pHead, int value);

#endif
