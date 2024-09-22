#include"List.h"

void ListTest01()
{
	//创建双向链表变量
	//LTNode* plist = NULL;
	//LTInit(&plist);

	LTNode* plist = LTInit();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);
	//LTPushFront(plist, 1);
	//LTPrint(plist);
	//LTPushFront(plist, 2);
	//LTPrint(plist);
	//LTPushFront(plist, 3);
	//LTPrint(plist);
	//LTPushFront(plist, 4);
	//LTPrint(plist);
	//
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);

	//LTNode* pos = LTFind(plist, 3);
	//if (pos == NULL)
	//{
	//	printf("没有找到！\n");
	//}
	//else
	//{
	//	printf("找到了！\n");
	//}
	//LTInsert(pos, 11);
	//LTErase(pos);
	//LTPrint(plist);

	//LTDesTroy(&plist);
	LTDesTroy2(plist);
	plist = NULL;
}
int main()
{
	ListTest01();
	return 0;
}