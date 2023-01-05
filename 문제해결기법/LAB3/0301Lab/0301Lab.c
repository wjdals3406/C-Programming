#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int m, int picked[], int toPick) {
	int smallest, lastindex, i;
	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}
	lastindex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastindex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastindex + 1] = i;
		pick(n, m, picked, toPick - 1);
	}
}

int main()
{
    int n, m;
    int *p;
    scanf("%d %d", &n, &m);

    p = (int*) malloc(sizeof(int) * m);
	pick(n, m, p, m);

    free(p);
}