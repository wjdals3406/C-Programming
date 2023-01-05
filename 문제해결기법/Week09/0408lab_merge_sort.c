#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *A, int p, int q, int r, int *B){
    int i, j, t;
    i = p;
    j = q+1;

    // B = (int*) malloc(sizeof(int) * (r-p+1));
    t = 0;
//���� �κ� �� ���� i�� q+1�� �ǰ�, ������ �κ� �� ���� j�� r+1�� �ȴ�
    while( i<= q && j<=r){
        if( A[i] < A[j]){
            B[t] = A[i];
            i++;
        }
        else {
            B[t] = A[j];
            j++;
        }
        t++;
    }

    if( i>q ){ //���� �κ��� �� ���� ��
        for( ; j<=r; j++, t++) {
            B[t] = A[j];
        }
        // for( ; j<=r; j++) {
        //     B[t] = A[j];
        //     t++;
        // }
    }
    else {
        for( ; i<=q; i++, t++) {
            B[t] = A[i];
        }
    }

    //B�� �ִ� ���� A�� ����
    for(i=p,t=0; i<=r; i++,t++)
        A[i] = B[t];

    // t=0;
    // for(i=p; i<=r; i++){
    //     A[i] = B[t];
    //     t++;
    // }

    // free(B);
}

void merge_sort(int *A, int p, int r, int *B){
    int q;
    if(p<r){
        q = (p+r)/2;
        merge_sort(A, p, q, B);
        merge_sort(A, q+1, r, B);
        merge(A, p, q, r, B);
    }
}

int main()
{
    int n, i;
    int *A, *B;
    srand(time(NULL));
    printf("Enter a number: ");
    scanf("%d", &n);
    
    A = (int*) malloc(sizeof(int) * n);
    B = (int*) malloc(sizeof(int) * n);

    for(i=0; i<n; i++)
        A[i] = rand() % 10001;

    for(i=0; i<n; i++)
        printf("%d ", A[i]);

    printf("\n���ĵ� ��: \n");

    merge_sort(A, 0, n-1, B);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);

    free(A);
    free(B);
    return 0;
}