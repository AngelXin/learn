#pragma once //防止头文件重复引用

typedef int SDataType;

typedef struct SListNode//定义结点
{
	SDataType data;//值域
	struct SListNode* pNext;//指针域指针
}Node;


typedef struct SList//链表
{
	Node* pHead;//链表结构链表中的一个结点（链表头指针）
}SList;


void SListInit(SList* pl); //初始化链表
Node* BuySListNode(SDataType data);//开辟一个结点

void SListPushBack(SList* pl, SDataType data);//尾插
void SListPopBack(SList* pl); //尾删

void SListPushFront(SList* pl, SDataType data);//头插
void SListPopFront(SList* pl);//头删

Node* SListFind(SList* pl, SDataType data);//在链表中查找值为data的结点，找到返回该结点的地址，否则返回空
void SListInsertAfter(Node* pos, SDataType data);//在链表结点pos位置后置入值为data的结点
void SListErase(SList* pl, Node* pos);//删除链表中位置在pos的结点

int SListSize(SList* pl);//获取链表中有效结点的个数
int SListEmpty(SList* pl);//检测链表是否为空

Node* SListFront(SList* pl);//获取链表第一个结点
Node* SListBack(SList* pl);//获取链表的第二个结点

void PrintSList(SList* pl);//打印链表
void DestorySList(SList* pl);//销毁