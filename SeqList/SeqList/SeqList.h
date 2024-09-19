#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;   //��˳����д���Ԫ�ص���������ΪSLDataType,�������ͳһ�滻

//��̬˳���
typedef struct Seqlist
{
	SLDataType* arr;
	int size;        //��Ч���ݵĶ���
	int capacity;    //˳���ռ�Ĵ�С
}SL;

//��ʼ��˳���
void SLInit(SL* ps);       

//˳��������
void SLDestroy(SL* ps);

//˳����ӡ
void SLPrint(SL ps);

//˳����ͷ������/˳����β������
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

//˳����ͷ��ɾ��/˳����β��ɾ��
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//˳���ָ��λ��֮ǰ����/ɾ������
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//˳������
int SLFind(SL* ps, SLDataType x);

