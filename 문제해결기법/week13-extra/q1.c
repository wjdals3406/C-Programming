#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char card[15][5] = {
        "YYYY",
        "YYYN",
        "YYNY",
        "YYNN",
        "YNYY",
        "YNYN",
        "YNNY",
        "YNNN",
        "NYYY",
        "NYYN",
        "NYNY",
        "NYNN",
        "NNYY",
        "NNYN",
        "NNNY"
    };
    char input[5];
    int i;

    scanf("%c %c %c %c", &input[0], &input[1], &input[2], &input[3]);
    input[4] = 0x00;

    for(i=0; i<15; i++)
        if(strcmp(input, card[i]) == 0)
            break;

    printf("%d", i + 1);
}