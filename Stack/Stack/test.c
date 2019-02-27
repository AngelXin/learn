#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <stdio.h>

void TestStack()
{
	Stack s;
	StackInit(&s);
	// _CheckCapacity(&s);
	StackPush(&s, 2);//尾插
	StackPush(&s, 4);
	StackPush(&s, 3);
	StackPrint(&s);
	printf("top = %d,size = %d\n", StackTop(&s), StackSize(&s));//求栈顶元素,求有效元素的个数

	StackPush(&s, 5);
	StackPrint(&s);
	printf("top = %d,size = %d\n", StackTop(&s), StackSize(&s));//求栈顶元素,求有效元素的个数

	StackPop(&s);//尾删
	StackPrint(&s);
	printf("top = %d,size = %d\n", StackTop(&s), StackSize(&s));//求栈顶元素,求有效元素的个数

	printf("empty = %d\n", StackEmpty(&s));//栈是否为空

	StackDestory(&s);

	//StackPrint(&s);
}

int main()
{
	TestStack();
	return 0;
}