#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10000] = "";
    
    int n;

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        char numStr[10000] = "";
        sprintf(numStr, "%d", i);
        strcat(s, numStr);
    }
    printf("%d", strlen(s));
    
    return 0;
}