//��ȯȣ��� ���� ��� ���� ����Ʈ�� �����ϱ�
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    int is_thread; // �ܸ����� ��ܸ����� ���� / �ļ��ڸ� ����� ������� �ƴ����� ����
} TreeNode;
// is_thread True : �ļ��� ��������� �� -> �̰ŷ� ���ؼ� right�� ���� �ڽĳ������ �ƴϸ� �ļ��������� �˰Ե�
// is_thread False : �ļ��� ���������� �ʾƵ� ��
//          7
//      3       6
//    1   2   4   5
//
TreeNode n9 = { 9, NULL, NULL, 1 };
TreeNode n10 = { 10, NULL, NULL, 0 };
TreeNode n1 = { 1, NULL, NULL, 1 }; // �ܸ� / n1�� �ܸ����� ���� �����ϴ��� �˷���� ��
TreeNode n2 = { 2, NULL, NULL, 1 }; // �ܸ� 
TreeNode n3 = { 3, &n1, &n2, 0 };
TreeNode n4 = { 4, NULL, NULL, 1 }; // �ܸ�
TreeNode n5 = { 5, &n9, &n10, 0 }; // �ܸ������� ���� ��ȸ�� ������ ����̹Ƿ� 0����
TreeNode n6 = { 6, &n4, &n5, 0 };
TreeNode n7 = { 7, &n3, &n6, 0 };
TreeNode *e = &n7;

// ���� ������ȸ ������� �� ��������, ��������� ������ ����� is_thread�� Ȯ���Ͽ� ����� ���� ������ �װ����� ��
//p�� ���� �ļ� ��带 �����Ѵ�. / ���� �ļ��ڸ� ã����
TreeNode *find_thread_successor(TreeNode *p)
{
    TreeNode *q = p->right; 

    if (q == NULL || p->is_thread == TRUE) //1, 3�� / q�� �ļ���
        return q; //�ļ��� return

    //������ ���� �Դµ�,���� child�� ������ �������� ���� ������
    while (q->left != NULL) q = q->left;
    return q;
}
void thread_inorder(TreeNode *t)
{
    TreeNode *q;
    q = t;
    // �ϴ� ���� ��ȸ�� ù ���� �̵�
    while (q->left) q = q->left; // ���� ���� child�� �� ������
    do
    {
        printf("%d ", q->data);
        q = find_thread_successor(q);
    } while (q);
}
void main()
{
// �ܸ� ����� ������ ��ũ�� ���� �ļ� ��带 �����Ѵ�
    n1.right = &n3; //���� ȭ��ǥ�� ����� ���
    n2.right = &n7; 
    n4.right = &n6;
    n9.right = &n5;
    thread_inorder(e);
} 