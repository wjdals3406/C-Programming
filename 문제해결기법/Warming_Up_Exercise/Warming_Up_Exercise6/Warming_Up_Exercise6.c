#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	char chr = 'y';
	srand(time(NULL));

	while (chr == 'y') {
		printf("*** �ζ� ��ȣ ������ ***\n");
		printf("���� ��ȣ: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);

		printf("\n�ٽ� �����ϰڽ��ϱ�? (y/n):");
		scanf_s(" %c", &chr, sizeof(chr));
	}
	
}