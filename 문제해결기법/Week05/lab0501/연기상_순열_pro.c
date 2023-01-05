#include <stdio.h>
#include <stdlib.h>

// bucket = picked
// bucketsize = m
// k = toPick
int result = 9999;
void pick( char items[][10], int n, int* picked, int m, int toPick ) {

    int i, lastIndex, smallest, j;
    if(toPick == 0 ) { 
        int sum = 0;
        for (i = 0; i < m; i++){
            sum += items[picked[i]];
            // printf("%10s", items[picked[i]]); 
        }
        printf("\n");
        return;
    } 
    lastIndex = m - toPick - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    
    for(i=0; i<n; i++){
        int flag = 0;
        for(j=0; j<=lastIndex; j++)
            if(picked[j] == i)
                flag = 1;
        if (flag == 1) continue;

        picked[lastIndex+1] = i;
        pick(items, n, picked, m, toPick - 1);
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
