#include"Tree.h"
#include"Queue.h"

//前序遍历 ------根左右
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历------左根右
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//后序遍历------左右根
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// ⼆叉树结点个数
// 一个结点的个数等于其左右子树结点个数之和加上它本身
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// ⼆叉树叶⼦结点个数
// 二叉树叶子结点的个数等于二叉树左右子树叶子结点的个数之和
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	if (root->left == NULL && root->right == NULL)   //判断为是叶子结点
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ⼆叉树第k层结点个数
// ⼆叉树第k层结点个数等于左右子树第K层的结点个数和
// 注意是K == 1
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// ⼆叉树的深度/⾼度
// 二叉树的深度要分别比较左右子树最深的那一个
// 每一个结点的深度都等于其左右子树中最深的那个
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// ⼆叉树查找值为x的结点
// 左根右的方式找
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* leftFind = BinaryTreeFind(root->left, x);
	if (leftFind)
	{
		return leftFind;
	}

	BTNode* rightFind = BinaryTreeFind(root->right, x);
	if (rightFind)
	{
		return rightFind;
	}

	return NULL;
}

// ⼆叉树销毁
// 以左右根的方式销毁
// 根被销毁了因此要传二级指针
void BinaryTreeDestroy(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	BinaryTreeDestroy(&((*root)->left));
	BinaryTreeDestroy(&((*root)->right));
	free(*root);
	*root = NULL;
}

// 层序遍历
// 层序遍历需要借助队列，根出队，左右子树放入其中，直到一个左右子树都为空
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//先插入根结点
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	QueueDestroy(&q);
}

//判断二叉树是否为完全二叉树
//---借助队列，不管他的孩子是不是空都放到队列中，满二叉树结束时一定队列里全为空
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//队列不一定为空
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}