#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r, int **F)
{
    if (r==0 || r==n)
        return 1;
    else{
        if(F[n][r] == 0){ 
            F[n][r] = comb(n-1, r-1, F) + comb(n-r, r, F);
        }
    }
    return F[n][r];
}

int main()
{
    int n, r, i, j;
    int C;
    int **F;

    scanf("%d %d", &n, &r);
    F= (int **) malloc(sizeof(int*)*n+1);
    for(i=0; i<n+1; i++){
        F[i] = (int *) malloc(sizeof(int)*r+1);
    }

    for(i=0; i<n+1; i++)
        for(j=0; j<r+1; j++){
            F[i][j] = 0;
        }
    
    C = comb(n,r, F);
    printf("%d\n", C);
    return 0;
}