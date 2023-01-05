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

// Ž��(�ݺ�)
TreeNode *search(TreeNode *node, int key)
{
    while(node != NULL){
    if( key == node->key ) return node;
    else if( key < node->key )
        node = node->left;
    else
        node = node->right;
    }
    return NULL; //Ž���� �������� ��� NULL ��ȯ
}

TreeNode *insert_node(TreeNode *root, int key)
{
    TreeNode *p, *t; // p�� �θ���, t�� ������
    TreeNode *n; // n�� ���ο� ���
    t = root;
    p = NULL;
    // Ž���� ���� ����, �ݺ��� �̿��ؼ� search(���� search�Լ� ����)
    while (t != NULL){ // �����尡 NULL�� �ɶ�����
        if( key == t->key ) return root;
        p = t; // �����带 �θ���� �ϰ�
        // �����带 ����
        if( key < t->key )
            t = t->left;
        else
            t = t->right;
    }

    // key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
    n = new_node(key);
    // �θ� ���� ��ũ ����
    if( p != NULL )
        if( key < p->key )
            p->left = n; // n�� ������
        else
            p->right = n;
    else // ���ʿ� Ʈ���� ����־�����
        root = n;
    return root;
} 

// ���� �Լ�
TreeNode *delete_node(TreeNode *root, int key) // ���߿� ROOT <-> *root�� �ٲ�
{
    TreeNode *p, *child, *succ, *succ_p, *t;
    // key�� ���� ��� t�� Ž��, p�� t�� �θ���
    p = NULL;
    t = root;
    // key�� ���� ��� t�� Ž���Ѵ�.
    while( t != NULL && t->key != key ){
        p = t; // �ڽĳ�带 �θ�
        t = ( key < t->key ) ? t->left : t->right; // �ڽĳ�� ����
    }
    // Ž���� ����� ������ t�� NULL�̸� Ʈ���ȿ� key�� ����
    if( t == NULL ) { // Ž��Ʈ���� ���� Ű
        printf("key is not in the tree");
        return root;
    }
    // ù��° ���: �ܸ������ ���
    if( (t->left==NULL) && (t->right==NULL) ){
        if( p != NULL ){
        // �θ����� �ڽ��ʵ带 NULL�� �����.
            if( p->left == t ) // �����Ϸ��� ���� ���� ����̸�
                p->left = NULL;
            else
                p->right = NULL;
        }
        else//p�� NULL�̸�(�� �� �ϳ��� �ܸ� ����̰� �̰� �����Ϸ���) ��Ʈ ����
            root = NULL;
    }
    // �ι�° ���: �ϳ��� �ڽĸ� ������ ���
    else if((t->left==NULL)||(t->right==NULL)){
        child = (t->left != NULL) ? t->left : t->right;
        if( p != NULL ){
            if( p->left == t ) // �θ� �ڽİ� ����
            p->left = child;
            else p->right = child;
        }
        else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
            root = child;
    }
    // ����° ���: �ΰ��� �ڽ��� ������ ���
    else{
        // ������ ����Ʈ������ �İ��ڸ� ã�´�.
        succ_p = t;
        succ = t->right;
        // �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
        while(succ->left != NULL){
            succ_p = succ;
            succ = succ->left;
    }
    // �ļ����� �θ�� �ڽ��� ����
    if( succ_p->left == succ )
        succ_p->left = succ->right;
    else
        succ_p->right = succ->right;
    // �ļ��ڰ� ���� Ű���� ���� ��忡 ����
    t->key = succ->key;
    // ������ �ļ��� ����
    t = succ;
    }
    free(t);
    return root;
} 