#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[])
{
    int i, j;
    for(i=0; src_s[i]!='\0'; i++);

    for(j=0; j < i; j++){
        s[j] = src_s[i-j-1];
    }
    s[j] = '\0';
}

int main(void)
{
    char src_s[101];
    char s[101];
    scanf("%s", src_s);
    // reverse(src_s, s);
    // printf("%s\n", s);
    printf("%d\n", strlen(src_s));
}