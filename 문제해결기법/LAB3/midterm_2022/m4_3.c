#include <stdio.h>
#include <stdlib.h>
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
    int i, pivot, tmp;
    for(i=n-1; i>=1; i--){
        if(array[i] > array[i-1]) {
            tmp = array[i-1];
            array[i-1] = array[n-1];
            array[n-1] = tmp;
            pivot = i;
            break;
        }
    }
    if(i==0) pivot = -1;
    return pivot;
}

void testPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void pick( int items[], int n, int* picked, int m, int toPick ) {
//m = picked_size
    int i, lastIndex, smallest;
    if(toPick == 0 ) { 
        int *subitem;
        subitem = (int*)malloc(sizeof(int) * m); 
        for (i = 0; i < m; i++){
            subitem[i] = items[picked[i]];
        }
        selectionSortNew(subitem, 0, m);

        int pivot = findpivot(subitem, m);
        selectionSortNew(subitem, pivot, m);
        testPrint(subitem, m);
        free(subitem);
        return;
    } 
    lastIndex = m - toPick - 1;
    if (m == toPick ) 
        smallest = 0; 
    else 
        smallest = picked[lastIndex] + 1;
    for(i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}

void main()
{
    int n, m;
    int *item;
    int *picked;

    scanf("%d", &n); 
    scanf("%d", &m); 
    for (int i = 0; i < n; i++)
		item[i]= i+1;
    picked = (int*)malloc(sizeof(int) * m); 
    pick( item, n,  picked, m, m );

    free(picked);
}
