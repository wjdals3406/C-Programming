#include <stdio.h>
#include <string.h>

int main(void)
{
	int array_1[5], array_2[5], k;

	printf("Enter ù��° �迭: ");
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &array_1[i]);
	printf("Enter �ι�° �迭: ");
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &array_2[i]);

	for (k = 0; k < 5; k++) {
		if (array_1[k] != array_2[k]) {
			printf("�� ���� �迭�� �ٸ���");
			break;
		}
	}
	if (k == 5)
		printf("�� ���� �迭�� ����");
}