#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

void flood_fill(int x, int y){

    int num;
    if (screen[x][y] == 0){
        screen[x][y] = 9;
        flood_fill(x, y+1); 
        flood_fill(x+1, y); 
        flood_fill(x, y-1); 
        flood_fill(x-1, y); 
    }
}

void draw()
{
    int i, j;
    for(i = 0; i<WIDTH; i++){
            for(j = 0 ; j<HEIGHT; j++){
                printf("%2d ", screen[i][j]);
            }
            printf("\n");
        }
    printf("\n");
}

void main()
{
    printf("미로: \n");
    draw();
    flood_fill(4, 3);
    printf("시작점을 <0 0>으로 한 미로방문<순서표기>: \n");
    draw();
}