#include <stdio.h> 
int N = 0;

// void get_num(int n, int check){
//     if(n==0) return;
    
//     get_num(n/10, check);
//     N++;
//     if(N==check) {
//         printf("%d ", n%10);
//         return;
//     }
    
// }

// int main(void)
// {
//     int n, num = 1;
//     scanf("%d", &n);
//     if(n < 4) {
//         printf("%d\n", 3 * n);
//         }

//     while(num<= n){
//         if(n < 4) {
//             N++;
//             num++;
//         }
//         else{
//             get_num(3 * num, n);
//             num++;
//         }
            
//     }
    
// }

int solution(int n){
    int count = 0;
    
    while(n!=0){
        n /= 10;
        count++;
    }

    return count;
}

int main(){
    //계속 빼서 0보다 작아지는 순간 내가 원하는 값이 있을 것이다.
    int n, i, m;
    int number;

    scanf("%d", &n);

    for(i=3; ; i=i+3){
        m = solution(i);
        if(n - m <= 0) {
            break;
        }
        else {
            n = n - m; // n - m = 0 -> 마지막 숫자, n - m = -1 / n- m = -2
        }
    }

    printf("%d", m);

    number = i;

    for(i=0; i<m-n; i++)
        number = number / 10;

    printf("%d\n", number%10);
    return 0;
}