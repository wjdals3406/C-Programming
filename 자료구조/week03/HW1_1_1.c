#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3 // �迭�� �̿��� ������ �������� ������ �ִ�

typedef int element; 
typedef struct {//������ ���� ��� : �迭�� top
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    //s�� top�� -1�� ������
    return (s->top == -1);
}

void stack_print(StackType *s)
{
    if (is_empty(s)) printf("<empty>\n");
    for(int i = s->top; i > -1; i--){
        if(i == s->top){
            printf("%d <- top\n", s->data[i]);
        }
        else
            printf("%d\n", s->data[i]);
    }
    printf("--\n");
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item)
{
    if( is_full(s) ) 
        fprintf(stderr,"���� ��ȭ ����\n");
 
    else
        s->data[++(s->top)] = item;
    stack_print(s);
}

element pop(StackType *s)
{
    if( is_empty(s) ) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}



// ���Լ�
void main()
{
    StackType s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    pop(&s);
    stack_print(&s);
    push(&s, 50);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
}