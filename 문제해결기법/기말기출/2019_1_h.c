#include <stdio.h>
#include <stdlib.h>
int func(int n, int *H){
    if(n == 1){
        return 1;
    }
    else{
        if (H[n] == 0){
            long long sum = 0;
            for(int i=1; i<n; i++) {
                sum += i * func(n-i, H);
            }
            H[n] = sum;
        }
        return H[n];
    }
}

int func(int n, int *H){
    if (H[n] == 0){
        if (n == 1) H[n] = 1;
        else{
            int sum = 0;
            for(int i=n-1; i>=1; i--) {
                sum += i * func(n-i, H);
            }
            H[n] = sum;
        }
            
    }
    return H[n];

}



int func(int n, int *H){
    if (H[n] == 0){
        if (n == 1 || n == 2) H[n] = 1;
        else{
            int sum = 0;
            for(int i=n-1; i>=1; i--) {
                sum += i * func(n-i, H);
            }
            H[n] = sum;
        }
            
    }
    return H[n];

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