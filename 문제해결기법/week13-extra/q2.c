#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 80

void add_substring(char *palindrome, char *s, int len, int i)
{
    int j;
    for (j=0; j<i; j++)
        palindrome[len + j] = s[i - j - 1];
    palindrome[len + j] = 0x00;
}
int is_palindrome(char *s, int len){
    int i;
    for(int i=0; i<len/2; i++){
        if(s[i] != s[len -1 -i])
            return 0;
    }
    return 1;
}
void make_palindrome(char *s)
{
    char palindrome[MAX_LEN * 2];
    int len = strlen(s);
    int i = 0;

    strcpy(palindrome, s); //s를 palindrome에 복사
    do
    {
        add_substring(palindrome, s, len, i);
    } while (!is_palindrome(palindrome, len + i++));

    printf("%s", palindrome);
}

int main(){
    char s[MAX_LEN];
    
    scanf("%s", s);
    make_palindrome(s);
    
}