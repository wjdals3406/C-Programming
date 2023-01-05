#include <stdio.h>
#include <stdlib.h>

// int count = 0;
int pick( int *item, int n, int* picked, int m, int toPick, int target) {
//current_money : 현재까지 뽑은 금액의 총액
    int i, lastIndex, ret;

    if(toPick == 0 ) {
        int picked_index;
        int sum = 0;

        for (i = 0; i < m; i++){
            picked_index = picked[i];
            // printf("%d", item[picked_index]* (i+1));
            sum = sum + item[picked_index] * (i+1);
        }

        if(sum == target){
            // count++;
            return 1;
        }
        return 0;
    } 
    
    lastIndex = m - toPick - 1; 
    
    ret = 0;
    for(i=0; i < n; i++) {
        picked[lastIndex + 1] = i;
        // pick(item, n, picked, m, toPick - 1, target);
        ret = ret + pick(item, n, picked, m, toPick - 1, target);
        // if(ret == 1) return ret; --> 이거 하면 중간에 for문 빠져나옴
    }
    return ret;
}

int main()
{
    int n, N, result;
    int item[] = {1, -1}; //char item[] = {'+', '-'}
    int *picked;

    scanf("%d %d", &n, &N);
    
    picked = (int*) malloc(sizeof(int) * n);
    // pick( item, 2, picked, n, n, N);
    result = pick( item, 2, picked, n, n, N);
    printf("%d\n", result);
    free(picked);
    return 0;
}
