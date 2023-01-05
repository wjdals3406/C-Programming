#include <stdio.h>
int k_bonacci(int k, int n) //중복호출때메 sum이 굉장히 커지는 문제 발생
{
    int i, sum = 0;
    if(n>=1 && n <= k){
        return 1;
    }
    
    for(i = 1; i <= k; i++){
        sum += k_bonacci(k, n-i);
    }
    return sum;
    
}

void main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d", k_bonacci(k, n));

}