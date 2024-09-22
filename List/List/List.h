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

//˫�������ʼ��
//void LTInit(LTNode** pphead);

//�Ż��ýӿ�ͳһΪ LTNode* phead
LTNode* LTInit();

//˫����������
void LTDesTory(LTNode** pphead);

//�Ż��ӿ�ͳһΪ LTNode* phead��������Ҫ�ֶ��ͷ��� *plist=NULL;
void LTDesTory2(LTNode* phead);

//˫�������ӡ
void LTPrint(LTNode* phead);

//˫�������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead);

//˫������β��
void LTPushBack(LTNode* phead, LTDataType x);

//˫������ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

//˫������βɾ
void LTPopBack(LTNode* phead);

//˫������ͷɾ
void LTPopFront(LTNode* phead);

//˫���������
LTNode* LTFind(LTNode* phead, LTDataType x);

//˫������ָ��λ�ò���
void LTInsert(LTNode* pos, LTDataType x);

//˫������ָ��λ��ɾ��
void LTErase(LTNode* pos);

