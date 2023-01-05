#include <stdio.h>
#include <stdlib.h>

// bucket = picked
// bucketsize = m
// k = toPick
void pick( char items[][10], int n, int* bucket, int bucketSize, int k ) {

    int i, j, lastIndex, smallest, item;
    if(k == 0 ) { 
        for (i = 0; i < bucketSize; i++)
            printf("%10s ", items[bucket[i]]); 
        printf("\n");
        return;
    } 
    
    lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    for(i=0; i<n; i++){
        int flag = 0;
        for(j=0; j<=lastIndex; j++)
            if(bucket[j] == i)
                flag = 1;
        if (flag == 1) continue;

        bucket[lastIndex+1] = i;
        pick(items, n, bucket, bucketSize, k - 1);
    }
}

void main()
{
    int m;
    int *bucket;
    printf("상의 종류는? ");
    scanf("%d", &m);
    printf("%12s %8s", "상 1", "상 2\n");
    
    bucket = (int*) malloc(sizeof(int) * m);
    char item[][10] = {"공유", "김수현", "송중기", "지성", "현빈"};
    pick( item, sizeof(item) / sizeof(item[0]), bucket, m, m );
    free(bucket);
}
