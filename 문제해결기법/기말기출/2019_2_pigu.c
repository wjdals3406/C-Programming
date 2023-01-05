#include <stdio.h>
#include <stdlib.h>

int result = 9999;
void pick( int items[], int n, int* picked, int picksize, int toPick ) {
//m = picked_size
    int i, lastIndex, smallest;
    if(toPick == 0 ) { 
        int sum1 = 0;
        int sum2 = 0;
        int idx = 0;
        for (i = 0; i < picksize * 2; i++){
            if(i != picked[idx]){
                sum1 += items[i];
            }
            else {
                sum2 += items[picked[idx]];
                idx++;
            }
        }
        int sum = (sum1 > sum2) ? sum1 - sum2 : sum2 - sum1;
        if (sum < result) result = sum;
        return;
    } 
    lastIndex = picksize - toPick -1; 
    
    if (picksize == toPick ) 
        smallest = 2; 
    else 
        smallest = picked[lastIndex] + 1;
    for(i = smallest; i < 2*n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, picksize, toPick - 1);
    }
}

int main()
{
    int n;
    int *cap;
    int *picked;

    scanf("%d", &n); 
    cap = (int *) malloc(sizeof(int) *(n)); 
    picked = (int *) malloc(sizeof(int) *(n/2)); 
    picked[0] = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &cap[i]);
    }
    pick( cap, n/2,  picked, n/2, n/2-1 );
    printf("%d", result);

    free(cap);
    free(picked);
}
