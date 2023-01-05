#include <stdio.h>
#include <stdlib.h>

// bucket = picked
// bucketsize = m
// k = toPick
int result = 9999;
void pick( char items[][10], int n, int* picked, int m, int toPick ) {

    int i, lastIndex, smallest, j;
    if(toPick == 0 ) { 
        int sum = 0;
        for (i = 0; i < m; i++){
            sum += items[picked[i]];
            // printf("%10s", items[picked[i]]); 
        }
        printf("\n");
        return;
    } 
    lastIndex = m - toPick - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
    
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

void main()
{
    int m;
    int *bucket;
    printf("���� ������? ");
    scanf("%d", &m);
    printf("%12s %8s", "�� 1", "�� 2\n");
    
    bucket = (int*) malloc(sizeof(int) * m);
    char item[][10] = {"����", "�����", "���߱�", "����", "����"};
    pick( item, sizeof(item) / sizeof(item[0]), bucket, m, m );
    free(bucket);
}
