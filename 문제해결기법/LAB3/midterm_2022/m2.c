#include <stdio.h>

int result = 0;
int calculateReverse(int n)
{
    int rnum = 0;
    while(n!=0){
        rnum = rnum*10 + n%10; 
        n /= 10;
    }
    return rnum;
}

void print_binary(int x, int k)
{
    if( x > 0 )
    {
    print_binary(x / k, k); 
    result = result * 10 + x % k;
    // printf("%d ", x % k); 
    }
}

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    print_binary(a, b);
    if(result == calculateReverse(result)) printf("%d", 1);
    else printf("%d", 0);
    // printf("%d", a + b);
    return 0;
}

