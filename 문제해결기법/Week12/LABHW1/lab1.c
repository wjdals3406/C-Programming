#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void makeCode(char alpha[], char encode[], int dist) {
    int i;
    for(i=0; i<26; i++)
        alpha[i] = 'A' + i;

    for(i=0; i<26; i++){
        encode[i] = alpha[i] + dist;
        if(encode[i] > 'Z') 
            encode[i] = encode[i] - 26;
    }
}

void printCode(char code[]) {
    printf("%s\n", code);
}

void encodeCode(char plain_text[], char encoded_text[], char encode[]) {
    int str_len;
    str_len = strlen(plain_text);

    for(int i=0; i<str_len; i++){
        if(plain_text[i] >= 'A' && plain_text[i] <= 'Z'){
            int idx = plain_text[i] - 'A';
            encoded_text[i] = encode[idx];
        }
        else
            encoded_text[i] = plain_text[i];
    }
}

int main(){
    char alpha[27] = "";
    char encode[27] = "";
    char plain_text[81] = ""; 
    char encoded_text[81] = ""; 
    int dist;

    printf("Enter a distance for encoding:");
    scanf("%d", &dist);
    makeCode(alpha, encode, dist);

    printf("---------------------------------------\n");
    printf("alphabet:\t");
    printCode(alpha);
    printf("encoded:\t");
    printCode(encode);
    printf("---------------------------------------\n");

    fgets(plain_text, 80, stdin); //remove enter
    printf("Enter a sentence to encode:");
    fgets(plain_text, 80, stdin);

    encodeCode(plain_text, encoded_text, encode );
    printf("original sentence:\t");
    printf("%s", plain_text);
    printf("encoded sentence:\t");
    printf("%s", encoded_text);
}