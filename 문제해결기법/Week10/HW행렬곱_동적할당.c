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
void matrixMul(int **a, int **b, int **x, int r, int l, int c){
    int i, j, k;
    int sum=0;
    
    for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			for (k = 0; k < l; k++)
				sum += a[i][k] * b[k][j];
			x[i][j] = sum;
			sum = 0;
		}

}
void matrixTrans(int **a, int **b, int r, int c){
    int i,j;
    for(i=0; i<c; i++){
        for(j=0; j<r; j++){
            b[i][j] = a[j][i];
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
    int **A, **C, **T, **M;
    int ar, ac, cr, cc, i;

    printf("Enter 행렬 A의 행과 열의 개수: ");
    scanf("%d %d", &ar, &ac);
    printf("Enter 행렬 C의 행과 열의 개수<C의 행은 4이어야: ");
    scanf("%d %d", &cr, &cc);

    A = (int**) malloc(sizeof(int *) * ar);
    C = (int**) malloc(sizeof(int *) * cr);
    M = (int**) malloc(sizeof(int *) * ar);
    T = (int**) malloc(sizeof(int *) * ac);

    for(i=0; i<ar; i++)
        A[i] = (int*) malloc(sizeof(int) * ac);
    for(i=0; i<cr; i++)
        C[i] = (int*) malloc(sizeof(int) * cc);
    for(i=0; i<ar; i++)
        M[i] = (int*) malloc(sizeof(int) * cc);
    for(i=0; i<ac; i++)
        T[i] = (int*) malloc(sizeof(int) * ar);
    
    printf("<3 x 3> 행렬 A 입력: \n");
    readMatrix(A, ar, ac);
    printf("\n");
    printf("<3 x 3> 행렬 C 입력: \n");
    readMatrix(C, cr, cc);

    printf("\n행렬곱:\n");
    matrixMul(A, C, M, ar, ac, cc);
    printMatrix(M, ar, cc); 

    printf("\n전치행렬:\n");
    matrixTrans(A, T, ar, ac);
    printMatrix(T, ac, ar); 

    for(i=0; i<ar; i++){
        free(A[i]);
        free(M[i]);
    }
    for(i=0; i<cr; i++)
        free(C[i]);
    for(i=0; i<ac; i++)
        free(T[i]);

    free(A);
    free(C);
    free(M);
    free(T);
}