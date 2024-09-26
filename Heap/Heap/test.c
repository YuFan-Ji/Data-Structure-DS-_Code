#include"Heap.h"

void test01()
{
	HP hp;
	HPInit(&hp);

	int arr[] = { 17,20,10,13,19,15 };
	for (int i = 0; i < 6; i++)
	{
		HPPush(&hp, arr[i]);
	}

	//HPPop(&hp);

	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}


	HPDestroy(&hp);
}

int main()
{
	test01();
	return 0;
}