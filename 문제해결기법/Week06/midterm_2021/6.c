#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
void pick( int *items, int n, int* picked, int m, int toPick ) {
//m = picked_size
    int i, lastIndex, smallest, j, flag= 1;
    int sum = 0;

    if(toPick == 0 ) {
        for (i = 0; i < m; i++){
            sum = sum * 10 + items[picked[i]];
        }

        for(i=0; i<n; i++){ //n=4
            // flag = 1;
            if(picked[i] !=  i){
                if(sum % items[i]==0) count++;
                return;
                }
            if(sum % items[i]==0) count++;
            return;
            // if(flag == 1){
            //     if(sum % items[i]==0) count++;
            //     break;
            // }
        }
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

int main(void) 
{ 
    int* items; 
    int n;
    int* bucket; 
    int i; 

    scanf("%d", &n); //n개 중에서 n-1개 뽑음
    items = (int*)malloc(sizeof(int) * n); 

    bucket = (int*)malloc(sizeof(int) * n-1); 
    for (i = 0; i < n; i++) 
        scanf("%d", &items[i]);

    pick(items, n, bucket, n-1, n-1);
    printf("%d", count);
    free(items);
    free(bucket);
}
