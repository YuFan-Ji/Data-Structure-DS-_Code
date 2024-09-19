#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;   //将顺序表中储存元素的类型命名为SLDataType,方便后续统一替换

//动态顺序表
typedef struct Seqlist
{
	SLDataType* arr;
	int size;        //有效数据的多少
	int capacity;    //顺序表空间的大小
}SL;

//初始化顺序表
void SLInit(SL* ps);       

//顺序表的销毁
void SLDestroy(SL* ps);

//顺序表打印
void SLPrint(SL ps);

//顺序表的头部插入/顺序表的尾部插入
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

//顺序表的头部删除/顺序表的尾部删除
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//顺序表指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//顺序表查找
int SLFind(SL* ps, SLDataType x);

