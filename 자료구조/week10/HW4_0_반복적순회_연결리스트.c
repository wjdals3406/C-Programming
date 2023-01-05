#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

//스택을 위한 타입 정의 
typedef TreeNode* element;

typedef struct StackNode {
	element data;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;


// 초기화 함수
void init(LinkedStackType *s)
{
    s->top = NULL; //처음에는 노드가 없기 때문
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType *s) // Stack 연산중의 하나라 남겨두었지만 항상 거짓을 반환. 즉 꽉 차있을 때는 없음
{
    return 0;
}
// 삽입 함수
void push(LinkedStackType *s, element item) 
{
    StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
    if( temp == NULL ){
        fprintf(stderr, "메모리 할당에러\n");
        return;
    }
    else{
        temp->data = item;
        temp->link = s->top;
        s->top = temp;
    }
}


// 삭제 함수
element pop(LinkedStackType *s)
{
    if( is_empty(s) ) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else{
        StackNode *temp=s->top; //temp는 s의 첫번째 노드의 주소
        element data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

void inorder_iter(TreeNode *root, LinkedStackType *s)
{
	while(1){
		for(; root; root = root->left)
			push(s, root);
		root = pop(s);

		if(!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}
 
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };

TreeNode *root = &n6;

int main(void)
{
    LinkedStackType s;
    init(&s);

	printf("중위 순회=");
	inorder_iter(root, &s);
	printf("\n");
	
	return 0;
}


