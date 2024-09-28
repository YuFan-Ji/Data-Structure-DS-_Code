#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


//定义二叉树的链式结构
//二叉树结点的结构

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;         //左孩子
	struct BinaryTreeNode* right;        //右孩子
}BTNode;


//前序遍历
void PreOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历 
void PostOrder(BTNode* root);

// ⼆叉树结点个数
int BinaryTreeSize(BTNode* root);

// ⼆叉树叶⼦结点个数
int BinaryTreeLeafSize(BTNode* root);

// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode* root);

// ⼆叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ⼆叉树销毁
void BinaryTreeDestroy(BTNode** root);

//层序遍历
void LevelOrder(BTNode* root);

//判断二叉树是否为完全二叉树
bool BinaryTreeComplete(BTNode* root);