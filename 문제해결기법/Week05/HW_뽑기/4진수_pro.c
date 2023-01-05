#include <stdio.h>
#include <stdlib.h>

void pick( int items[], int n, int* picked, int m, int toPick ) {
//m = picked_size
    int i, lastIndex, smallest;

    if(toPick == 0 ) { 
        int picked_index;
        for (i = 0; i < m; i++){
            picked_index = picked[i];
            printf("%d ", items[picked_index]); 
        }
        printf("\n");
        return;
    } 
    lastIndex = m - toPick - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
    //�ߺ����� -> smallest = 0
    for(i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}

int main()
{
    int item[] = {0,1,2,3};
    int m;
    int *picked;

    scanf("%d", &m);
    picked = (int*) malloc(sizeof(int) * m);
    pick( item, 4,  picked, m, m );
    free(picked);

    return 0;
}
