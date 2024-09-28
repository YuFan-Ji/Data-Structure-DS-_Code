#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义队列结构
//typedef int QDataType;
typedef struct BinaryTreeNode* QDataType;
//typedef struct BTNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;//保存队列有效数据个数
}Queue;

void QueueInit(Queue* pq);
// ⼊队列，队尾
void QueuePush(Queue* pq, QDataType x);
// 出队列，队头
void QueuePop(Queue* pq);

//队列判空
bool QueueEmpty(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
//队列有效元素个数
int QueueSize(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);