#include <stdio.h>
#include <stdlib.h>
int count = 0;
void pick( int items[], int n, int* bucket, int bucketSize, int k, int m) {

    int i, lastIndex, smallest, item, sum = 0;
    if(k == 0 ) { 
        if ( m  == 0) {
            count ++;
        }
        return;
    } 
    lastIndex = bucketSize - k - 1; 
    if (bucketSize == k ) 
        smallest = 0; 
    else 
        smallest = bucket[lastIndex];
    for(item = smallest; item < n; item++) {
        if( m - items[item] >= 0){
            bucket[lastIndex + 1] = item;
            pick(items, n, bucket, bucketSize, k - 1, m - items[item]);
        }
        else if ( m - items[item] < 0) break;
    }
}

int main(void)
{
    int m;
    int *bucket;
    scanf("%d", &m);
    
    bucket = (int*) malloc(sizeof(int) * m);
    int item[5] = {0, 10, 50, 100, 500};
    pick(item, 5, bucket, m/10, m/10, m);
    printf("%d", count);
    free(bucket);
}
