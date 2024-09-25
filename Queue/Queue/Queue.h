#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;         //��¼���е�Ԫ�ظ���
}Queue;


//���еĳ�ʼ��
void QueueInit(Queue* pq);

//�����
void QueuePush(Queue* pq, QDataType x);

//������
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

//ȡ����Ԫ�ظ���
int QueueSize(Queue* pq);

//��������
void QueueDestroy(Queue* pq);

//�����п�
bool QueueEmpty(Queue* pq);
