#include <stdio.h> 
#include <string.h> 
void reverse_string(char *str, int s, int e) 
{ 
    int temp;
    int str_len = strlen(str);
    // for(int i=0; i< str_len/2; i++){
    //     temp = str[str_len-1-i] ;
    //     str[str_len-1-i] = str[i];
    //     str[i] = temp;
    // }
    for(;s<=e/2;s++){
        temp=str[s];
        str[s] = str[e];
        str[e] = temp;
    }
} 

int main() 
{   char str[100]; 
    printf("Enter any string:"); 
    scanf("%s", str); 
    reverse_string(str, 0, strlen(str) - 1); 
    printf("\nReversed String is: %s", str); 
    return 0; } 