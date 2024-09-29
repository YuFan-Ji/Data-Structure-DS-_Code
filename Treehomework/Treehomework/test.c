#include "Tree.h"  // ������������غ�������

int main()
{
    // ǰ���������
    char treeArr[] = "ABD##E#H##CF##G##";
    int pi = 0;
    int n = sizeof(treeArr) / sizeof(treeArr[0]) - 1;  // ȥ�� '\0'

    // ����������
    BTNode* root = BinaryTreeCreate(treeArr, n, &pi);

    // ǰ�����
    printf("ǰ�����: ");
    BinaryTreePrevOrder(root);
    printf("\n");

    // �������
    printf("�������: ");
    BinaryTreeInOrder(root);
    printf("\n");

    // �������
    printf("�������: ");
    BinaryTreePostOrder(root);
    printf("\n");

    // �������ڵ����
    printf("�������ڵ�����: %d\n", BinaryTreeSize(root));

    // ������Ҷ�ӽڵ����
    printf("������Ҷ�ӽڵ���: %d\n", BinaryTreeLeafSize(root));

    // ��������3��ڵ����
    printf("��������3��ڵ����: %d\n", BinaryTreeLevelKSize(root, 3));

    // ���ҽڵ�
    char findVal = 'E';
    BTNode* foundNode = BinaryTreeFind(root, findVal);
    if (foundNode) {
        printf("�ҵ��ڵ�: %c\n", foundNode->_data);
    }
    else {
        printf("δ�ҵ��ڵ�: %c\n", findVal);
    }

    // �������
    printf("�������: ");
    BinaryTreeLevelOrder(root);
    printf("\n");

    // �ж��Ƿ�����ȫ������
    if (BinaryTreeComplete(root)) {
        printf("�ö���������ȫ������\n");
    }
    else {
        printf("�ö�����������ȫ������\n");
    }

    // ���ٶ�����
    BinaryTreeDestory(&root);

    return 0;
}