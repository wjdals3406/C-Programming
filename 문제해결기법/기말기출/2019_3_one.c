#include <stdio.h>
#include <stdlib.h>

int func(int n, int *F){
    int sum1=999999999;
    int sum2=999999999;
    if(n <= 3){
        return 1;
    }
    else{
        if(F[n] == 0){
            if(n%3 == 0 || n%2 == 0){
                if (n%3 == 0 ){
                    if(func(n/3, F) <= func(n-1, F))
                        sum1 = func(n/3, F);
                    else sum1 = func(n-1, F);
                }
                if (n%2 == 0){
                    if(func(n/2, F) <= func(n-1, F))
                        sum2 = func(n/2, F);
                    else sum2 = func(n-1, F);
                }

                if(sum1 <= sum2) F[n] = sum1+1;
                else F[n] = sum2 + 1;
            }
            else{
                F[n] = func(n-1, F) + 1;
            }
            
        }
        return F[n];
    }
}

int main(){
    int n;
    int i;
    int *F;

    scanf("%d", &n);
    F = (int *) malloc(sizeof(int) *(n+1));
    for(i=0; i<n+1; i++){
        F[i] = 0;
    }
    printf("%d", func(n, F));
    
}