#include <stdio.h>

int isPrime(int x) {

	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	for (int i = 2; i <= 30; i++) {
		if (isPrime(i))
			printf("%d ", i);
	}
}