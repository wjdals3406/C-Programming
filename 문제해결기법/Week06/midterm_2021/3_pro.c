#include <stdio.h>

int main(void)
{
    int n, m, i, col;
    char list[101][101] = {0,};
    char start_val;
    scanf("%d %d", &n, &m);
    scanf("%d", &col);

    for(i=0; i<m; i++)
        scanf("%s", list[i]);

    // start_val = list[0][start-1];
    for(i=0; i<m; i++){
        if(col == 0){
            if(list[i][col] == '1') col++;
        }
        else if(col == n-1){
            if(list[i][col-1] == '1') col--;
        }
        else{
            if( list[i][col] == '1') col++;
            else if ( list[i][col-1] == '1') col--;
        }
        // if(col != 0  && list[i][col-1] == '1'){ //ÀÌ°Å Æ²·ÈÀ½
        //     col --;
        //     }
        // else if(col == n-1 && list[i][col] == '1'){
        //     col ++;
        // }
    }

    printf("%d", col);
    return 0;
}