#include <stdio.h>
int echo(int n[]) {
	for (int i = 0; i < 5; i++)
		printf("%d ", n[i]);
	printf("\n");
}
int reverse(int n[]) {
	for (int i = 0; i < 5; i++)
		printf("%d ", n[4 - i]);
	printf("\n");
}
int main(void)
{
	int i, num[5];

	for (i = 0; i < 5; i++) 
		scanf_s("%d", &num[i]);
	
	echo(num);
	reverse(num);
}