#include <stdio.h>
#include <stdlib.h>

int fib(int n, int *F, int *check){
    if(n <= 1){
        check[n]++;
        return 1;
    }
    else{
        return fib(n-1, F, check) + fib(n-2, F, check);
    }
    
}

int fib(int n, int *F, int *check){
    if(n == 0){
        check[n]++;
        return 1;
    }
    else{
        if (F[n] == 0){
            F[n] = fib(n-1, F, check) + fib(n-2, F, check);
        }
        return F[n];
    }
}

int main(){
    int n;
    int i;
    int *F;
    int *check;

    scanf("%d", &n);
    check = (int *) malloc(sizeof(int) *(n+1));
    F = (int *) malloc(sizeof(int) *(n+1));
    for(i=0; i<n+1; i++){
        F[i] = 0;
        check[i] = 0;
    }
    fib(n,F,check);

    for(i=1; i>=0; i--){
        printf("%d ", check[i]);
    }

}