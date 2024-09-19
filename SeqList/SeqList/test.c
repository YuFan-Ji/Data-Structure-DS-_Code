#include"SeqList.h"

void test01()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPrint(s);
	SLPushFront(&s, 0);
	SLPushFront(&s, 0);
	SLPrint(s);
	SLInsert(&s, 0, 99);
	SLInsert(&s, 2, 100);
	SLInsert(&s, 6, 77);
	SLPrint(s);
	SLPopBack(&s);
	SLPrint(s);
	SLPopFront(&s);
	SLPrint(s);
	SLErase(&s, 3);
	SLPrint(s);
}

void test02()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 0);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	int tem = SLFind(&s, 2);
	printf("%d\n", tem);
	printf("%d\n", s.arr[tem]);
}

int main()
{
	test01();
	printf("----------------------------\n");
	test02();
	return 0;
}