#include <stdio.h>

int main(void) {
	int n1, n2, count= 0;
	scanf("%d %d", &n1, &n2);

    while (n1 != 0 && n2 != 0){
        if (n1%10 + n2%10 >= 10){
            n1 /= 10;
            n2 /= 10;
            n1++;
            count++;
        }
        else{
            n1 /= 10;
            n2 /= 10;
        }
    }
    if (n1 >= 10) count++;

    printf("%d",count);
}

// int main(void) {
// 	int n1, n2, count= 0, remain1, remain2, carry = 0;
// 	scanf("%d %d", &n1, &n2);

//     while (n1 != 0 && n2 != 0){
//         remain1 = n1%10;
//         remain2 = n2%10;
//         if ( remain1 + remain2 + carry >= 10){
//             carry = 1;
//             count++;
//         }
//         else{
//             carry = 0;
//         }

//         n1 /= 10;
//         n2 /= 10;
//     }
//     if (n1 >= 10) count++;

//     printf("%d", count);
}