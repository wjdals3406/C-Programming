#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int reverse(char src_s[], char s[])
{
    int i, j, src_len;
    src_len = strlen(src_s);

    for(j=0; j < src_len; j++){
        s[j] = src_s[src_len-j-1];
    }
    s[j] = '\0';
    return i;
}

int main(void)
{
    int carry = 0, s1_len, s2_len, idx = 0, sum = 0, check = 0;
    char s_1[101], s_2[101];
    char s_copy1[101], s_copy2[101];
    char sum_char[202];
    int max_len;

    scanf("%s", s_1);
    scanf("%s", s_2);
    s1_len = reverse(s_1, s_copy1);
    s2_len = reverse(s_2, s_copy2);
    max_len = (s1_len > s2_len)?  s1_len: s2_len;

    while(s1_len !=0 && s2_len != 0){
        check = (s_copy1[idx] - '0') + (s_copy2[idx] - '0'); //각 자리의 합
        if(check + sum >=10){
            carry++;
            // sum_char[idx] = '1';
        }
        sum = (check + sum) / 10;

        s1_len--;
        s2_len--;
        idx++;

    }

    if(s1_len > 0 ){
        while(s1_len != 0){
            check = (s_copy1[idx] - '0') + sum;
            if(check >= 10) carry++;
            else break;
            sum = check/ 10;
            s1_len--;
            idx++;
        }
    }
    else if(s2_len > 0 ){
        while(s2_len != 0){
            check = (s_copy2[idx] - '0') + sum;
            if(check >= 10) carry++;
            else break;
            sum = check/ 10;
            s2_len--;
            idx++;
        }
    }
    printf("%d", carry);
    
}