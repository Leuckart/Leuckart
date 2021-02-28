/**************************************************
	> File Name:  Sword_ComplexList.h
	> Author:     Leuckart
	> Time:       2020-02-18 21:37
**************************************************/

#ifndef SWORD_COMPLEXLIST_H_
#define SWORD_COMPLEXLIST_H_

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};

ComplexListNode *CreateNode(int nValue);
void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling);
void PrintList(ComplexListNode *pHead);

#endif
