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
    StackNode *top;//top이 연결리스트르 가져야 하기 때문에 포인터임 <- (?)
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
//이거 시험에 나올 수도 있음
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
// 피크 함수
element peek(LinkedStackType *s)
{
    if( is_empty(s) ) {
        fprintf(stderr, "스택이 비어있음\n");
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

// 주 함수
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