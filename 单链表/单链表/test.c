#define _CRT_SECURE_NO_WARNINGS 1
//不带头结点的单链表

#include "SList.h"
#include <stdio.h>

void TestSList()
{
	SList link;//定义
	SListInit(&link);//初始化
	//PrintSList(&link);//打印

	SListPushBack(&link, 1);//尾插
	SListPushBack(&link, 2);
	SListPushBack(&link, 3);
	SListPushBack(&link, 4);
	SListPushBack(&link, 5);
	SListPushBack(&link, 6);
	SListPushBack(&link, 7);
	SListPopBack(&link); //尾删

	SListPushFront(&link, 0);//头插
	SListPushFront(&link, 8);
	SListPopFront(&link);//头删

	SListInsertAfter(SListFind(&link,4),9);//在链表结点pos位置后置入值为data的结点
	SListErase(&link, SListFind(&link,3));//删除链表中位置在pos的结点

	printf("%d\n",SListSize(&link));//获取链表中有效结点的个数
	printf("%d\n",SListEmpty(&link));//检测链表是否为空

	SListFront(&link);//获取链表第一个结点
	SListBack(&link);//获取链表的第二个结点

	PrintSList(&link);//打印

    DestorySList(&link);//销毁
}

int main()
{
	TestSList();
	return 0;
}