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
int findpivot(int array[], int n){
    int i, pivot, tmp, minidx, j;
    for(i=n-1; i>=1; i--){
        if(array[i] > array[i-1]) {
            int minval = 999;
            for(j=n-1; j>=i; j--){
                if(array[i-1] < array[j] && minval > array[j]){
                    minval = array[j];
                    minidx = j;
                }
            }
            tmp = array[i-1];
            array[i-1] = array[minidx];
            array[minidx] = tmp;
            pivot = i;
            break;
        }
    }
    if(i==0) pivot = -1;
    return pivot;
}


int main(void)
{
	int n;
	int a[100];
    int pivot;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

    pivot=findpivot(a, n);
	selectionSortNew(a, pivot, n);
    
    if(pivot != -1) testPrint(a, n);
    else printf("-1");
	return 0;
}