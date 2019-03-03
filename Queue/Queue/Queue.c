#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void QueueInit(Queue* q) //初始化
{
	assert(q);
	q->_front = q->_rear = NULL;
}

QNode* BuyNode(QDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));

	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_pNext = NULL;
	pNewNode->data = data;

	return pNewNode;
}

void QueuePush(Queue* q, QDataType data)
{
	QNode* pNewNode = NULL;
	assert(q);

	pNewNode = BuyNode(data);
	if (NULL == q->_front)
	{
		q->_front = q->_rear = pNewNode;
	}
	else
	{
		q->_rear->_pNext = pNewNode;
		q->_rear = pNewNode;
	}
}

void QueuePop(Queue* q)
{
	assert(q);

	//空队列

	if (q->_front == NULL)
	{
		assert(0);
		return;
	}

	//只有一个结点

	else if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}

	//结点数大于1

	else
	{
		QNode* pCur = q->_front;
		q->_front = pCur->_pNext;
		free(pCur);
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	QNode* pCur = NULL;
	int count = 0;

	pCur = q->_front;
	while (pCur)
	{
		count ++ ;
		pCur = pCur->_pNext;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QNode* pCur = NULL;

	pCur = q->_front;
	while (pCur)
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	q->_front = q->_rear = NULL;
}

void QueuePrint(Queue* q)
{
	assert(q);
	QNode* pCur = NULL;

	pCur = q->_front;
	while (pCur)
	{
		printf("%d ", pCur->data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}