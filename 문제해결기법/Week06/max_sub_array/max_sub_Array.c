#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int right_max_sum(int A[], int left, int right)
{
   int sum = 0;
   int max = A[left];

   for (int i = left; i <= right; i++)
   {
      sum += A[i];
      if (max < sum)
         max = sum;
   }

   return max;
}
int left_max_sum(int A[], int left, int right)
{
   int sum = 0;
   int max = A[right];

   for (int i = right; i >= left; i--)
   {
      sum += A[i];
      if (max < sum)
         max = sum;
   }

   return max;
}
int max_subarray(int* A, int left, int right)
{
   int middle = (left + right) / 2;
   int v1, v2, v3;

   if (left >= right)
      return A[right];

    v1 = max_subarray(A, left, middle);
    v2 = max_subarray(A, middle + 1, right);
    v3 = left_max_sum(A, left, middle ) + right_max_sum(A, middle+1, right);


   if (v1 > v2 && v1 > v3)
      return v1;
   else if (v2 > v1 && v2 > v3)
      return v2;
   else
      return v3;
}

int main(void)
{
   int array_size, max, i;
   int *A;
   scanf("%d", &array_size);

   A = (int*)malloc(sizeof(int) * array_size);
   for (i = 0; i < array_size; i++)
      scanf("%d", &A[i]);

   max = max_subarray(A, 0, array_size - 1);
   printf("%d\n", max);

   free(A);

   return 0;
}