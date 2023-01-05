#include <stdio.h>

int main(void)
{
    int n, m, start, i, j, row=0, col=0;
    char list[101][101];
    char start_val;
    scanf("%d %d", &n, &m);
    scanf("%d", &start);
    col = start;

    for(i=0; i<m; i++)
        scanf("%s", list[i]);

    // start_val = list[0][start-1];
    while(row != m){
        if(col != 0  && list[row][col-1] == '1'){
            col -= 1;
            row++;
            continue;
        }
        if(col != 0 && col != n && list[row][col] == '1'){
            col += 1;
            row++;
            continue;
        }
        if(col == 0 && list[row][col] == '1'){
            col += 1;
            row++;
            continue;
        }
        if(col == n && list[row][col-1] == '1'){
            col -= 1;
            row++;
            continue;
        }
        
        row++;

    }
    printf("%d", col);
}