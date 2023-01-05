#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;

int isSequence(int* a, int size)
{
    int i, sum = a[1] - a[0];
    int flag = 1;

    for(i=0; i<size-1; i++){
        if(a[i+1] - a[i] != sum) {
            flag = 0;
            return 0;
        }
    }
    if(flag ==1) return 1;
}
void pick( int items[], int n, int* picked, int m, int toPick ,int* num_array, int* num_array_copy) {
//m = picked_size
    int i, lastIndex, smallest;


    if(toPick == 0 ) { 
        int picked_index;
        for (i = 0; i < m; i++){
            picked_index = picked[i];
            num_array_copy[i] = items[picked_index] + num_array[i]; //num_Array를 변경시키면 안됨
        }
        if (isSequence(num_array_copy, m) == 1) {
            count ++;
        }
        return;
    } 
    lastIndex = m - toPick - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    //중복순열 -> smallest = 0
    for(i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, num_array, num_array_copy);
    }
}
int main(void) 
{ 
    int items[] = { -1, 0, 1 }; 
    int* num_array;
    int* num_array_copy; 
    int n; 
    int* picked; 
    int i; 

    scanf("%d", &n); 
    picked = (int*)malloc(sizeof(int) * n); 
    num_array = (int*)malloc(sizeof(int) * n); 
    num_array_copy = (int*)malloc(sizeof(int) * n); 
    for (i = 0; i < n; i++) 
        scanf("%d", &num_array[i]);


    pick(items, 3, picked, n, n, num_array, num_array_copy);
    printf("%d", count);
    free(picked);
    free(num_array);
    free(num_array_copy);
}
