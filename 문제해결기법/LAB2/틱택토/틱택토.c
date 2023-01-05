#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void display(char b[][3])
{
	char ch;
	int i, j;
	printf("     ");
	for (i = 0; i < 3; i++)
		printf("%2d", i);
	printf("\n     --------\n");

	for (i = 0; i < 3; i++) {
		printf("%3d |", i);
		for (j = 0; j < 3; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

int winCheck(char b[][3], int r, int c) {
	char t = b[r][c];
	int i, hor = 1, ver = 1, dig = 1, o_dig = 1;
	int row = r;

	//수평
	for (i = c - 1; i >= 0; i--)
		if (b[r][i] != t)
			break;
		else
			hor++;

	for (i = c + 1; i < 3; i++)
		if (b[r][i] != t)
			break;
		else
			hor++;
	//역대각선
	for (i = c - 1; i >= 0; i--)
		if (b[row - 1][i] != t)
			break;
		else {
			o_dig++;
			row--;
		}
	row = r;

	for (i = c + 1; i < 3; i++)
		if (b[row + 1][i] != t)
			break;
		else {
			o_dig++;
			row++;
		}
	row = r;
	//대각선
	for (i = c - 1; i >= 0; i--)
		if (b[row + 1][i] != t)
			break;
		else {
			dig++;
			row++;
		}
	row = r;

	for (i = c + 1; i < 3; i++)
		if (b[row - 1][i] != t)
			break;
		else {
			dig++;
			row--;
		}
	row = r;

	//수직
	for (i = row - 1; i >= 0; i--)
		if (b[i][c] != t)
			break;
		else
			ver++;

	for (i = row + 1; i < 3; i++)
		if (b[i][c] != t)
			break;
		else
			ver++;

	if (hor == 3 || dig == 3 || o_dig == 3 || ver == 3)
		return 1;
	else
		return 0;

}
void main()
{
	char board[3][3];
	char turn = 'X';
	int r, c;
	int i, j;
	int count;
	int win;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';
	count = 1;
	display(board);

	do
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);

		if (board[r][c] != ' ')
			continue;
		board[r][c] = turn;
		display(board);

		if (win = winCheck(board, r, c)) 
			printf("Player %c wins!\n", turn);

		
		if (turn == 'X')
			turn = 'O';
		else if (turn == 'O')
			turn = 'X';

		count++;

	} while (!win && count <= 3 * 3);

	if (!win && count > 3 * 3) 
		printf("Nobody wins!");
}

