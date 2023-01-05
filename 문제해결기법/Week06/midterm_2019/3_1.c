#include <stdio.h>
int solution(int n){
    int count = 0;
    
    while(n!=0){
        n /= 10;
        count++;
    }

    return count;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", solution(n));
    
}