#include <stdio.h>

int main(void)
{
	int i, k, num, key;
	int n_array[5];

	printf("Enter 5�� ����: ");
	for (i = 0; i < 5; i++) {
		scanf_s("%d", &num);
		n_array[i] = num;
	}
	printf("Enter a key: ");
	scanf_s("%d", &key);
	for (k = 0; k < 5; k++) {
		if (n_array[k] == key) {
			printf("%d��°�� �ִ�", k+1);
			break;
		}
	}
	if (k == 5)
		printf("����");
}