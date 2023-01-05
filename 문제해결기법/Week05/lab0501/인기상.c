#include <stdio.h>
#include <stdlib.h>

void pick( char *items[], int n, int* picked, int m, int toPick ) {

    int i, lastIndex, smallest;
    if(toPick == 0 ) { 
        int picked_index;
        for (i = 0; i < m; i++){
            picked_index = picked[i];
            printf("%10s ", items[picked_index]); 
        }
        printf("\n");
        return;
    } 
    lastIndex = m - toPick - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
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
    int m;
    int *picked;
    printf("�α�� ���? ");
    scanf("%d", &m);
    
    picked = (int*) malloc(sizeof(int) * m);
    char *item[] = {"����", "�����", "���߱�", "����", "����"};
    pick( item, sizeof(item) / sizeof(item[0]), picked, m, m );
    free(picked);
}
