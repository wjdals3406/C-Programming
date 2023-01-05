#include <stdio.h>
#include <stdlib.h>

// int fib(int n, int *F){

//     if(n <= 2)
//         return 1;
//     else{
//         if (F[n-1] == 0)
//             F[n-1] = fib(n-1, F);
//         if (F[n-2] == 0)
//             F[n-2] = fib(n-2, F);   
//         return F[n-1] + F[n-2];
//     }
// }

int fib(int n, int *F){
    if(n <= 2){
        return 1;
    }
    else{
        if (F[n] == 0){
            F[n] = fib(n-1, F) + fib(n-2, F);
        }
        return F[n];
    }
}

int main(){
    int n;
    int i;
    int *F;

    printf("�� ��°������ �Ǻ���ġ ����:");
    scanf("%d", &n);
    F = (int *) malloc(sizeof(int) *(n+1));
    for(i=0; i<n+1; i++)
        F[i] = 0;

    // printf("%d ", fib(n, F));
    for(i=1; i<n+1; i++)
        printf("%d ", fib(i, F));
    
}