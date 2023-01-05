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
void inorder(TreeNode * root) { // 중위 순회
    if (root) {
        inorder(root->left);// 왼쪽서브트리 순회
        printf("[%d] ", root->key); // 노드 방문
        inorder(root->right);// 오른쪽서브트리 순회
    }
}

// 탐색(반복)
TreeNode *search(TreeNode *node, int key)
{
    while(node != NULL){
    if( key == node->key ) return node;
    else if( key < node->key )
        node = node->left;
    else
        node = node->right;
    }
    return NULL; //탐색에 실패했을 경우 NULL 반환
}

TreeNode *insert_node(TreeNode *root, int key)
{
    TreeNode *p, *t; // p는 부모노드, t는 현재노드
    TreeNode *n; // n은 새로운 노드
    t = root;
    p = NULL;
    // 탐색을 먼저 수행, 반복을 이용해서 search(위의 search함수 참조)
    while (t != NULL){ // 현재노드가 NULL이 될때까지
        if( key == t->key ) return root;
        p = t; // 현재노드를 부모노드로 하고
        // 현재노드를 전진
        if( key < t->key )
            t = t->left;
        else
            t = t->right;
    }

    // key가 트리 안에 없으므로 삽입 가능
    n = new_node(key);
    // 부모 노드와 링크 연결
    if( p != NULL )
        if( key < p->key )
            p->left = n; // n도 포인터
        else
            p->right = n;
    else // 애초에 트리가 비어있었으면
        root = n;
    return root;
} 

// 삭제 함수
TreeNode *delete_node(TreeNode *root, int key) // 나중에 ROOT <-> *root로 바꿈
{
    TreeNode *p, *child, *succ, *succ_p, *t;
    // key를 갖는 노드 t를 탐색, p는 t의 부모노드
    p = NULL;
    t = root;
    // key를 갖는 노드 t를 탐색한다.
    while( t != NULL && t->key != key ){
        p = t; // 자식노드를 부모가
        t = ( key < t->key ) ? t->left : t->right; // 자식노드 전진
    }
    // 탐색이 종료된 시점에 t가 NULL이면 트리안에 key가 없음
    if( t == NULL ) { // 탐색트리에 없는 키
        printf("key is not in the tree");
        return root;
    }
    // 첫번째 경우: 단말노드인 경우
    if( (t->left==NULL) && (t->right==NULL) ){
        if( p != NULL ){
        // 부모노드의 자식필드를 NULL로 만든다.
            if( p->left == t ) // 삭제하려는 것이 왼쪽 노드이면
                p->left = NULL;
            else
                p->right = NULL;
        }
        else//p가 NULL이면(즉 단 하나의 단말 노드이고 이걸 삭제하려면) 루트 삭제
            root = NULL;
    }
    // 두번째 경우: 하나의 자식만 가지는 경우
    else if((t->left==NULL)||(t->right==NULL)){
        child = (t->left != NULL) ? t->left : t->right;
        if( p != NULL ){
            if( p->left == t ) // 부모를 자식과 연결
            p->left = child;
            else p->right = child;
        }
        else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
            root = child;
    }
    // 세번째 경우: 두개의 자식을 가지는 경우
    else{
        // 오른쪽 서브트리에서 후계자를 찾는다.
        succ_p = t;
        succ = t->right;
        // 후계자를 찾아서 계속 왼쪽으로 이동한다.
        while(succ->left != NULL){
            succ_p = succ;
            succ = succ->left;
    }
    // 후속자의 부모와 자식을 연결
    if( succ_p->left == succ )
        succ_p->left = succ->right;
    else
        succ_p->right = succ->right;
    // 후속자가 가진 키값을 현재 노드에 복사
    t->key = succ->key;
    // 원래의 후속자 삭제
    t = succ;
    }
    free(t);
    return root;
} 