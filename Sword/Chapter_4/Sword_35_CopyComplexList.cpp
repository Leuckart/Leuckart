/**************************************************
	> File Name:  Sword_35_CopyComplexList.cpp
	> Author:     Leuckart
	> Time:       2020-02-18 21:34
**************************************************/

// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include <cstdio>
#include "../Inc/Sword_ComplexList.h"

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *pCur = pHead;
	while (pCur)
	{
		ComplexListNode *pNew = new ComplexListNode();
		pNew->m_nValue = pCur->m_nValue;
		pNew->m_pNext = pCur->m_pNext;
		pNew->m_pSibling = nullptr;

		pCur->m_pNext = pNew;
		pCur = pNew->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pCur = pHead;
	while (pCur)
	{
		ComplexListNode *pNext = pCur->m_pNext;
		if (pCur->m_pSibling)
			pNext->m_pSibling = pCur->m_pSibling->m_pNext;

		pCur = pNext->m_pNext;
	}
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
	if (!pHead)
		return nullptr;

	ComplexListNode *pCopyHead = pHead->m_pNext;
	ComplexListNode *pCur = pHead;
	ComplexListNode *pCopyCur = pHead->m_pNext;

	while (pCur)
	{
		pCur->m_pNext = pCopyCur->m_pNext;
		pCur = pCur->m_pNext;

		if (pCur)
		{
			pCopyCur->m_pNext = pCur->m_pNext;
			pCopyCur = pCur->m_pNext;
		}
		else
		{
			pCopyCur->m_pNext = nullptr;
		}
	}
	return pCopyHead;
}

ComplexListNode *Clone(ComplexListNode *pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

// ====================测试代码====================
void Test(const char *testName, ComplexListNode *pHead)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList(pHead);

	ComplexListNode *pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
	ComplexListNode *pNode1 = CreateNode(1);
	ComplexListNode *pNode2 = CreateNode(2);
	ComplexListNode *pNode3 = CreateNode(3);
	ComplexListNode *pNode4 = CreateNode(4);
	ComplexListNode *pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test1", pNode1);
	printf("**************************************************\n");
	printf("**************************************************\n");
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
	ComplexListNode *pNode1 = CreateNode(1);
	ComplexListNode *pNode2 = CreateNode(2);
	ComplexListNode *pNode3 = CreateNode(3);
	ComplexListNode *pNode4 = CreateNode(4);
	ComplexListNode *pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, pNode3);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test2", pNode1);
	printf("**************************************************\n");
	printf("**************************************************\n");
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
	ComplexListNode *pNode1 = CreateNode(1);
	ComplexListNode *pNode2 = CreateNode(2);
	ComplexListNode *pNode3 = CreateNode(3);
	ComplexListNode *pNode4 = CreateNode(4);
	ComplexListNode *pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode4);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test3", pNode1);
	printf("**************************************************\n");
	printf("**************************************************\n");
}

// 只有一个结点
void Test4()
{
	ComplexListNode *pNode1 = CreateNode(1);
	BuildNodes(pNode1, nullptr, pNode1);

	Test("Test4", pNode1);
	printf("**************************************************\n");
	printf("**************************************************\n");
}

// 鲁棒性测试
void Test5()
{
	Test("Test5", nullptr);
	printf("**************************************************\n");
	printf("**************************************************\n");
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
