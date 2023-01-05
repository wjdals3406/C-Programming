#include <stdio.h>

int search_binary(int key, int arr[], int low, int high)
{
    int middle;
    while(low <= high) {
        middle = (low+high) / 2;
        if(key == arr[middle]) return middle;
        else if(key > arr[middle]) low = middle + 1;
        else high = middle - 1;
    }
    return -1;
}

int main(void){
	int arr[] = {2,3,5,7,8,9};
int key;

scanf("%d", &key);
printf("%d\n", search_binary(key, arr, 0, sizeof(arr)/sizeof(int) - 1));
}