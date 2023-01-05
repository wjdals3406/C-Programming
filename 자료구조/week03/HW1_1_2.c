#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3 

typedef struct{
   int num;
   char word[80];
}element; 

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

element stack_print(StackType *s)
{
    if (is_empty(s)) printf("<empty>\n");
    
    for(int i = s->top; i > -1; i--){
        if(i == s->top){
            printf("[%d, %s] <- top\n", s->data[i].num, s->data[i].word);
        }
        else
            printf("[%d, %s]\n", s->data[i].num, s->data[i].word);
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
    // element e;
    init(&s);
    //e.num = 10 
    //strcpy(e.word, "ten")
    element one={10,"ten"};
    element two={20,"twenty"};
    element three={30,"thirty"};
    element four={40,"forty"};
    element five={50,"fifty"};
    push(&s, one);
    push(&s, two);
    push(&s, three);
    push(&s, four);
    pop(&s);
    stack_print(&s);
    push(&s, five);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
}