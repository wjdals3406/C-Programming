#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char num[1000];
    char copynum[1000];
    int slen;
    int nidx=0, cidx=0;
    int flag = 0;
    int count = 1;
    int rcount = 0;
    
    scanf("%s", num);
    slen = strlen(num);

    while(nidx != slen){
        while(nidx != slen - 2 && num[nidx] == num[nidx+1]){
            count++;
            nidx++;
            flag = 1;
        }
        if(flag == 1) {
            copynum[cidx] = count+48;
            rcount++;
            cidx++;
            copynum[cidx] = num[nidx];
            rcount++;
        }
        else{
            copynum[cidx] = num[nidx];
            rcount++;
        }
        count = 1;
        flag = 0;
        nidx++;
        cidx++;
    }
    copynum[cidx]='\0';
    printf("%s\n", copynum);
    printf("%d", rcount);
    
    return 0;
}