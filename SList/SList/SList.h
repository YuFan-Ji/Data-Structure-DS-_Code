#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SLTNode
{
	SLTDataType date;
	struct SLTNode* next;
}SLTNode;


//链表的打印
void SLTPrint(SLTNode* phead);

//申请新节点
SLTNode* SLTBuyNode(SLTDataType);

//链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//链表头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//链表尾删
void SLTPopBack(SLTNode** pphead);

//链表头删
void SLTPopFront(SLTNode** pphead);

//链表查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//指定位置之前插入数据
void SLTInsert(SLTNode** pphead,SLTNode* pos, SLTDataType x);

//指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//删除指定位置的节点
void SLTErase(SLTNode** pphead, SLTNode* pos);

//删除指定位置之后的节点
void SLTEraseAfter(SLTNode* pos);

//销毁链表
void SLTDestroy(SLTNode** pphead);