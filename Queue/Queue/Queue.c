#include"Queue.h"

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//入队列
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
	//申请成功
	newnode->data = x;
	newnode->next = NULL;
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL && pq->ptail == NULL;
}

//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));
	//只有一个结点的情况
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//有多个节点的情况
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

//取队列元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

//队列销毁
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