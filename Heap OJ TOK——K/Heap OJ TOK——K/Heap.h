#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//����ѵĽṹ---����

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;//��Ч�����ݸ���
	int capacity;//�ռ��С
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);

HPDataType HPTop(HP* php);
// �п�
bool HPEmpty(HP* php);


void Swap(int* x, int* y);
void AdjustUp(HPDataType* arr, int child);
void AdjustDown(HPDataType* arr, int parent, int n);