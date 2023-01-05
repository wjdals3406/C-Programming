#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char *s){
    int i, j = 0;
    int len = 1;
    char temp[1000] = "";
    char ch;
    int max = -1;

    ch = s[0];
    for( i = 1; i < strlen(s); i++){
        if (ch == s[i])
            len++;
        else{
            if (len > 1) temp[j++] = len + '0'; //숫자를 문자로 만들어 주기 위해
            if (max < len ) max = len;
            temp[j++] = ch;
            len = 1;
            ch = s[i];
        }
    }

    if (len > 1) temp[j++] = len + '0';
    if (max < len ) max = len;
    temp[j++] = ch;
    temp[j] = '\0';
    // printf("%s\n", temp);
    return max;
}
int main(){
    char s[1001];
    scanf("%s", s);
    printf("%d\n", solution(s));   
}