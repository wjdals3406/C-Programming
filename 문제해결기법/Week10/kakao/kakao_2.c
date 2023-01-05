#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cidx = 0;
int rcount = 0;

void get_num(int n, char copynum[]){
    if(n==0) return;
    
    get_num(n/10, copynum);
    copynum[cidx++] = n%10 + 48;
    rcount++;
}
int main(){
    char num[1000];
    char copynum[1000];
    int slen;
    int nidx=0;
    int curidx = 0;
    int count = 1;
    // int rcount = 0;

    scanf("%s", num);
    slen = strlen(num);

    while(curidx != slen){
        while(nidx < slen - 3 && num[nidx] == num[nidx+2] && num[nidx+1] == num[nidx+3]){
            count++;
            nidx+=2;
            curidx+=2;
        }
        if(count > 1) {
            if (count > 10){
                get_num(count, copynum);
            }
            else{
                copynum[cidx++] = count+48;
                rcount++;
            }

            copynum[cidx++] = num[curidx++];
            copynum[cidx++] = num[curidx++];
            rcount+=2;
        }
        else{
            copynum[cidx++] = num[curidx];
            rcount++;
            curidx++;
        }
        nidx+=2;
        count = 1;
    }
    copynum[cidx]='\0';
    printf("%s\n", copynum);
    printf("%d", rcount);
    
    return 0;
}