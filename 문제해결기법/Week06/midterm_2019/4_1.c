#include <stdio.h>
#include <stdlib.h>

//n�� ������ +/-�� ����(m)�� ���� 
//1���� n����, �� ���̿� +�� - �����ֱ�
int flag = 0;
void pick( char items[], int n, int* bucket, int bucketSize, int k, int N) {

    int i, j, lastIndex, smallest, item, sum = 0;

    if(k == 0 ) { 
        for (i = 0; i < bucketSize; i++){
            if(items[bucket[i]] == '+') 
                sum += i+1;
            else sum += -(i+1);
        }
        if(sum == N){
            flag = 1;
            printf("1");
        } 

              
        return;
    } 
    
    lastIndex = bucketSize - k - 1; 

    smallest = 0;

    for(item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        if(flag == 1) break;
        pick(items, n, bucket, bucketSize, k - 1, N);
    }
}

int main(void)
{
    int n, N;
    int *bucket;
    scanf("%d %d", &n, &N);
    
    bucket = (int*) malloc(sizeof(int) * n);
    char item[3] = {'+', '-', '\0'};
    pick( item, 2, bucket, n, n, N);
    if(flag == 0) printf("0");
    free(bucket);
}
