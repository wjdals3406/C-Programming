//���Ḯ��Ʈ�� ������ ����
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
// ������ ���� Ÿ�� ����
typedef int element;

typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;//top�� ���Ḯ��Ʈ�� ������ �ϱ� ������ �������� <- (?)
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
//�̰� ���迡 ���� ���� ����
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
        // temp->link = NULL;
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
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}


// ��ũ �Լ�
element peek(LinkedStackType *s)
{
    if( is_empty(s) ) {
        fprintf(stderr, "������ �������\n");
        exit(1);
    }
    else{
        return s->top->data;
    }
}

void print_stack(LinkedStackType *s)
{
    if(is_empty(s))
        printf("empty");
        
    for (StackNode *p = s->top; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

// �� �Լ�
void main()
{
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
}