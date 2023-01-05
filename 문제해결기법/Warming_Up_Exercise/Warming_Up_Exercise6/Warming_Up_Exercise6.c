#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	char chr = 'y';
	srand(time(NULL));

	while (chr == 'y') {
		printf("*** 로또 번호 생성기 ***\n");
		printf("생성 번호: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);

		printf("\n다시 생성하겠습니까? (y/n):");
		scanf_s(" %c", &chr, sizeof(chr));
	}
	
}