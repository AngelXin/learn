#pragma once

//����ʽ�ṹ

typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _pNext; //��һ�����ĵ�ַ
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
