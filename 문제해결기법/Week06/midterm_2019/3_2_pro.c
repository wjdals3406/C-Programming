#include <stdio.h>
#include <stdlib.h>

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
    int n, i, j, k, flag = 0;
    int count, result=0;
    int *p;

    scanf("%d", &n);
   

    for(i=3; ; i= i+3){
        k = i;
        if(n<=9) {
            printf("%d", n * 3);
            break;
        }
        if(i<=9 ) {
            result++;
            continue;
        }
        count= solution(i);
        p = (int*) malloc(sizeof(int) * count);

        for(j=count - 1; j>=0; j--){
            p[j] = k%10;
            k= k/10;
        }

        for(j=0; j<count; j++){
            result++;
            if(result == n) {
                flag = 1;
                printf("%d", p[j]);
                break;
            }
        }

        if(flag == 1) break;

    }
    
    // printf("%d", solution(n));
    
}