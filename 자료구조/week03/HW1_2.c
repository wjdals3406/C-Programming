#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 80 // 배열을 이용한 스택은 사이즈의 제한이 있다
#define MAX_STRING 80
typedef int element; 
typedef struct {//스택의 구성 요소 : 배열과 top
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1;
}

element stack_print(StackType *s)
{
    int flag = 1;
    for(int i=s->top; i>-1; i--){
        flag = 0;
        if(i==s->top){
            printf("%d <- top\n", s->data[i]);
        }
        else
            printf("%d\n", s->data[i]);
    }
    if (flag){
        printf("<empty>\n");
    }
    printf("--\n");
}

int is_empty(StackType *s)
{
    //s의 top이 -1과 같은지
    return (s->top == -1);
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
int palindrome(char str[])
{
    StackType s;
    int i;
    init(&s);
    for(i=0; str[i]!='\0'; i++){
        push(&s, str[i]);
    }
    for(i=0; str[i]!='\0'; i++){
        if (str[i] != pop(&s))
            return 0;
    }
    return 1; 
}
int main(void)
{
    char word[MAX_STRING];
    printf("Enter a word to check palindrome: ");
    scanf("%s", word);
    if (palindrome(word))
    printf("palindrome 입니다.\n");
    else
    printf("palindrome 이 아닙니다.\n");
}