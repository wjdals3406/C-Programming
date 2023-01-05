#include <stdio.h>
#include <stdlib.h>

#define ST 1
#define LE 2
#define UP 3

#define INIT 0
#define COMPUTED 1
int matrixPath(int **m, int **M, int **check, int **BP, int i, int j )
{
    if (check[i][j] != 0) return M[i][j];
    if (i == 0 && j == 0){
        BP[i][j] = ST;
        M[i][j] =  m[i][j];

    }
    else if (i == 0){
        BP[i][j] = LE;
        M[i][j] = matrixPath(m, M, check, BP, i, j-1) + m[i][j];
    }
    else if (j == 0){
        BP[i][j] = UP;
        M[i][j] = matrixPath(m, M, check, BP, i-1, j) + m[i][j];
    }
    else
    {
        int a, b;
        a = matrixPath(m, M, check, BP, i, j-1);
        b = matrixPath(m, M, check, BP, i-1, j);
        if(a<b)
            BP[i][j] = LE;
        else
            BP[i][j] = UP;

        M[i][j] = ((a<b)?a:b) + m[i][j];
    }
    check[i][j] = 1;
    return M[i][j];
}

int main(){
    int **m;
    int **M;
    int **check;
     int **BP;
    int r,c;
    int i,j;

    r=c=4;

    m= (int **) malloc(sizeof(int*)*r);
    M= (int **) malloc(sizeof(int*)*r);
    check= (int **) malloc(sizeof(int*)*r);
    BP= (int **) malloc(sizeof(int*)*r);

    for(i=0; i<r; i++){
        m[i] = (int *) malloc(sizeof(int)*c);
        M[i] = (int *) malloc(sizeof(int)*c);
        check[i]= (int *) malloc(sizeof(int*)*c);
        BP[i]= (int *) malloc(sizeof(int*)*c);
    }

    for(i=0; i<r; i++)
        for(j=0; j<c; j++){
            scanf("%d", &m[i][j]);
            M[i][j] = 0;
            check[i][j] = 0;
        }
    printf("%d\n", matrixPath(m, M, check, BP, r-1, c-1));

    for(i=0; i<r; i++){
        for(j=0; j<c; j++) {
            printf("%d ", BP[i][j]);
        }
        printf("\n");
    }
    
}