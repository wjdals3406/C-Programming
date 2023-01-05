#include <stdio.h>

void print_binary(int x, int k)
{
    if( x > 0 )
    {
    print_binary(x / k, k); 
    printf("%d ", x % k); 
    }
}


int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    print_binary(a, b);
    // printf("%d", a + b);
    return 0;
}

