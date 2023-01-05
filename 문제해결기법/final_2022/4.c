#include <stdio.h>
#include <stdlib.h>

void pick( int items[], int itemSize, int* bucket, int bucketSize, int toPick, int target, int *count) {

    int i, lastIndex, smallest, item; //중복조합
    int total = 0;
    int cnt = 0;

    lastIndex = bucketSize - toPick - 1; 
    if ( toPick == 0){
        for ( i = 0; i <= lastIndex; i++)
            total += items[bucket[i]];

        if (total == target){
        *count = *count + 1;
        return;
    }
    if (total > target)
        return;
    }
    

    if (bucketSize == toPick ) 
        smallest = 0; 
    else 
        smallest = bucket[lastIndex];

    for(item = smallest; item < itemSize; item++) {
        int sum = 0;
        
        bucket[lastIndex + 1] = item;
        sum += items[item];
        if (sum == target){
        *count = *count + 1;
        return;
    }
    if (sum > target)
        return;
    }
        pick(items, itemSize, bucket, bucketSize, toPick - 1, target, count);
    }
}

void main()
{
    int items[] = {1, 2, 3};
    int* bucket;
    int n;
    int count = 0;

    scanf("%d", &n);
    bucket = (int*) malloc(sizeof(int) * n);

    pick(items, 3, bucket, n, n, n, &count);
    printf("%d", count);
    free(bucket);
}
