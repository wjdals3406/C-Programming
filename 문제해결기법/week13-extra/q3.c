#include <stdio.h>
#include <stdlib.h>

int main(){
    //n : ����, m : �и�
    int n, m;
    int rootN = 1, rootM = 1; 
    int pLN = 0, pLM = 1, pRN = 1, pRM = 0; //LM : ���ʰ�, RN : �����ʰ�

    scanf("%d %d", &n, &m);

    while ( n*rootM != m*rootN){
        if (n *rootM < m*rootN) { //�Է¹��� ���� 5/7���� Ŭ ��
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