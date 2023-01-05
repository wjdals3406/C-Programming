#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r){
    int i, j;
    int t;
   
    i = p-1;

    for( j=p; j<r; j++){ 
        if(A[j] < A[r]){
            i++;
            //swap A[i] & A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
 }

void quick_sort(int *A, int p, int r){
    int q;
    if(p<r){ //�ε��� ���̰� 1�̻��� ��츸 
        q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

int main()
{
    int n, i;
    int *array;
    srand(time(NULL));
    printf("Enter a number: ");
    scanf("%d", &n);
    
    array = (int*) malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
        array[i] = rand() % 10001;

    for(i=0; i<n; i++)
        printf("%d ", array[i]);

    printf("\n���ĵ� ��: \n");

    quick_sort(array, 0, n-1);

    for(i=0; i<n; i++)
        printf("%d ", array[i]);

    free(array);
    return 0;
}