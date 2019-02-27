#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <stdio.h>

void TestStack()
{
	Stack s;
	StackInit(&s);
	// _CheckCapacity(&s);
	StackPush(&s, 2);//β��
	StackPush(&s, 4);
	StackPush(&s, 3);
	StackPrint(&s);
	printf("top = %d,size = %d\n", StackTop(&s), StackSize(&s));//��ջ��Ԫ��,����ЧԪ�صĸ���

	StackPush(&s, 5);
	StackPrint(&s);
	printf("top = %d,size = %d\n", StackTop(&s), StackSize(&s));//��ջ��Ԫ��,����ЧԪ�صĸ���

	StackPop(&s);//βɾ
	StackPrint(&s);
	printf("top = %d,size = %d\n", StackTop(&s), StackSize(&s));//��ջ��Ԫ��,����ЧԪ�صĸ���

	printf("empty = %d\n", StackEmpty(&s));//ջ�Ƿ�Ϊ��

	StackDestory(&s);

	//StackPrint(&s);
}

int main()
{
	TestStack();
	return 0;
}