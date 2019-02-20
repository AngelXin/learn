#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void SListInit(SList* pl) //初始化
{
	assert(pl);
	pl->pHead = NULL;
}


Node* BuySListNode(SDataType data) //开辟一个结点
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->data = data;
	pNode->pNext = NULL;
	return pNode;
}

void SListPushBack(SList* pl, SDataType data) //尾插
{
	Node* pNewNode = NULL;//定义新的结点
	Node* pCur = NULL; //将头指针赋值给它

	assert(pl);

	pNewNode = BuySListNode(data);
	pCur = pl->pHead;

	//空链表
	if (NULL == pl->pHead)
		pl->pHead = pNewNode;
	else
	{
		while (pCur->pNext)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNewNode;
	}
}


void SListPopBack(SList* pl) //尾删
{
	assert(pl);

	if (NULL == pl->pHead) //空链表
	{
		printf("没有可以删除的项\n");
		return;
	}
	else if (NULL == pl->pHead->pNext) //只有一个结点
	{
		free(pl->pHead);
		pl->pHead = NULL;
	}

	//方法一：找到倒数第二个结点

	//else //有两个以上的结点
	//{
	//	Node* pTailNode = pl->pHead; 
	//	while (pTailNode->pNext->pNext)//找到倒数第二个结点
	//	{
	//		pTailNode = pTailNode->pNext;
	//	}
	//	free(pTailNode->pNext);
	//	pTailNode->pNext = NULL;
	//}

	//方法二：找到倒数第一个结点，并保存前一个结点

	else
	{
		Node* pTailNode = pl->pHead;
		Node* pPreNode = NULL;
		while (pTailNode->pNext)
		{
			pPreNode = pTailNode;
			pTailNode = pTailNode->pNext;
		}
		free(pTailNode);
		pPreNode->pNext = NULL;
	}
}


void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	assert(pl);

	pNewNode = BuySListNode(data);
	pNewNode->pNext = pl->pHead;
	pl->pHead = pNewNode;
}

void SListPopFront(SList* pl)
{
	assert(pl);
	if (NULL == pl->pHead)
	{
		return;
	}
	else
	{
		Node* pDelNode = pl->pHead;
		pl->pHead = pDelNode->pNext;
		free(pDelNode);
	}
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空
Node* SListFind(SList* pl, SDataType data)
{
	Node* pCur = pl->pHead;
	assert(pl);

	while (pCur)
	{
		if (pCur->data == data)
		{
			return pCur;
		}
		else
		{
			pCur = pCur->pNext;
		}
	}
	return NULL;
}

void SListInsertAfter(Node* pos, SDataType data)
{
	Node* pNewNode = NULL;
	if (NULL == pos)
		return;

	pNewNode = BuySListNode(data);
	pNewNode->pNext = pos->pNext;
	pos->pNext = pNewNode;
}

void SListErase(SList* pl, Node* pos)
{
	Node* pDelNode = NULL;
	assert(pl);

	if (NULL == pl->pHead || NULL == pos)
		return;

	//pos刚好在第一个结点的位置
	if (pos == pl->pHead)
	{
		pl->pHead = pos->pNext;
		free(pos);
		return;
	}

	//pos不在第一个位置
	pDelNode = pl->pHead;
	while (pDelNode->pNext != pos)
	{
		pDelNode = pDelNode->pNext;
	}
	pDelNode->pNext = pos->pNext;
	free(pos);
}


void PrintSList(SList* pl) //打印链表
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->pHead;
	while (pCur)
	{
		printf("%d-->", pCur->data);
		pCur = pCur->pNext;
	}
	printf("NULL\n");
}


void DestorySList(SList* pl) //销毁链表
{
	Node* pCur = NULL;
	assert(pl);

	pCur = pl->pHead;
	while (pCur)
	{
		pl->pHead = pCur->pNext;
		free(pCur);
		pCur = pl->pHead;
	}
	pl->pHead = NULL;
}

int SListSize(SList* pl)
{
	assert(pl);
	Node* pCur = NULL;
	int count = 0;

	pCur = pl->pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->pNext;
	}
	return count;
}


int SListEmpty(SList* pl)
{
	assert(pl);
	return NULL == pl->pHead;
}

Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->pHead;
}


Node* SListBack(SList* pl)
{
	Node* pCur = pl->pHead;
	assert(pl);
	assert(pl->pHead);

	pCur = pl->pHead;
	while (pCur->pNext)
	{
		pCur = pCur->pNext;
	}
	return pCur;
}
