#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i, sum=0;
    char num[100];
    scanf("%s", num);

    if((num[strlen(num)-1] - '0') % 2 == 0) printf("1");
    else printf("0");

    for(i=0; num[i] != '\0'; i++){
        sum += num[i] - '0';
    }
    if(sum % 3 == 0) printf("1");
    else printf("0");

    sum = 0;
    for(i=0; num[i] != '\0'; i++){
        sum = sum * 10 + num[i] - '0';
    }
    if(sum % 100 %4 == 0) printf("1");
    else printf("0");

    if((num[strlen(num)-1] - '0') % 5 == 0) printf("1");
    else printf("0");

}


