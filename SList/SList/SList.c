#include"SList.h"

//打印链表
void SLTPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* pcur;
	pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->date);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//申请新节点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* node = (SLTNode* )malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc file!");
		exit(1);
	}
	node->date = x;
	node->next = NULL;
	return node;
}

//链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

//链表头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
		newnode->next = *pphead;
		*pphead = newnode;
}

//链表尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//处理只有一个节点的情况
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* ptail = *pphead;
		SLTNode* prev = NULL;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//链表头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead&& *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//链表查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->date == x)
		{
			return pcur;
		}
		else
		{
			pcur = pcur->next;
		}
	}
	//没有找到
	return NULL;
}

//指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next!=pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}

//指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode; 
}

//删除指定位置的节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除指定位置之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos&&pos->next);
	SLTNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

//销毁链表
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}