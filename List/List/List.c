#include"List.h"

LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->date = x;
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}

//˫�������ʼ��
//void LTInit(LTNode** pphead)
//{
//	*pphead = LTBuyNode(-1);
//}

//�Ż��ýӿ�ͳһΪ LTNode* phead
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}

//˫����������
void LTDesTory(LTNode** pphead)
{
	assert(pphead && *pphead);
	LTNode* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		LTNode* Next = pcur->next;
		free(pcur);
		pcur = Next;
	}
	free(*pphead);
	*pphead = NULL;
	pcur = NULL;
}

//�Ż��ӿ�ͳһΪ LTNode* phead��������Ҫ�ֶ��ͷ��� *plist=NULL;!!!
void LTDesTory2(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = (phead)->next;
	while (pcur != phead)
	{
		LTNode* Next = pcur->next;
		free(pcur);
		pcur = Next;
	}
	free(phead);
	phead = NULL;
	pcur = NULL;
}

//˫�������ӡ
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->date);
		pcur = pcur->next;
	}
	printf("\n");
}

//˫�������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//˫������β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//˫������ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//˫������βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode* del = phead->prev;
	LTNode* prev = del->prev;
	prev->next = phead;
	phead->prev = prev;
	free(del);
	del = NULL;
}

//˫������ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}

//˫���������
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->date == x)
		{
			//�ҵ���
			return pcur;
		}
		pcur = pcur->next;
	}
	//û�ҵ�
	return NULL;
}

//˫������ָ��λ�ò���
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//˫������ָ��λ��ɾ��
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}


