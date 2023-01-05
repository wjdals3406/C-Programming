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
            for(j=start; j<n; j++){ //n이 3일때, 0번째와 3번째, 1번쨰와 4번쨰, 2번째와 5번째값이 같은지 확인 
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
                get_num(count, copynum);
            }
            else{
                copynum[cidx++] = count+48;
                rcount++;
            }
            for(int k = 0; k<n; k++){
                copynum[cidx++] = num[curidx++];
            }
            rcount+=n;

        }
        else{
            copynum[cidx++] = num[curidx];
            rcount++;
            curidx++;
        }
        nidx+=n;
        count = 1;
    }
    if(rcount < minval){
        minval = rcount;
    }
    // copynum[cidx]='\0';
    }
    
    // printf("%s\n", copynum);
    printf("%d", minval);
    
    return 0;
}