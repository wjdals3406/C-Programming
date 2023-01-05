#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 80 // �迭�� �̿��� ������ �������� ������ �ִ�
#define MAX_STRING 80
typedef int element; 
typedef struct {//������ ���� ��� : �迭�� top
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
    //s�� top�� -1�� ������
    return (s->top == -1);
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
    printf("palindrome �Դϴ�.\n");
    else
    printf("palindrome �� �ƴմϴ�.\n");
}