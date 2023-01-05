#include <stdio.h>
#include <stdlib.h>

void pick( int items[], int n, int* picked, int m, int toPick, int target, int current_money ) {
//m = picked_size
    int i, lastIndex, smallest;
    int picked_index;
    
    lastIndex = m - toPick - 1;

    if(current_money == target){
        for(i=0; i<=lastIndex; i++){
            picked_index = picked[i];
            if(items[picked_index] != 0)
                printf("%d ", items[picked_index]);
        }
        printf("\n");
        return;

    }

    if(current_money > target || toPick == 0 ) { 
        return;
    } 

    if (m == toPick ) 
        smallest = 0; 
    else 
        smallest = picked[lastIndex];

    for(i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, target, current_money + items[i]);
    }
}

void main()
{
    int money, n;
    int *picked;
    int item[] = { 1000, 5000, 10000};

    scanf("%d", &money);
    
    n = money/item[0];
    picked = (int*) malloc(sizeof(int) * n);
    pick(item, sizeof(item)/sizeof(item[0]), picked, n, n, money, 0);
    free(picked);
}

