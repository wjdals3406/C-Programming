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
    while ( i < sLen) { //for(i=2; i<sLen; i = i + 2)�� ���� ǥ��
        // s += 2;
        // strncpy(str2, s, 2); //�ؿ� �ٰ� ���� ǥ��
        strncpy(str2, &s[i], 2);
        if (strncmp(str1, str2, 2) == 0)
            len++;
        else {
            if (len > 1){
                sprintf(numStr, "%d", len); //���� ��� s�� 10�϶� ���ʴ�� '1', '2'�� �־���
                strcat(temp, numStr); //length�� �̾����
            }
            strcat(temp, str1); //���ڸ� �̾����
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