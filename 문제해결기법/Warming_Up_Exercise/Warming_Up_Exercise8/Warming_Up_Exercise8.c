#include <stdio.h>
#include <string.h>

char input(char n[], int size) {
	
	scanf_s("%s", n, size);
}

char reverse(char n[]) {
	int len;
	len = strlen(n);

	printf("Reverse: ");
	for (int i = len  - 1; i >= 0; i--)
		printf("%c", n[i]);
}

int main(void)
{
	char name[20];

	printf("Enter your name: ");
	input(name, sizeof(name));
	reverse(name);
}