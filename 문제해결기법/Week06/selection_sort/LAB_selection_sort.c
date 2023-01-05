#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void selection_sort(int* array, int n){
    int i, j, max, max_idx;
    for(i=0; i<n-1; i++){
        max_idx = 0;
        max = array[0];
        for(j=1; j<n-i; j++){
            if(max < array[j]){
                max = array[j];
                max_idx = j;
            }
        }
        array[max_idx] = array[n-i-1];
        array[n-i-1] = max;
    }
}

// void selection_sort(int* array, int n){
//     int i, j, least, least_idx;

//     for(i=0; i<n-1; i++){
//         least_idx = i;
//         least = array[i];
//         for(j=i; j<n; j++){
//             if(least > array[j]){
//                 least = array[j];
//                 least_idx = j;
//             }
//         }
//         array[least_idx] = array[i];
//         array[i] = least;
//     }
// }
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

    selection_sort(array, n);

    for(i=0; i<n; i++)
        printf("%d ", array[i]);

    free(array);
}