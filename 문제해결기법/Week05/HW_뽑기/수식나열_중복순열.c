#include <stdio.h>
#include <stdlib.h>

//n의 개수와 +/-의 개수(m)가 같음 
//1부터 n까지, 그 사이에 +와 - 끼워넣기
void pick( char items[], int n, int* bucket, int bucketSize, int k) {

    int i, j, lastIndex, smallest, item, sum = 0;

    if(k == 0 ) { 
        for (i = 0; i < bucketSize; i++){
            // printf("%c%d", items[bucket[i]], i+1); 
            if(items[bucket[i]] == '+') 
                sum += i+1;
            else sum += -(i+1);
        }
        
        // printf(" = %d", sum); 
        // printf("\n");
        sum = 0;
        return;
    } 
    
    lastIndex = bucketSize - k - 1; 

    smallest = 0;

    for(item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(items, n, bucket, bucketSize, k - 1);
    }
}

void main()
{
    int m;
    int *bucket;
    scanf("%d", &m);
    
    bucket = (int*) malloc(sizeof(int) * m);
    char item[3] = {'+', '-', '\0'};
    pick( item, 2, bucket, m, m);
    free(bucket);
}
