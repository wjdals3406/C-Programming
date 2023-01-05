#include <stdio.h>
int calculateReverse(int n)
{
    int rnum = 0;
    while(n!=0){
        rnum = rnum*10 + n%10; 
        n /= 10;
    }
    return rnum;
}

int main(void) {
    int n, rnum, count = 0;
	scanf("%d", &n);
    while (n != calculateReverse(n)){
        rnum = calculateReverse(n);
        n = n + rnum;
        count++;
        if (count > 1000){
            printf("NaN");
            break;
        }
    }
    printf("%d %d", count, n);
}