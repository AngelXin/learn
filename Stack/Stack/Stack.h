#pragma once

typedef int SDataType;

typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top;   //±ê¼ÇÕ»¶¥
}Stack;


void _CheckCapacity(Stack* ps);
void StackPrint(Stack* ps);
void StackInit(Stack* ps);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
SDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestory(Stack* ps);