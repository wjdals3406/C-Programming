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

    int dist, str_len, i;
    FILE *fp1, *fp2;

    printf("Enter a distance for encoding:");
    scanf("%d", &dist);
    makeCode(alpha, encode, dist);

    printf("---------------------------------------\n");
    printf("alphabet:\t");
    printCode(alpha);
    printf("encoded:\t");
    printCode(encode);
    printf("---------------------------------------\n");

    if ((fp1 = fopen("original.txt", "rt")) == NULL) {
        printf("??????1"); 
        exit(1); 
    }
    if ((fp2 = fopen("encoded.txt", "wt")) == NULL) {
        printf("??????2");
        exit(1);
    }

    while (fgets(plain_text, sizeof(plain_text), fp1) != NULL) {
        encodeCode(plain_text, encoded_text, encode );
        fputs(encoded_text, fp2);
        memset(plain_text, 0x00, 81);
        memset(encoded_text, 0x00, 81);
    }

    fclose(fp1);
    fclose(fp2);
}