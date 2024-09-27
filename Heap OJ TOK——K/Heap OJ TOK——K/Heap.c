#include"Heap.h"
void HPInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void HPDestroy(HP* php)
{
	assert(php);
	if (php->arr)
		free(php->arr);

	php->arr = NULL;
	php->size = php->capacity = 0;
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)//不需要等于，child只要走到根节点的位置，根节点没有父节点不需要交换
	{
		//建大堆，>
		//建小堆，<
		if (arr[child] < arr[parent])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//判断空间是否足够
	if (php->size == php->capacity)
	{
		//扩容
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newCapacity;
	}
	php->arr[php->size] = x;

	AdjustUp(php->arr, php->size);

	++php->size;
}

void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;//左孩子
	//while (parent < n)
	while (child < n)
	{
		//小堆：找左右孩子中找最小的
		//大堆：找左右孩子中找大的
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;

		}
		else
		{
			break;
		}
	}
}

void HPPop(HP* php)
{
	assert(php && php->size);

	//arr[0]  arr[size-1]
	Swap(&php->arr[0], &php->arr[php->size - 1]);

	--php->size;

	AdjustDown(php->arr, 0, php->size);


}
// 判空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

HPDataType HPTop(HP* php)
{
	assert(php && php->size);

	return php->arr[0];
}