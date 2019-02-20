#pragma once //��ֹͷ�ļ��ظ�����

typedef int SDataType;

typedef struct SListNode//������
{
	SDataType data;//ֵ��
	struct SListNode* pNext;//ָ����ָ��
}Node;


typedef struct SList//����
{
	Node* pHead;//����ṹ�����е�һ����㣨����ͷָ�룩
}SList;


void SListInit(SList* pl); //��ʼ������
Node* BuySListNode(SDataType data);//����һ�����

void SListPushBack(SList* pl, SDataType data);//β��
void SListPopBack(SList* pl); //βɾ

void SListPushFront(SList* pl, SDataType data);//ͷ��
void SListPopFront(SList* pl);//ͷɾ

Node* SListFind(SList* pl, SDataType data);//�������в���ֵΪdata�Ľ�㣬�ҵ����ظý��ĵ�ַ�����򷵻ؿ�
void SListInsertAfter(Node* pos, SDataType data);//��������posλ�ú�����ֵΪdata�Ľ��
void SListErase(SList* pl, Node* pos);//ɾ��������λ����pos�Ľ��

int SListSize(SList* pl);//��ȡ��������Ч���ĸ���
int SListEmpty(SList* pl);//��������Ƿ�Ϊ��

Node* SListFront(SList* pl);//��ȡ�����һ�����
Node* SListBack(SList* pl);//��ȡ����ĵڶ������

void PrintSList(SList* pl);//��ӡ����
void DestorySList(SList* pl);//����