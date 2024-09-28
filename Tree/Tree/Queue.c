#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
// ⼊队列，队尾
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//申请新节点
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	//ptail newnode
	if (pq->phead == NULL)
	{//队列为空
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		//队列不为空
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;//newnode
	}
	pq->size++;
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL && pq->ptail == NULL;
}

// 出队列，队头
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	//只有一个结点的情况，避免ptail变成野指针
	if (pq->ptail == pq->phead)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//删除队头元素、
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	--pq->size;
}
//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}
//队列有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	/*int size = 0;
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		size++ ;
		pcur = pcur->next;
	}
	return size;*/
	return pq->size;
}

//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));

	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}