#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	int n;
	int* a;

	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", isSequence(a, n));
	free(a);
	return 0;
}