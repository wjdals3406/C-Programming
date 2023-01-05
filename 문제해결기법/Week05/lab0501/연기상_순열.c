#include <stdio.h>
#include <stdlib.h>

// bucket = picked
// bucketsize = m
// k = toPick
void pick( char items[][10], int n, int* bucket, int bucketSize, int k ) {

    int i, j, lastIndex, smallest, item;
    if(k == 0 ) { 
        for (i = 0; i < bucketSize; i++)
            printf("%10s ", items[bucket[i]]); 
        printf("\n");
        return;
    } 
    
    lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
    for(i=0; i<n; i++){
        int flag = 0;
        for(j=0; j<=lastIndex; j++)
            if(bucket[j] == i)
                flag = 1;
        if (flag == 1) continue;

        bucket[lastIndex+1] = i;
        pick(items, n, bucket, bucketSize, k - 1);
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
