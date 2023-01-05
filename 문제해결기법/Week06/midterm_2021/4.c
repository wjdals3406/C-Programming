#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
void pick( int items[], int n, int* picked, int m, int toPick ,int* invest) {
//m = picked_size
    int i, lastIndex, smallest;

    if(toPick == 0 ) { 
        int picked_index;
        int sum = 0;
        for (i = 0; i < m; i++){
            picked_index = picked[i];
            sum = sum + items[picked_index] * invest[i];
        }
        if (sum == 0) count ++;
            // printf("=%d\n", sum);
        return;
    } 
    lastIndex = m - toPick - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
    //�ߺ����� -> smallest = 0
    for(i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, invest);
    }
}
int main(void) 
{ 
    int items[] = { -1, 0, 1 }; 
    int* invest; 
    int investNum; 
    int* bucket; 
    int i; 

    scanf("%d", &investNum); 
    bucket = (int*)malloc(sizeof(int) * investNum); 
    invest = (int*)malloc(sizeof(int) * investNum); 
    for (i = 0; i < investNum; i++) 
        scanf("%d", &invest[i]);
     

    pick(items, 3, bucket, investNum, investNum, invest);
    printf("%d", count);
    free(invest);
}
