#include"Heap.h"
#include<time.h>

//ð������
//ʱ�临�Ӷȣ�0(N^2)
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			//����
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
//������
//�ռ临�Ӷ�Ϊ0(1)
//ʱ�临�Ӷ�ΪO(n*logn)
void HeapSort(int* arr, int n)
{
	//����
	//����---���
	//����----С��


	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(arr, i);
	//}

	//���µ����㷨����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}

	//ѭ�����Ѷ����ݸ����λ�ã���仯��ÿ�μ���һ�����ݣ������ݽ��н���
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
	// ������
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
	printf("������k:");
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

	//���ļ��ж�ȡǰK������
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	//����---С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, i, k);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//��ȡ�������ݸ��Ѷ������ݽ��бȽ�
		//�ȶѶ�ֵ�󣬽������
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
	////����һ�����飬�������е����ݽ�������
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