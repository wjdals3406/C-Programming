#include <stdio.h>
void get_num(int n){
    if(n==0) return;
    
    get_num(n/10);
    printf("%d ", n%10);
    
}

int main(void)
{
    int n;
    scanf("%d", &n);
    get_num(n*9);
}