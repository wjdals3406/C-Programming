#include <stdio.h>
#include <string.h>
int reverse(char src_s[], char s[])
{
    int j, src_len;
    src_len = strlen(src_s);

    for(j=0; j < src_len; j++){
        s[j] = src_s[src_len-j-1];
    }
    // s[j] = '\0';
    return src_len;
}

int main(){
    char n1[101] = {0,};
    char n2[101] = {0,};
    char rev_n1[101] = {0,};
    char rev_n2[101] = {0,};
    int i, s1_len, s2_len, max_len;
    int carry=0, carry_count = 0;

    scanf("%s", n1);
    scanf("%s", n2);

    s1_len = reverse(n1, rev_n1);
    s2_len = reverse(n2, rev_n2);

    max_len = (s1_len > s2_len)?  s1_len: s2_len;

    for(i=0; i<max_len; i++){
        int t1 = (rev_n1[i]==0)? 0 : rev_n1[i] - '0'; // rev_n1[i]==0 => null값일 때, 값에 접근이 안될 때 
        int t2 = (rev_n2[i]==0)? 0 : rev_n2[i] - '0';

        int t3 = t1 - t2 - carry;
        // 000001 
        // 7

        if (t3 < 0){
            carry = 1;
            carry_count++;
        }
        else carry = 0;

    }
    printf("%d", carry_count);

    return 0;
}