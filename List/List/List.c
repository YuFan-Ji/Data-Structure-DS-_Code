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

//双向链表初始化
//void LTInit(LTNode** pphead)
//{
//	*pphead = LTBuyNode(-1);
//}

//优化让接口统一为 LTNode* phead
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}

//双向链表销毁
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

//优化接口统一为 LTNode* phead，但是需要手动释放让 *plist=NULL;!!!
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

//双向链表打印
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

//双向链表是否为空
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//双向链表尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//双向链表头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//双向链表尾删
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

//双向链表头删
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

//双向链表查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->date == x)
		{
			//找到了
			return pcur;
		}
		pcur = pcur->next;
	}
	//没找到
	return NULL;
}

//双向链表指定位置插入
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//双向链表指定位置删除
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}


