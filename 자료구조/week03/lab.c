#include <stdio.h>
#define MAX_STACK_SIZE 100 // 배열을 이용한 스택은 사이즈의 제한이 있다
// 스택을 위한 타입 정의
//int대신 element타입으로 정의함으로써 '내가 정의하는게 배열의 정의이다'라고 말해줄 수 있음
//자료형이 바뀌더라도 지장 없음

typedef int element; 
typedef struct {//스택의 구성 요소 : 배열과 top
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init(StackType *s)
{
    s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    //s의 top이 -1과 같은지
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

// 삽입함수
void push(StackType *s, element item)
{
    if( is_full(s) ) {
    fprintf(stderr,"스택 포화 에러\n");
    return;
 }
    else //top 먼저 증가 후 item 삽입
        s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType *s)
{
    if( is_empty(s) ) {
    fprintf(stderr, "스택 공백 에러\n");
    exit(1);
}
    else
        return s->data[(s->top)--]; // 데이터 꺼내고 top감소
}

// 피크함수
element peek(StackType *s)
{
    if( is_empty(s) ) {
    fprintf(stderr, "스택 공백 에러\n");
    exit(1);
    }
    else
        return s->data[s->top];
}

// 주함수
void main()
{
    StackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
}