#include<stdio.h>
int comb(int n, int r)
{
    printf("comb(%d,%d)\n",n,r);
    if (r==0 || r==n)
        return 1;
    else
        return comb(n-1, r-1) + comb(n-r, r);

}

int main(void)
{
    int C;
    C = comb(4,2); // 4C2
    printf("%d\n", C);
    return 0;
}