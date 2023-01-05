#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다

typedef int element; 
typedef struct {//스택의 구성 요소 : 배열과 top
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    //s의 top이 -1과 같은지
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
        fprintf(stderr,"스택 포화 에러\n");
 
    else
        s->data[++(s->top)] = item;
    stack_print(s);
}

element pop(StackType *s)
{
    if( is_empty(s) ) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}



// 주함수
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