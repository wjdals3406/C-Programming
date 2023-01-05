#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

//������ ���� Ÿ�� ���� 
typedef TreeNode* element;

typedef struct StackNode {
	element data;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;


// �ʱ�ȭ �Լ�
void init(LinkedStackType *s)
{
    s->top = NULL; //ó������ ��尡 ���� ����
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType *s) // Stack �������� �ϳ��� ���ܵξ����� �׻� ������ ��ȯ. �� �� ������ ���� ����
{
    return 0;
}
// ���� �Լ�
void push(LinkedStackType *s, element item) 
{
    StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
    if( temp == NULL ){
        fprintf(stderr, "�޸� �Ҵ翡��\n");
        return;
    }
    else{
        temp->data = item;
        temp->link = s->top;
        s->top = temp;
    }
}


// ���� �Լ�
element pop(LinkedStackType *s)
{
    if( is_empty(s) ) {
        fprintf(stderr, "������ �������\n");
        exit(1);
    }
    else{
        StackNode *temp=s->top; //temp�� s�� ù��° ����� �ּ�
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

	printf("���� ��ȸ=");
	inorder_iter(root, &s);
	printf("\n");
	
	return 0;
}


