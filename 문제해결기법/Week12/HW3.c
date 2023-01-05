#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void check(char input_text[], int dist, int checked[], char sub[]){
    int i=0;
    int str_len;
    int idx=0, aidx=0;
    int flag = 1;
    int iidx=0;
    int sidx=0;

    str_len = strlen(input_text);
    while(sidx < 26){
        if(i < str_len){
            iidx = input_text[i] - 'A';
            if(checked[iidx] != 1){
                checked[iidx] = 1;
                sub[sidx++] = input_text[i]; //sub의 인덱스를 다르게 줘야 함
            }
            i++;
            continue;
        }
        sub[sidx] = 'A' + aidx;
        if(checked[sub[sidx] - 'A'] != 1){
            checked[sub[sidx] - 'A'] = 1;
            sidx++;
        }
        aidx++;
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
    char input_text[31] = "";
    char plain_text[81] = ""; 
    char encoded_text[81] = "";
    char input_file[31] = "";
    char output_file[31] = "";
    int checked[27] = {0};

    FILE *fp1, *fp2;

    int dist;

    printf("Enter a key to use for encoding:");
    scanf("%s", input_text);
    printf("Enter a distance for encoding:");
    scanf("%d", &dist);
    printf("Enter input file name:");
    scanf("%s", input_file);
    printf("Enter output file name:");
    scanf("%s", output_file);
    makeCode(alpha, encode, input_text, dist, checked, sub);

    printf("---------------------------------------\n");
    printf("alphabet:\t");
    printCode(alpha);
    printf("encoded:\t");
    printCode(encode);
    printf("---------------------------------------\n");

    if ((fp1 = fopen(input_file, "rt")) == NULL) {
        printf("파일오픈에러1"); 
        exit(1); 
    }
    if ((fp2 = fopen(output_file, "wt")) == NULL) {
        printf("파일오픈에러2");
        exit(1);
    }

    while (fgets(plain_text, sizeof(plain_text), fp1) != NULL) {
        char encoded_text[81] = "";
        encodeCode(plain_text, encoded_text, encode );
        fputs(encoded_text, fp2);
    }

    fclose(fp1);
    fclose(fp2);
  
}