#include <stdio.h>
#include <string.h>

int main(void)
{
	int array_1[5], array_2[5], k;

	printf("Enter 첫번째 배열: ");
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &array_1[i]);
	printf("Enter 두번째 배열: ");
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &array_2[i]);

	for (k = 0; k < 5; k++) {
		if (array_1[k] != array_2[k]) {
			printf("두 개의 배열은 다르다");
			break;
		}
	}
	if (k == 5)
		printf("두 개의 배열은 같다");
}