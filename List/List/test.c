#include"List.h"

void ListTest01()
{
	//����˫���������
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
	//	printf("û���ҵ���\n");
	//}
	//else
	//{
	//	printf("�ҵ��ˣ�\n");
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