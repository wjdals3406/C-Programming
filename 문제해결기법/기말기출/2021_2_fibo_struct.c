#include <stdio.h>
#include <stdlib.h>
struct Fibo
{
    int zero;
    int one;
};

struct Fibo fib(int n, struct Fibo *fibo){
    
    if(n == 0){
        fibo[n].zero = 1;
    }
    if(n == 1){
        fibo[n].one = 1;
    }
    else{
        if (fibo[n].zero == 0 && fibo[n].one == 0){
            struct Fibo f1 = fib(n-1, fibo);
            struct Fibo f2 = fib(n-2, fibo);
            fibo[n].one = f1.one + f2.one;
            fibo[n].zero = f1.zero + f2.zero;
        }
    }
    return fibo[n];
}

// void fib(int n, struct Fibo *fibo, int *M2){
//     if(M2[n] != 0 ) return;
//     if(n == 0){
//         fibo[n].zero = 1;
//         fibo[n].one = 0;
//     }
//     if(n == 1){
//         fibo[n].zero = 0;
//         fibo[n].one = 1;
//     }
//     else{
//         fib(n-1, fibo);
//         fib(n-2, fibo);
//         fibo[n].one = fibo[n-1].one + fibo[n-2].one;
//         fibo[n].zero = fibo[n-1].zero + fibo[n-2].zero;
        
//     }
//     M2[n] = 1;
// }

int main(){
    int n;
    int i;
    int j;
    struct Fibo *fibo;
    int *M2;

    scanf("%d", &n);
    fibo = (struct Fibo*) malloc(sizeof(struct Fibo) * n+1);
    // M2 = (int*) malloc(sizeof(int) * n+1);
        
    for(i=0; i<n+1; i++){
        fibo[i].zero = 0;
        fibo[i].one = 0;
    }
    fib(n, fibo);

    printf("%d %d", fibo[n].one, fibo[n].zero);
}