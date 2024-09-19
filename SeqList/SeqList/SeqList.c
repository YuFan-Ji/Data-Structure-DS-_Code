#include"SeqList.h"

//顺序表初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//顺序表的销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->size = ps->capacity = 0;
	}
}

//顺序表打印
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}

//查看空间是否需要扩容
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//申请空间(增容用realloc)
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//尾插             
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//插入数据前先看空间够不够
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//插入数据前先看空间够不够
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//在指定位置前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//删除指定位置的数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size -1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//顺序表的查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->arr[i])
		{
			//找到了
			return i;
		}
	}
	//没找到
	return -1;
}