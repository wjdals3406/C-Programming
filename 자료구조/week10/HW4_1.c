#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//        root
//         15
//   4            15
// 15           16   25
//
//        root2
//         15
//   4            15
// 15           16   25
//                      28
TreeNode n1={15, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={15, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root= &n6;
TreeNode m1 = {15, NULL, NULL};
TreeNode m2 = {4, &m1, NULL};
TreeNode m3 = {16, NULL, NULL};
TreeNode m7 = {28, NULL, NULL};
TreeNode m4 = {25, NULL, &m7};
TreeNode m5 = {15, &m3, &m4};
TreeNode m6 = {15, &m2, &m5};
TreeNode *root2= &m6;


int get_nonleaf_count(TreeNode *t)
{
    if( t == NULL ) 
        return 0;

    else if( t != NULL){
        if(t->left != NULL || t->right != NULL)
            return (1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right));
        else // t->left == NULL && t->right == NULL
            return 0;
    }
}

int get_leaf_count(TreeNode *t)
{
    if (t == NULL)
        return 0;

    else if (t != NULL){
        if(t->left == NULL && t->right == NULL)
            return 1;
        else
            return (get_leaf_count(t->left) + get_leaf_count(t->right));
    }
}

//p319 #16
// int get_oneleaf_count(TreeNode *node) {
//     int count = 0;

//     if( node == NULL ) //t가 NULL이면
//         return 0;
//     else{
//         if((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL)){
//             count = 1 + get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
//         }
//         else //
//             count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
//     }
//     return count;
// }

int get_oneleaf_count(TreeNode *node){
    if (!node){
        return 0;
    }
    else{
        if((node->left==NULL && node->right !=NULL) || node->left!=NULL && node->right ==NULL)
            return 1 + get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
        else
            return get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
    }
}

int get_twoleaf_count(TreeNode *node) {
    int count = 0;

    if( !node ) //t가 NULL이면
        return count;
    else if( node->left != NULL && node->right != NULL){
        count = 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
    }
    else
        count = get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
    return count;

}

//p290 Quiz 03
int equal(TreeNode *t1, TreeNode *t2) {
    if(t1==NULL && t2==NULL) {
  	    return 1;
    }
    if((t1==NULL && t2!=NULL) || t1!=NULL && t2==NULL) {
        return 0;
    }
    if(t1->data != t2->data) {
        return 0;
    }

    return equal(t1->left, t2->left) && equal(t1->right, t2->right);
}


//p319 #17
int get_max(TreeNode *node) {
    if (node != NULL){
        int max = node->data;
        int left_max = get_max(node->left);
        int right_max = get_max(node->right);
        if (left_max > right_max && left_max > max)
            max = left_max;
        else if (right_max >= left_max && right_max > max)
            max = right_max;

        return max;
    }
}

int get_min(TreeNode *node) {
    if (!node)
        return 987654321;
    if (node != NULL){
        int min = node->data;
        int left_min = get_min(node->left);
        int right_min = get_min(node->right);
        if (left_min < right_min && left_min < min)
            min = left_min;
        else if (right_min <= left_min && right_min < min)
            min = right_min;

        return min;
    }
}
//p319 #20
void node_increase(TreeNode *node) {
    if (node != NULL){
        node->data = node->data + 1;
        node_increase(node->left);
        node_increase(node->right);
    }
}
void preorder(TreeNode *root) // p274 코드 복사
{
    if(root != NULL){
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

TreeNode* copy(TreeNode *root)
{
    TreeNode *temp;
    if(root){
        temp = (TreeNode *) malloc(sizeof(TreeNode));
        temp->left = copy(root->left);
        temp->right = copy(root->right);
        temp->data = root->data;
        return temp;
    }
    return NULL;
}

int main(void)
{
    TreeNode *result[MAX_TREE_SIZE];
    TreeNode *clone;
    int i, num;
    printf("가)\n");
    printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
    printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));

    printf("트리 root 중 단말노드의 개수는 %d.\n", get_leaf_count(root));
    printf("트리 root2 중 단말노드의 개수는 %d.\n", get_leaf_count(root2));

    printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
    printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
    printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
    printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
    printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
    printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
    printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
    printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
    printf("\n 나)\n");
    preorder(root);
    node_increase(root);
    printf("\n");
    preorder(root);
    printf("\n");
    printf("%s\n", equal(root, root) ? "같다": "다르다");
    printf("%s\n", equal(root2, root2) ? "같다": "다르다");
    printf("%s\n", equal(root, root2) ? "같다": "다르다");
    printf("\n 다)\n");
    clone = copy(root) ;
    preorder(root) ;
    printf("\n");
    preorder(clone) ;
    printf("\n");
} 