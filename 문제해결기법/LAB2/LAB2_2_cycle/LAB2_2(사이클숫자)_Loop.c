#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int get_cycle_number(int n) {
	int count = 1;
	while (n != 1) {
		printf("%d ", n);
		count++;
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;
		if (n == 1)
			printf("%d", 1);
	}
	return count;
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("\n%d", get_cycle_number(n));
}