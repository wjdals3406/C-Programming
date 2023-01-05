#include <stdio.h>
#include <stdlib.h>
// 4진법이 뭔지 몰라도 되고 포인트는 각 자리의 숫자는 0부터 3까지 나올 수 있다는 점 
void pick( int n, int* bucket, int bucketSize, int k ) {

    int i, j, lastIndex, smallest, item;
    if(k == 0 ) { 
        for (i = 0; i < bucketSize; i++)
        printf("%d ", bucket[i]); 
        printf("\n");
        return;
    } 
    
    lastIndex = bucketSize - k - 1; 
    if (bucketSize == k ) 
        smallest = 0; 
    else 
        smallest = bucket[lastIndex];
    for(item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(n, bucket, bucketSize, k - 1);
    }
}

void main()
{
    int m;
    int *bucket;
    scanf("%d", &m);
    
    bucket = (int*) malloc(sizeof(int) * m);
    pick(4, bucket, m, m );
    free(bucket);
}
