#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

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
	int picked[4];
	pick(7, 4, picked, 4);
}