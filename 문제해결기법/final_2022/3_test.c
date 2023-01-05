#include <stdio.h>
#include <stdlib.h>

void pick( int items[], int n, int* bucket, int bucketSize, int k, int m) {

    int i, lastIndex, smallest, item, sum = 0;
    if(k == 0 ) { 
        for (i = 0; i < bucketSize; i++){
            sum += items[bucket[i]];
            if(sum > m) return; 
        }
        if(sum == m){
            for (i = 0; i < bucketSize; i++){
                if(items[bucket[i]] == 0) continue;
                printf("%d ", items[bucket[i]]); 
            }
                
            printf("\n");
        }
        sum = 0;
        return;
    } 
    lastIndex = bucketSize - k - 1; 
    if (bucketSize == k ) 
        smallest = 0; 
    else 
        smallest = bucket[lastIndex];

    for(item = n - 1; item >= smallest; item--) {
        bucket[lastIndex + 1] = item;
        pick(items, n, bucket, bucketSize, k - 1, m);
    }
}

void main()
{
    int m;
    int *bucket;
    scanf("%d", &m);
    
    bucket = (int*) malloc(sizeof(int) * m);
    int item[4] = {10000, 5000, 1000, 0};
    pick(item, 4, bucket, m/1000, m/1000, m);
    free(bucket);
}
