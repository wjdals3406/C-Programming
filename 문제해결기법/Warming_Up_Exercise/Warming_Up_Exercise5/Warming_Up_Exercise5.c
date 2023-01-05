#include <stdio.h>

int main(void)
{
	int i, count=0 ;
	char str[30], chr;

	printf("Enter a String: ");
	scanf_s("%s", str, sizeof(str));

	
	printf("Enter a character: ");
	scanf_s(" %c", &chr, sizeof(chr));

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == chr)
			count++;
	}

	printf("'%c' is appeared %d times", chr, count);
}