#include "Tree.h"  // 包含二叉树相关函数声明

int main()
{
    // 前序遍历数组
    char treeArr[] = "ABD##E#H##CF##G##";
    int pi = 0;
    int n = sizeof(treeArr) / sizeof(treeArr[0]) - 1;  // 去除 '\0'

    // 创建二叉树
    BTNode* root = BinaryTreeCreate(treeArr, n, &pi);

    // 前序遍历
    printf("前序遍历: ");
    BinaryTreePrevOrder(root);
    printf("\n");

    // 中序遍历
    printf("中序遍历: ");
    BinaryTreeInOrder(root);
    printf("\n");

    // 后序遍历
    printf("后序遍历: ");
    BinaryTreePostOrder(root);
    printf("\n");

    // 二叉树节点个数
    printf("二叉树节点总数: %d\n", BinaryTreeSize(root));

    // 二叉树叶子节点个数
    printf("二叉树叶子节点数: %d\n", BinaryTreeLeafSize(root));

    // 二叉树第3层节点个数
    printf("二叉树第3层节点个数: %d\n", BinaryTreeLevelKSize(root, 3));

    // 查找节点
    char findVal = 'E';
    BTNode* foundNode = BinaryTreeFind(root, findVal);
    if (foundNode) {
        printf("找到节点: %c\n", foundNode->_data);
    }
    else {
        printf("未找到节点: %c\n", findVal);
    }

    // 层序遍历
    printf("层序遍历: ");
    BinaryTreeLevelOrder(root);
    printf("\n");

    // 判断是否是完全二叉树
    if (BinaryTreeComplete(root)) {
        printf("该二叉树是完全二叉树\n");
    }
    else {
        printf("该二叉树不是完全二叉树\n");
    }

    // 销毁二叉树
    BinaryTreeDestory(&root);

    return 0;
}