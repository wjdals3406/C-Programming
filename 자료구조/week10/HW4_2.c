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

void preorder(TreeNode* root){
    if (root) {
        printf("%d ", root->key);    
        preorder(root->left);    
        preorder(root->right);    
    }
}

int get_node_count(TreeNode *node)
{
    int count=0;

    if( node != NULL )
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    return count;
}

int get_height(TreeNode *node)
{
    int height = 0;

    if( node != NULL ){
        height = 1 + ( get_height(node->left) > get_height(node->right) ? get_height(node->left):get_height(node->right) );
    }
    return height;
}

TreeNode *search(TreeNode *node, int key)
{
    if( node == NULL ) return NULL;
    if( key == node->key ) return node;
    else if( key < node->key )
        return search(node->left, key);
    else
        return search(node->right, key);
}


TreeNode * insert_node(TreeNode * root, int key)  
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
    temp = min_value_node(root->right); 
    root->key = temp->key; 
    root->right = delete_node(root->right, temp->key); 
    }
    return root;
} 


int get_maximum(TreeNode *node) {
    if (node != NULL){
        int max = node->key;
        int left_max = get_maximum(node->left);
        int right_max = get_maximum(node->right);
        if (left_max > right_max && left_max > max)
            max = left_max;
        else if (right_max >= left_max && right_max > max)
            max = right_max;

        return max;
    }
}

int get_minimum(TreeNode *node) {
    if (!node)
        return 987654321;
    if (node != NULL){
        int min = node->key;
        int left_min = get_minimum(node->left);
        int right_min = get_minimum(node->right);
        if (left_min < right_min && left_min < min)
            min = left_min;
        else if (right_min <= left_min && right_min < min)
            min = right_min;

        return min;
    }
}

int main(void)
{
    TreeNode * root = NULL;
    char ch;
    int key;

    do{
        printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, n<min>, q<uit>:");
        scanf(" %c", &ch);
        if (ch == 'i'){
            printf("삽입할 key값 입력:");
            scanf("%d", &key);
            root = insert_node(root, key);
        }
        else if (ch == 'h'){
            printf("트리의 높이는 %d\n", get_height(root));
        }
        else if (ch == 'c'){
            printf("노드의 개수는 %d\n", get_node_count(root));
        }
        else if (ch == 'p'){
            preorder(root);
            printf("\n");
        }
        else if (ch == 'd'){
            printf("삭제할 key값 입력:");
            scanf("%d", &key);
            root = delete_node(root, key);
        }
        else if (ch == 's'){
            printf("탐색할 key값 입력:");
            scanf("%d", &key);
            if (search(root, key) != NULL)
                printf("있음\n");
            else
                printf("없음\n");

        }
        else if (ch == 'm'){
            printf("가장 큰 값은 %d\n", get_maximum(root));
        }
        else if (ch == 'n'){
            printf("가장 작은 값은 %d\n", get_minimum(root));
        }
        
    } while(ch != 'q');

    return 0;
}