#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int a[100], b[100];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);

    if(a[m-1] == n){
        int i, idx;
        for(i = m-1; i>=1; i--){
            if(a[i] - a[i-1] > 1 && i != 1) {
                idx = i-1;
                break;
            }
        }
        if (i==0){
            idx = 0;
        }
        for (int j = 0; j < m; j++){
                if(j < idx) b[j] = a[j];
                else if(j == idx) b[j] = a[j]+1;
                else b[j] = b[j-1] + 1;
            }
            if(b[m-1] > n) printf("-1");
            else{
                for (int j = 0; j < m; j++)
                    printf("%d ", b[j]);
            }
    }

    else{
        for (int i = 0; i < m; i++){
            if(i==m-1){
                printf("%d ", a[i]+1);
            }
            else{
                printf("%d ", a[i]);
            }
        }
    }
	return 0;
}