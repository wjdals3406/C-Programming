#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* array, int n){
    int i, j, k, tmp;
    for(i=1; i<n; i++){
        for(j=0; j<i; j++)
            if(array[j] > array[i]) break;
        tmp = array[i];

        for(k=i; k>j; k--)
            array[k] = array[k-1];
        
        array[j] = tmp;
    }
}

int main(void)
{
    int n, i;
    int *array;
    srand(time(NULL));
    printf("Enter a number: ");
    scanf("%d", &n);
    
    array = (int*) malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
        array[i] = rand() % 1000;

    for(i=0; i<n; i++)
        printf("%d ", array[i]);

    printf("\n정렬된 후: \n");

    insertion_sort(array, n);

    for(i=0; i<n; i++)
        printf("%d ", array[i]);

    free(array);
}