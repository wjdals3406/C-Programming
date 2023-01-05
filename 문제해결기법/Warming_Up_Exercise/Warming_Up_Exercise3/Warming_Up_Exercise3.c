#include <stdio.h>
#include <stdbool.h>
int total(int n) {
	int sum=0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main(void)
{
	int num=0;
	while (true) {
		printf("Input a number(-1 for exit): ");
		scanf_s("%d", &num);
		if (num == -1)
			break;
		printf("%d부터 %d까지의 합은 %d\n", 1, num, total(num));
	}
	
}