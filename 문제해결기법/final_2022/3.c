#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int solution(int n){
    int count = 0;
    
    while(n!=0){
        n /= 10;
        count++;
    }

    return count;
}
int main()
{
    char s[10000] = "";
    char numStr[10000];
    int n;
    int i=0;
    int len;
    int sum = 0;

    scanf("%d", &n);
    for(i=1; i<=n; i++){
        len = solution(i);
        sum += len;
        sprintf(numStr, "%d", i);
        strcat(s, numStr);
        if (sum >= n)
            break;
    }
    printf("%c", s[n-1]);
    
    return 0;
}