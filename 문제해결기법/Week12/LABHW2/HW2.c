#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char input_text[], int dist, int checked[], char key[]){
    int i=0;
    int str_len;
    int idx=0, aidx=0;
    int flag = 1;
    int iidx=0;
    int kidx=0;

    str_len = strlen(input_text);
    while(kidx < 26){
        if(i < str_len){
            iidx = input_text[i] - 'A';
            if(checked[iidx] != 1){
                checked[iidx] = 1;
                key[kidx++] = input_text[i]; //sub의 인덱스를 다르게 줘야 함
            }
        }
        else{
            key[kidx] = 'A' + aidx;
            if(checked[key[kidx] - 'A'] != 1){
                checked[key[kidx] - 'A'] = 1;
                kidx++;
            }
            aidx++;
        }
        i++;
        
    }
}

void makeCode(char alpha[], char encode[], char input_text[], int dist, int checked[], char sub[]) {
    int i, j;
    int str_len;
    int idx=0, sidx=0;
    int flag = 1;

    for(i=0; i<26; i++)
        alpha[i] = 'A' + i;

    check(input_text, dist, checked, sub);
    for(i=0; i<26; i++){
        idx = i + dist;
        if(idx>=26) idx= idx-26;
        encode[idx] = sub[sidx++];
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
    char sub[81]="";
    char input_text[27] = "";
    char plain_text[81] = ""; 
    char encoded_text[81] = ""; 
    int checked[27] = {0};

    int dist;

    printf("Enter a key to use for encoding<대문자로 된 단어 입력>:");
    scanf("%s", input_text);
    printf("Enter a distance for encoding:");
    scanf("%d", &dist);
    makeCode(alpha, encode, input_text, dist, checked, sub);

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