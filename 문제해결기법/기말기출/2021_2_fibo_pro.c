#include <stdio.h>
#include <stdlib.h>

int fib1(int n, int *M){
    if ( n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        if (M[n-1] == 0)
            M[n-1] = f1(n - 1, M);
        if (M[n-2] == 0)
            M[n-2] = f1(n - 2, M);
        return M[n - 1] + M[n - 2];
    }
}

int fib0(int n, int *M){
    if ( n == 0)
        return 1;
    else if (n == 1)
        return 0;
    else {
        if (M[n-1] == 0)
            M[n-1] = f0(n - 1, M);
        if (M[n-2] == 0)
            M[n-2] = f0(n - 2, M);
        return M[n - 1] + M[n - 2];
    }
}


int main(){
    int n;
    int i;
    int *F;
    int *M1, *M2;

    scanf("%d", &n);
    M1 = (int *) malloc(sizeof(int) *(n+1));
    M2 = (int *) malloc(sizeof(int) *(n+1));
    for(i=0; i<n; i++){
        M1[i] = 0;
        M2[i] = 0;
    }
    printf("%d %d\n", f1(n, M1), f0(n, M2));
    free(M1);
    free(M2);
    return 0;
}