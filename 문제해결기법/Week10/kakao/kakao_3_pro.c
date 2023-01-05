#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char *s){
    int i, j;
    int len, unit, min = 1000;
    char temp[1000] = "";
    char str1[500] = "", str2[500] = "";
    char numStr[1000];
    int sLen = strlen(s);

    for(unit = 1; unit <= sLen / 2; unit++){
        // char *temp_s = s;
        len = 1;
        // strncpy(str1, temp_s, unit);
        strncpy(str1, s, unit);
        str1[unit] = '\0';

        for (i=unit; i<sLen; i=i+unit) { //for(i=2; i<sLen; i = i + 2)와 같은 표현
            strncpy(str2, &s[i], unit);
            str2[unit] = '\0';
            
            if (strncmp(str1, str2, unit) == 0)
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
        }
        if (len > 1){
        sprintf(numStr, "%d", len);
        strcat(temp, numStr);
        }
        strcat(temp, str1);

        if (min > strlen(temp))
            min = strlen(temp);
        memset(temp, 0x00, 1000);
    }
    return min;
}

int main(){
    char s[1001];
    scanf("%s", s);
    printf("%d",solution(s));
}