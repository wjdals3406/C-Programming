#include <stdio.h>
#include <stdlib.h>

int func(int n, int *F){
    int min = n;
    int ret;

    if( F[n] != -1 ) return F[n];

    if (n == 1)
        return 0;

    if (n % 3 == 0) {
        min = func(n / 3, F);
    }
    if ( n % 2 == 0) {
        ret = func(n / 2, F);
        if(ret < min) min = ret;
    }
    ret = func(n - 1, F);
    if (ret < min) min = ret;
    F[n] = min + 1;
    return F[n];
}

// int func(int n, int *F){
//     int min = n;

//     if( F[n] != -1 ) return F[n];

//     if (n == 1)
//         return 0;

//     if (n % 3 == 0) {
//         if (F[n / 3] == -1)
//             F[n / 3] = func(n / 3, F);
//         if (F[n / 3] < min) min = F[n / 3];
//     }
//     if ( n % 2 == 0) {
//         if (F[n / 2] == -1)
//             F[n / 2] = func(n / 2, F);
//         if (F[n / 2] < min) min = F[n / 2];
//     }
//     if (F[n - 1] == -1)
//         F[n - 1] = func( n - 1, F);
//     if (F[n - 1] < min) min = F[n - 1];
//     return min+1;
// }

int main(){
    int n;
    int i;
    int *F;

    scanf("%d", &n);
    F = (int *) malloc(sizeof(int) *(n+1));
    for(i=0; i<n+1; i++){
        F[i] = -1;
    }
    printf("%d", func(n, F));
    
}