#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct{
   int num;
   char word[80];
}element; 

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
    if (is_empty(s)) printf("(empty)\n");
    for (StackNode *p = s->top; p != NULL; p = p->link){
        if(p == s->top){
            printf("[%d, %s] <- top\n", p->data.num, p->data.word);
        }
        else
            printf("[%d, %s]\n", p->data.num, p->data.word);
    }
    printf("--\n");
}

// �� �Լ�
void main()
{
    LinkedStackType s;
    init(&s);
    element one={10,"ten"};
    element two={20,"twenty"};
    element three={30,"thirty"};
    element four={40,"forty"};
    element five={50,"fifty"};
    print_stack(&s);
    push(&s, one); print_stack(&s);
    push(&s, two); print_stack(&s);
    push(&s, three); print_stack(&s);
    push(&s, four); print_stack(&s);
    pop(&s); print_stack(&s);
    push(&s, five); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
}