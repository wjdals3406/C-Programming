#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cidx = 0;
int rcount = 0;

void get_num(int n){
    if(n==0) return;
    get_num(n/10);
    rcount++;
}

int main(){
    char num[1000];
    char copynum[1000];
    int slen;
    int n=0;
    int minval = 999;

    scanf("%s", num);
    slen = strlen(num);

    for(n=1; n<=slen/2; n++){
        int nidx=0;
        int curidx = 0;
        int count = 1;
        cidx = 0;
        rcount = 0;

        while(curidx != slen){
        int start =0;
        int flag = 0;
        int j;

        while(nidx <= slen-n && num[nidx] == num[nidx + n] ){
            for(j=start; j<n; j++){  
                if(num[j] != num[j+n]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                count ++;
                start += n;
                nidx+=n;
                curidx+=n;
            }
            else break;
        }
        
        if(count > 1) {
            if (count > 10){
                get_num(count);
            }
            else rcount++;
            
            for(int k = 0; k<n; k++){
                curidx++;
            }
            rcount+=n;
        }

        else{
            rcount++;
            curidx++;
        }
        nidx+=n;
        count = 1;
    }
    if(rcount < minval){
        minval = rcount;
        }
    }
    printf("%d", minval);
    
    return 0;
}