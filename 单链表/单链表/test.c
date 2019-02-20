#define _CRT_SECURE_NO_WARNINGS 1
//����ͷ���ĵ�����

#include "SList.h"
#include <stdio.h>

void TestSList()
{
	SList link;//����
	SListInit(&link);//��ʼ��
	//PrintSList(&link);//��ӡ

	SListPushBack(&link, 1);//β��
	SListPushBack(&link, 2);
	SListPushBack(&link, 3);
	SListPushBack(&link, 4);
	SListPushBack(&link, 5);
	SListPushBack(&link, 6);
	SListPushBack(&link, 7);
	SListPopBack(&link); //βɾ

	SListPushFront(&link, 0);//ͷ��
	SListPushFront(&link, 8);
	SListPopFront(&link);//ͷɾ

	SListInsertAfter(SListFind(&link,4),9);//��������posλ�ú�����ֵΪdata�Ľ��
	SListErase(&link, SListFind(&link,3));//ɾ��������λ����pos�Ľ��

	printf("%d\n",SListSize(&link));//��ȡ��������Ч���ĸ���
	printf("%d\n",SListEmpty(&link));//��������Ƿ�Ϊ��

	SListFront(&link);//��ȡ�����һ�����
	SListBack(&link);//��ȡ����ĵڶ������

	PrintSList(&link);//��ӡ

    DestorySList(&link);//����
}

int main()
{
	TestSList();
	return 0;
}