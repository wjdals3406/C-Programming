#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode * new_node(int item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(TreeNode * root) { // ���� ��ȸ
    if (root) {
        inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
        printf("[%d] ", root->key); // ��� �湮
        inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
    }
}
void preorder(TreeNode * root){
    if(root){
        printf("%d ", root->key);
        inorder(root->left);
        inorder(root->right);
    }
}

void posteorder(TreeNode * root){
    if(root){
        printf("%d ", root->key);
        inorder(root->left);
        inorder(root->right);
    }
}

//Ž��(��ȯ)
TreeNode *search(TreeNode *node, int key)
{
    if( node == NULL ) return NULL;
    if( key == node->key ) return node;
    else if( key < node->key )
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode * insert_node(TreeNode * root, int key)  //���ʿ� �����ؾ� �ϴ��� �����ʿ� �����ؾ� �ϴ��� üũ
{
    // Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
    if (root == NULL) return new_node(key);
    // �׷��� ������ ��ȯ������ Ʈ���� ��������.
    if (key < root->key)
        root->left = insert_node(root->left, key);
    else if (key > root->key)
        root->right = insert_node(root->right, key);

    return root;// ����� ��Ʈ �����͸� ��ȯ / ������ �ڸ��� �θ� ���
}

TreeNode * min_value_node(TreeNode * node) //�����ʿ��� ���� ���� �� : �������� �޿� ���� ���� ��
{
    TreeNode * current = node;
    while (current->left != NULL) // �� ���� �ܸ� ��带 ã���� ������
        current = current->left;
    return current;
}

// ���� �Լ�
TreeNode * delete_node(TreeNode * root, int key) 
{
    TreeNode *temp;
    if (root == NULL) return root;
    // ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
    if (key < root->key)
        root->left = delete_node(root->left, key);
    // ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    // Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
    else {
    // ù ��°�� �� ��° ���
        if (root->left == NULL) {
            TreeNode * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
    // �� ��° ��� child�� �ΰ� �̻� -> child ã�ư�����
    temp = min_value_node(root->right); //������ ����Ʈ���� ���� ���� ��
    //������ ����Ʈ������ �������ų�, ���� ����Ʈ������ �������ų�
    //������ ����Ʈ���� ���� ���� ���� �������ų�, ���� ����Ʈ������ ���� ū ���� �������ų�

    // �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
    root->key = temp->key; //��Ʈ�� ���� ����ǰ�, �����带 ������
    // �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
    root->right = delete_node(root->right, temp->key); //�����Ǵ� ��尡 ������尡 �ƴ� ��� �ڽ� ��带 ���� �÷����� �ֱ� ����
    }
    return root;
} 

int main(void)
{
    TreeNode * root = NULL;
    TreeNode * tmp = NULL;
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);
    root = insert_node(root, 45);
    printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
    preorder(root);
    inorder(root);
    postorder(root);
    printf("\n\n");
    if (search(root, 30) != NULL)
        printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
    else
        printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
    root = delete_node(root, 50);
    inorder(root);
    return 0;
}