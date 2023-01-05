#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[128] = {0, };
    int sum = 0, n=0, i=0;

    scanf("%s", s);
    
    for(i=0; i<strlen(s); i++){
        sum = sum + s[i] - '0';
    }

    if (strlen(s) > 2){
        n = (s[strlen(s) - 2] - '0')*10;
    }
    n = n + s[strlen(s) - 1] - '0';

    printf("%d", n%2==0? 1:0);
    printf("%d", sum%3==0? 1:0);
    printf("%d", n%4==0? 1:0);
    printf("%d", n%5==0? 1:0);

    return 0;

}