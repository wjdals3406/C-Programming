#include <stdio.h>
#include <stdlib.h>

void pick( int items[], int itemSize, int* bucket, int bucketSize, int toPick, int target, int *count) {

    int i, lastIndex, smallest, item; //중복조합
    int total = 0;
    int cnt = 0;

    lastIndex = bucketSize - toPick - 1; 
    for ( i = 0; i <= lastIndex; i++)
        total += items[bucket[i]];

    if (total == target){
        *count = *count + 1;
        return;
    }
    if (total > target)
        return;

    if ( toPick == 0)
        return;

    if (bucketSize == toPick ) 
        smallest = 0; 
    else 
        smallest = bucket[lastIndex];

    for(item = smallest; item < itemSize; item++) {
        bucket[lastIndex + 1] = item;
        pick(items, itemSize, bucket, bucketSize, toPick - 1, target, count);
    }
}

void main()
{
    int items[] = {1, 2};
    int* bucket;
    int n;
    int count = 0;

    scanf("%d", &n);
    bucket = (int*) malloc(sizeof(int) * n);

    pick(items, 2, bucket, n, n, n, &count);
    printf("%d", count);
    free(bucket);
}
