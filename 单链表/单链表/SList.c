#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void SListInit(SList* pl) //��ʼ��
{
	assert(pl);
	pl->pHead = NULL;
}


Node* BuySListNode(SDataType data) //����һ�����
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

void SListPushBack(SList* pl, SDataType data) //β��
{
	Node* pNewNode = NULL;//�����µĽ��
	Node* pCur = NULL; //��ͷָ�븳ֵ����

	assert(pl);

	pNewNode = BuySListNode(data);
	pCur = pl->pHead;

	//������
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


void SListPopBack(SList* pl) //βɾ
{
	assert(pl);

	if (NULL == pl->pHead) //������
	{
		printf("û�п���ɾ������\n");
		return;
	}
	else if (NULL == pl->pHead->pNext) //ֻ��һ�����
	{
		free(pl->pHead);
		pl->pHead = NULL;
	}

	//����һ���ҵ������ڶ������

	//else //���������ϵĽ��
	//{
	//	Node* pTailNode = pl->pHead; 
	//	while (pTailNode->pNext->pNext)//�ҵ������ڶ������
	//	{
	//		pTailNode = pTailNode->pNext;
	//	}
	//	free(pTailNode->pNext);
	//	pTailNode->pNext = NULL;
	//}

	//���������ҵ�������һ����㣬������ǰһ�����

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

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ�
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

	//pos�պ��ڵ�һ������λ��
	if (pos == pl->pHead)
	{
		pl->pHead = pos->pNext;
		free(pos);
		return;
	}

	//pos���ڵ�һ��λ��
	pDelNode = pl->pHead;
	while (pDelNode->pNext != pos)
	{
		pDelNode = pDelNode->pNext;
	}
	pDelNode->pNext = pos->pNext;
	free(pos);
}


void PrintSList(SList* pl) //��ӡ����
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


void DestorySList(SList* pl) //��������
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
