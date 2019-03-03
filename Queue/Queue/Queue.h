#pragma once

//用链式结构

typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _pNext; //下一个结点的地址
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
QNode* BuyNode(QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestory(Queue* q);
void QueuePrint(Queue* q);
