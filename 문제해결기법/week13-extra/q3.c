#include <stdio.h>
#include <stdlib.h>

int main(){
    //n : 분자, m : 분모
    int n, m;
    int rootN = 1, rootM = 1; 
    int pLN = 0, pLM = 1, pRN = 1, pRM = 0; //LM : 왼쪽값, RN : 오른쪽값

    scanf("%d %d", &n, &m);

    while ( n*rootM != m*rootN){
        if (n *rootM < m*rootN) { //입력받은 값이 5/7보다 클 때
            pRN = rootN;
            pRM = rootM;
            printf("L");
        }
        else {
            pLN = rootN;
            pLM = rootM;
            printf("P");

        }
        rootN = pRN + pLN;
        rootM = pRM + pLM;
    }
    printf("\n");
}