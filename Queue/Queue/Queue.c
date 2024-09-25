#include"Queue.h"

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//�����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//�����½ڵ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	//����ɹ�
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

//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL && pq->ptail == NULL;
}

//������
void QueuePop(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));
	//ֻ��һ���������
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//�ж���ڵ�����
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

//ȡ����Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

//��������
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