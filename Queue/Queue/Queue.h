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
	int size;         //记录队列的元素个数
}Queue;


//队列的初始化
void QueueInit(Queue* pq);

//入队列
void QueuePush(Queue* pq, QDataType x);

//出队列
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//取队列元素个数
int QueueSize(Queue* pq);

//队列销毁
void QueueDestroy(Queue* pq);

//队列判空
bool QueueEmpty(Queue* pq);
