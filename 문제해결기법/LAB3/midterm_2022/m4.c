#include <stdio.h>
#include <stdlib.h>

void testPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void selectionSortNew(int A[], int left, int n)
{
	int i, j, max, max_idx;
    for(i=0; i<n-1-left; i++){
        max_idx = left;
        max = A[left];
        for(j=left+1; j<n-i; j++){
            if(max < A[j]){
                max = A[j];
                max_idx = j;
            }
        }
        A[max_idx] = A[n-i-1];
        A[n-i-1] = max;
    }
}



// void selection_sort(int* array, int n){
//     int i, j, max, max_idx;
//     for(i=0; i<n-1; i++){
//         max_idx = 0;
//         max = array[0];
//         for(j=1; j<n-i; j++){
//             if(max < array[j]){
//                 max = array[j];
//                 max_idx = j;
//             }
//         }
//         array[max_idx] = array[n-i-1];
//         array[n-i-1] = max;
//     }
// }

int main(void)
{
	int n;
	int a[100];
	int start;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &start);

	selectionSortNew(a, start, n);
	testPrint(a, n);
	return 0;
}