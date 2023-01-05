#include <stdio.h>
void pick( char items[], int n, int* picked, int m, int toPick ) {
//m = picked_size
    int i, lastIndex, smallest;
    if(toPick == 0 ) { 
        for (i = 0; i < m; i++)
            printf("%c ", items[picked[i]]); 
        printf("\n");
        return;
    } 
    lastIndex = m - toPick - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    if (m == toPick ) 
        smallest = 0; 
    else 
        smallest = picked[lastIndex] + 1;
    for(i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}

void main()
{
    char item[] = "ABCDEFG";
    int picked[3];
    pick( item, 7,  picked, 3, 3 );
}
