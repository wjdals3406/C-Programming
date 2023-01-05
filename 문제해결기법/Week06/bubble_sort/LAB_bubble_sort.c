#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int* array, int n){
    int i, j, tmp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
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

    bubble_sort(array, n);

    for(i=0; i<n; i++)
        printf("%d ", array[i]);

    free(array);
}