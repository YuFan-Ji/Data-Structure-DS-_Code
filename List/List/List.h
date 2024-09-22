#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType date;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//双向链表初始化
//void LTInit(LTNode** pphead);

//优化让接口统一为 LTNode* phead
LTNode* LTInit();

//双向链表销毁
void LTDesTory(LTNode** pphead);

//优化接口统一为 LTNode* phead，但是需要手动释放让 *plist=NULL;
void LTDesTory2(LTNode* phead);

//双向链表打印
void LTPrint(LTNode* phead);

//双向链表是否为空
bool LTEmpty(LTNode* phead);

//双向链表尾插
void LTPushBack(LTNode* phead, LTDataType x);

//双向链表头插
void LTPushFront(LTNode* phead, LTDataType x);

//双向链表尾删
void LTPopBack(LTNode* phead);

//双向链表头删
void LTPopFront(LTNode* phead);

//双向链表查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//双向链表指定位置插入
void LTInsert(LTNode* pos, LTDataType x);

//双向链表指定位置删除
void LTErase(LTNode* pos);

