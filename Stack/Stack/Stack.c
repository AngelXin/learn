#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

void _CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		//¿ª±ÙÐÂ¿Õ¼ä
		int newcapacity = ps->_capacity*2;
		SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType)*newcapacity);
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}

		//¿½±´ÔªËØ
		memcpy(pTemp, ps->_array, ps->_top*sizeof(SDataType));

		//ÊÍ·Å¾É¿Õ¼ä
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newcapacity;
	}
}

void StackPrint(Stack* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->_top ; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*3);
	if (NULL == ps->_array)
	{
		assert(0);
		return;
	}
	
	ps->_capacity =3;
	ps->_top = 0;
}

void StackPush(Stack* ps, SDataType data)//Î²²å
{
	assert(ps);
	_CheckCapacity(ps);//À©ÈÝ
	ps->_array[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps)//Î²É¾
{
	assert(ps);
	if (0 == ps->_top)
		return;

	ps->_top--;
}

SDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_top-1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_top;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}
