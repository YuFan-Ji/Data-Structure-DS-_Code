#include"SeqList.h"

//˳����ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//˳��������
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->size = ps->capacity = 0;
	}
}

//˳����ӡ
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}

//�鿴�ռ��Ƿ���Ҫ����
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//����ռ�(������realloc)
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

//β��             
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//��������ǰ�ȿ��ռ乻����
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//��������ǰ�ȿ��ռ乻����
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

//ͷɾ
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

//��ָ��λ��ǰ����
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

//ɾ��ָ��λ�õ�����
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

//˳���Ĳ���
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->arr[i])
		{
			//�ҵ���
			return i;
		}
	}
	//û�ҵ�
	return -1;
}