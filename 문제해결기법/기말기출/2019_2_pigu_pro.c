#include <stdio.h>
#include <stdlib.h>

void pick( int items[], int n, int* picked, int picksize, int toPick , int total, int *min) {
//m = picked_size
    int i, lastIndex, smallest, item;
    int sum = 0;
    int diff;

    if(toPick == 0 ) { 
        for (i = 0; i < picksize; i++)
            sum += items[picked[i]];
        diff = abs(total - 2 * sum);
        if (*min > diff)
            *min = diff;

        return; // 능력치 차이 = sum(우리팀) - (total - sum)
    } 
    lastIndex = picksize - toPick -1; 
    
    if (picksize == toPick ) 
        smallest = 0; 
    else 
        smallest = picked[lastIndex] + 1;
    for(item = smallest; item < n; item++) {
        picked[lastIndex + 1] = item;
        pick(items, n, picked, picksize, toPick - 1, total, min);
    }
}

int main()
{
    int n;
    int *ability;
    int *picked;
    int total = 0;
    int min;

    scanf("%d", &n); 
    ability = (int *) malloc(sizeof(int) *(n)); 
    for(int i=0; i<n; i++){
        scanf("%d", &ability[i]);
        total += ability[i];
    }
    picked = (int *) malloc(sizeof(int) *(n/2)); 
    min = total;
    
    picked[0] = 0;
    pick( ability, n,  picked, n/2, n/2-1, total, &min);
    printf("%d", min);

    free(ability);
    free(picked);
}


//전체 total - 우리편합 = 상대편합
// int pick( int items[], int itemsize, int* picked, int picksize, int toPick , int total) {
// //m = picked_size
//     int i, lastIndex, smallest, item;
//     int sum = 0;
//     int diff;
//     int min = total;
//     if(toPick == 0 ) { 
//         for (i = 0; i < picksize; i++)
//             sum += items[picked[i]];

//         return abs(total - 2 * sum); // 상대편 = sum(우리팀) - (total - sum)
//     } 
//     lastIndex = picksize - toPick -1; 
    
//     if (picksize == toPick ) 
//         smallest = 0; 
//     else 
//         smallest = picked[lastIndex] + 1;
//     for(item = smallest; item < itemsize; item++) {
//         picked[lastIndex + 1] = item;
//         diff = pickpick(items, itemsize, picked, picksize, toPick - 1, total);
//         if (min > diff)
//             min = diff;
//     }
//     return min;
// }

// int main()
// {
//     int n;
//     int *ability;
//     int *picked;
//     int total = 0;

//     scanf("%d", &n); 
//     ability = (int *) malloc(sizeof(int) *(n)); 
//     for(int i=0; i<n; i++){
//         scanf("%d", &ability[i]);
//     }
//     picked = (int *) malloc(sizeof(int) *(n/2)); 
    
//     picked[0] = 0;
//     printf("%d", pick( ability, n,  picked, n/2, n/2-1, total ));

//     free(ability);
//     free(picked);
// }

