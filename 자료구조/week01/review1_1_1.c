#include <stdio.h> 
#include <string.h> 
void reverse_string(char *str, int s, int e) 
{ 
    int temp;
    int str_len = strlen(str);
    if (s >= e) return;
    temp = str[e] ;
    str[e] = str[s];
    str[s] = temp;
    reverse_string(str,s+1,e-1);
    
} 
int main() 
{   char str[100]; 
    printf("Enter any string:"); 
    scanf("%s", str); 
    reverse_string(str, 0, strlen(str) - 1); 
    printf("\nReversed String is: %s", str); 
    return 0; } 