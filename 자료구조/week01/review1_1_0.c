#include <stdio.h> 
#include <string.h> 
void print_reverse(char *str, int end) 
{ 
    if (end < 0) return;
    else{
        printf("%c", str[end]);
    }
    print_reverse(str, end-1); // --end를 매개변수로 넣어줘도 됨

} 

int main() 
{   char str[100]; 
    printf("Enter any string:"); 
    scanf("%s", str); 
    printf("Reversed String is: "); 
    print_reverse(str, strlen(str) - 1); // str과 마지막 인덱스를 매개변수로 return 0; 
} 