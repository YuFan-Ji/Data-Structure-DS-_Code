#include"SList.h"

void test01()
{
	SLTNode* n1 = NULL;
	SLTPushBack(&n1, 1);
	SLTPrint(n1);
	SLTPushBack(&n1, 2);
	SLTPrint(n1);
	SLTPushBack(&n1, 3);
	SLTPrint(n1);
	SLTPushFront(&n1, 100);
	SLTPushFront(&n1, 101);
	SLTPushFront(&n1, 102);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
	SLTPopFront(&n1);
	SLTPopFront(&n1);
	SLTPrint(n1);
	SLTNode* findnode =SLTFind(n1, 100);
	if (findnode == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了%d\n", findnode->date);
	}
	SLTNode* findnode2 = SLTFind(n1, 10);
	if (findnode2 == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了%d\n", findnode2->date);
	}
	SLTInsert(&n1,findnode , 50);
	SLTInsert(&n1, findnode, 20);
	SLTPrint(n1);
	SLTInsertAfter(findnode, 1314);
	SLTInsertAfter(findnode, 1314);
	SLTPrint(n1);
	SLTErase(&n1, findnode);
	SLTPrint(n1);
	findnode = SLTFind(n1, 1314);
	SLTEraseAfter(findnode);
	SLTPrint(n1);
	SLTDestroy(&n1);
}


int main()
{
	test01();
	return 0;
}