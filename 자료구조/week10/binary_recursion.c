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

//탐색(순환)
TreeNode *search(TreeNode *node, int key)
{
    if( node == NULL ) return NULL;
    if( key == node->key ) return node;
    else if( key < node->key )
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode * insert_node(TreeNode * root, int key)  //왼쪽에 삽입해야 하는지 오른쪽에 삽입해야 하는지 체크
{
    // 트리가 공백이면 새로운 노드를 반환한다.
    if (root == NULL) return new_node(key);
    // 그렇지 않으면 순환적으로 트리를 내려간다.
    if (key < root->key)
        root->left = insert_node(root->left, key);
    else if (key > root->key)
        root->right = insert_node(root->right, key);

    return root;// 변경된 루트 포인터를 반환 / 삽입할 자리의 부모 노드
}

TreeNode * min_value_node(TreeNode * node) //오른쪽에서 가장 작은 값 : 왼쪽으로 쭈욱 따라 들어가면 됨
{
    TreeNode * current = node;
    while (current->left != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감
        current = current->left;
    return current;
}

// 삭제 함수
TreeNode * delete_node(TreeNode * root, int key) 
{
    TreeNode *temp;
    if (root == NULL) return root;
    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
    if (key < root->key)
        root->left = delete_node(root->left, key);
    // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    // 키가 루트와 같으면 이 노드를 삭제하면 됨
    else {
    // 첫 번째나 두 번째 경우
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
    // 세 번째 경우 child가 두개 이상 -> child 찾아가야함
    temp = min_value_node(root->right); //오른쪽 서브트리의 가장 작은 값
    //오른쪽 서브트리에서 가져오거나, 왼쪽 서브트리에서 가져오거나
    //오른쪽 서브트리의 가장 작은 값을 가져오거나, 왼쪽 서브트리에서 가장 큰 값을 가져오거나

    // 중외 순회시 후계 노드를 복사한다.
    root->key = temp->key; //루트에 값이 복사되고, 현재노드를 삭제함
    // 중외 순회시 후계 노드를 삭제한다.
    root->right = delete_node(root->right, temp->key); //삭제되는 노드가 리프노드가 아닐 경우 자식 노드를 위로 올려보내 주기 위해
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
    printf("이진 탐색 트리 중위 순회 결과 \n");
    preorder(root);
    inorder(root);
    postorder(root);
    printf("\n\n");
    if (search(root, 30) != NULL)
        printf("이진 탐색 트리에서 30을 발견함 \n");
    else
        printf("이진 탐색 트리에서 30을 발견못함 \n");
    root = delete_node(root, 50);
    inorder(root);
    return 0;
}