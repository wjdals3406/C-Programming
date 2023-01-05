#include <stdio.h>
#include <stdlib.h>
void readMatrix(int **a, int r, int c){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}
void matrixAdd(int **a, int **b, int **x, int r, int c){
    int i,j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            x[i][j] = a[i][j] + b[i][j];
        }
    }

}
void printMatrix(int **a, int r, int c){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int **A, **B, **X;
    int r, c, i;

    printf("Enter 행렬 A의 행과 열의 개수: ");
    scanf("%d %d", &r, &c);

    A = (int**) malloc(sizeof(int *) * r);
    B = (int**) malloc(sizeof(int *) * r);
    X = (int**) malloc(sizeof(int *) * r);

    for(i=0; i<r; i++){
        A[i] = (int*) malloc(sizeof(int) * c);
        B[i] = (int*) malloc(sizeof(int) * c);
        X[i] = (int*) malloc(sizeof(int) * c);
    }
    readMatrix(A, r, c);
    readMatrix(B, r, c);

    matrixAdd(A, B, X, r, c);
    printf("행렬합:\n");
    printMatrix(X, r, c); 

    for(i=0; i<r; i++){
        free(A[i]);
        free(B[i]);
        free(X[i]);
    }
    free(A);
    free(B);
    free(X);
}