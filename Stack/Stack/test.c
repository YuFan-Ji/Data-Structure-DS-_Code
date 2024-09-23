#include"Stack.h"

void STTest()
{
	ST st;
	STInit(&st);
	//////////////////////////
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	printf("size: %d\n", STSize(&st));//4
	//StackPush(&st, 5);

	//StackPop(&st);

	//ѭ����ջ��ֱ��ջΪ��
	while (!StackEmpty(&st))
	{
		STDataType data = StackTop(&st);
		printf("%d ", data);
		//��ջ
		StackPop(&st);
	}
	printf("size: %d\n", STSize(&st));//0


	///////////////////////
	STDestroy(&st);
}

int main()
{
	STTest();
	return 0;
}