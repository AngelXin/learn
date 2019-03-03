#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
#include <stdio.h>

void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePrint(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("rear = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));
	printf("\n");

	QueuePop(&q);//队头出队

	QueuePrint(&q);
	printf("front = %d\n",QueueFront(&q));
	printf("rear = %d\n",QueueBack(&q));
	printf("size = %d\n",QueueSize(&q));

	printf("empty = %d\n",QueueEmpty(&q));
	QueueDestory(&q);

}

int main()
{
	TestQueue();
	return 0;
}