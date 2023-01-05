#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* array, int n){
    for(int i=0; i<n; i++)
        printf("%5d ", array[i]);
    
    printf("\n");
}

void bubble_sort(int* array, int n){
    int i, j, tmp, flag = 0;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                flag = 1;
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
        if (flag == 0) break;
        printf("i = %d:", i);
        print_array(array, n);

        flag = 0;
    }
}
int main(void)
{
    int n, i;
    int *array;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    array = (int*) malloc(sizeof(int) * n);
    for(i=0; i<n; i++)
        array[i] = rand() % 100;

    printf("초기 :");
    print_array(array, n);
    bubble_sort(array, n);
    printf("정렬 :");
    print_array(array, n);

    free(array);
}