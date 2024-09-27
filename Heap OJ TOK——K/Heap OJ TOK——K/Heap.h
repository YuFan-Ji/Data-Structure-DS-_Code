#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义堆的结构---数组

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;//有效的数据个数
	int capacity;//空间大小
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);

HPDataType HPTop(HP* php);
// 判空
bool HPEmpty(HP* php);


void Swap(int* x, int* y);
void AdjustUp(HPDataType* arr, int child);
void AdjustDown(HPDataType* arr, int parent, int n);