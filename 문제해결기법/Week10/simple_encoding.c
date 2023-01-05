#include <stdio.h>
#include <stdlib.h>

int encoding(int *p, int n){
    int max_val = -1;
    int result = 1;
    int tmp;

    for(int i=0; i<n; i++){
        result *= p[i];
    }

    for(int i=0; i<n; i++){
        tmp = result / p[i];
        if(tmp * (p[i] + 1) > max_val) max_val = tmp * (p[i] + 1);
    }
    return max_val;
}

int main(){
    int i, n;
    int *p;
    
    printf("Enter the number: ");
    scanf("%d", &n);
    p = (int*) malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
        scanf("%d", &p[i]);
    
    printf("%d", encoding(p, n));
    free(p);
    return 0;
}