#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i, n;
    char num[100];
    scanf("%s", num);
    
    if((num[strlen(num)-1] - '0') % 2 == 0) printf("1");
    else printf("0");
}