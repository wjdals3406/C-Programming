#include <stdio.h>
#include <stdlib.h>
int func(int n, long long *H){
    int i;
    long long sum = 0;

    if(H[n] != 0) return H[n];

    if(n==1) H[n] = 1;
    else{
        for(int i=1; i<n; i++) {
            sum += i * func(n-i, H);
        }
        H[n] = sum;
        
        return H[n];
    }
}

int main(){
    int n;
    int i;
    int *H;

    scanf("%d", &n);
    H = (int *) malloc(sizeof(int) *(n+1));
    for(i=0; i<n+1; i++)
        H[i] = 0;

    printf("%d ", func(n, H));
}