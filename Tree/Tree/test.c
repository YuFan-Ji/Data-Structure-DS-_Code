#include"Tree.h"

BTNode* buyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;

	return newnode;
}

void test01()
{
	BTNode* node1 = buyNode(1);
	BTNode* node2 = buyNode(2);
	BTNode* node3 = buyNode(3);
	BTNode* node4 = buyNode(4);
	//BTNode* node5 = buyNode(5);
	//BTNode* node6 = buyNode(6);

	node1->left = node2;
	node1->right = node3;
	node2->right = node4;
	//node2->right = node5;
	//node3->left = node6;


	//PreOrder(node1);
	//printf("\n");
	//InOrder(node1);
	//printf("\n");
	//PostOrder(node1);

	//int size = 0;
	//BinaryTreeSize(node1, &size);
	//printf("size : %d\n", size);
	////size = 0;
	//BinaryTreeSize(node1, &size);
	//printf("size : %d\n", size);

	//printf("size:%d\n", BinaryTreeSize(node1));
	//printf("size:%d\n", BinaryTreeSize(node1));

	//printf("size:%d\n", BinaryTreeSize(node1));
	//printf("leaf size: %d\n", BinaryTreeLeafSize(node1));
	//printf("第K层size : %d\n", BinaryTreeLevelKSize(node1, 2));
	//printf("depth/height:%d\n", BinaryTreeDepth(node1));

	//BTNode* find =BinaryTreeFind(node1, 33);
	//printf("%s\n", find == NULL ? "未找到！" : "找到了！");

	//LevelOrder(node1);

	bool ret = BinaryTreeComplete(node1);
	printf("%s\n", ret == false ? "不是完全二叉树" : "是完全二叉树");

	BinaryTreeDestroy(&node1);
}

int main()
{
	test01();
	return 0;
}