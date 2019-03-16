#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinTreeNode
{
	char  data;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BTNode;

BTNode* CreateBinTree(BTDataType* array, int* index)
{
	if ((array[*index]) == '#')
	{
		++(*index);
		return NULL;
	}
	BTNode* pRoot = (BTNode*)malloc(sizeof(BTNode));
	pRoot->data = array[*index];
	++(*index);

	pRoot->left = CreateBinTree(array, index);
	pRoot->right = CreateBinTree(array, index);

	return pRoot;
}

void PreOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;

	PreOrder(pRoot->left);
	printf("%c ", pRoot->data);
	PreOrder(pRoot->right);
}

void DestoryBinTree(BTNode* pRoot)
{
	if (pRoot)
	{
		DestoryBinTree(pRoot->left);
		DestoryBinTree(pRoot->right);
		free(pRoot);
	}
}

int main()
{
	char array[100] = {0};
	scanf("%s ", array);
	int index = 0;
	BTNode* pRoot = CreateBinTree(array, &index);
	PreOrder(pRoot);
	DestoryBinTree(pRoot);

	return 0;
}