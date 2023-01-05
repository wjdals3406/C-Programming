#include <stdio.h>

int main(void)
{
	int num, i, mul=1;
	printf("Enter a number: ");
	scanf_s("%d", &num);

	for (i = 0; i < 5; i++) 
		mul = 2 * mul;
	
	printf("%d", mul);

}