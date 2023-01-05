#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *s){
    int i;
    int len = 1, unit;
    char temp[1000] = "";
    char str1[500] = "", str2[500] = "";
    char numStr[1000];
    int sLen = strlen(s);

    strncpy(str1, s, 2);
    str1[2] = '\0';
    i=2;
    while ( i < sLen) { //for(i=2; i<sLen; i = i + 2)와 같은 표현
        // s += 2;
        // strncpy(str2, s, 2); //밑에 줄과 같은 표현
        strncpy(str2, &s[i], 2);
        if (strncmp(str1, str2, 2) == 0)
            len++;
        else {
            if (len > 1){
                sprintf(numStr, "%d", len); //예를 들어 s가 10일때 차례대로 '1', '2'를 넣어줌
                strcat(temp, numStr); //length를 이어붙임
            }
            strcat(temp, str1); //문자를 이어붙임
            strcpy(str1, str2);
            len = 1;
        }
        i += 2;
    }
    if (len > 1){
        sprintf(numStr, "%d", len);
        strcat(temp, numStr);
    }
    strcat(temp, str1);

    printf("%s\n", temp);
}

int main(){
    char s[1001];
    scanf("%s", s);
    solution(s);
}