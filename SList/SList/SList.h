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


//����Ĵ�ӡ
void SLTPrint(SLTNode* phead);

//�����½ڵ�
SLTNode* SLTBuyNode(SLTDataType);

//����β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//����ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//����βɾ
void SLTPopBack(SLTNode** pphead);

//����ͷɾ
void SLTPopFront(SLTNode** pphead);

//�������
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead,SLTNode* pos, SLTDataType x);

//ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//ɾ��ָ��λ�õĽڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);

//ɾ��ָ��λ��֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos);

//��������
void SLTDestroy(SLTNode** pphead);