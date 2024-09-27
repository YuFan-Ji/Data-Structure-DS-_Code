#include"Heap.h"
#include<time.h>

//冒泡排序
//时间复杂度：0(N^2)
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			//升序
			if (arr[j] > arr[j + 1])
			{
				exchange = 1;
				Swap(&arr[j], &arr[j + 1]);
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}
//堆排序
//空间复杂度为0(1)
//时间复杂度为O(n*logn)
void HeapSort(int* arr, int n)
{
	//建堆
	//升序---大堆
	//降序----小堆


	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(arr, i);
	//}

	//向下调整算法建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}

	//循环将堆顶数据跟最后位置（会变化，每次减少一个数据）的数据进行交换
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

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

	//int i = 0;
	//while (!HPEmpty(&hp))
	//{
	//	arr[i++] = HPTop(&hp);
	//	HPPop(&hp);
	//}
	int k = 3;
	while (k--)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}

	//for (int i = 0; i < 6; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	HPDestroy(&hp);
}


void CreateNDate()
{
	// 造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void TOPk()
{
	int k = 0;
	printf("请输入k:");
	scanf("%d", &k);

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail!");
		exit(1);
	}
	int* minHeap = (int*)malloc(k * sizeof(int));
	if (minHeap == NULL)
	{
		perror("malloc fail!");
		exit(2);
	}

	//从文件中读取前K个数据
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	//建堆---小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, i, k);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//读取到的数据跟堆顶的数据进行比较
		//比堆顶值大，交换入堆
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			AdjustDown(minHeap, 0, k);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}

	fclose(fout);
}

int main()
{
	//test01();
	////给定一个数组，对数组中的数据进行排序
	/*int arr[] = { 17,20,10,13,19,15 };

	BubbleSort(arr,6);
	HeapSort(arr, 6);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	//CreateNDate();
	TOPk();
	return 0;
}