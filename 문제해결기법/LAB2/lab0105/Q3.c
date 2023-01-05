#include <stdio.h>
// int isOne(int n)
// {
//     int count = 0;
//     while(n!=0){
//         if(n%10 != 1) return 0;
//         n /= 10;
//         count++;
//     }
//     return count;
// }

// int main(void) {
// 	int a, b = 1;
// 	scanf("%d", &a);

//     while(isOne(a * b) == 0){
//         b++;
//     }
//     printf("%d", isOne(a*b));
// }

unsigned long long generate_ones(int nlen){
    unsigned long long ret = 0;
    int i;

    for(i=0; i<nlen; i++){
        ret = ret * 10 + 1;
    }
    return ret;
}

void main(){
    unsigned long long number_ones = 0;
    int input_number;
    int i = 1;

    scanf("%d", &input_number);

    while(1) {
        number_ones = generate_ones( i ); // 1,  11, 111 ...
        if(number_ones % input_number == 0) break;

        i++;
    }
    printf("%d\n", i)
}