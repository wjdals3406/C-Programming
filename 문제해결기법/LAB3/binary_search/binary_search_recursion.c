#include <stdio.h>

int search_binary(int key, int arr[], int low, int high)
{
    // int middle;
    // if(low <= high){
    //     middle = (low + high) / 2;
    //     if (key == arr[middle])
    //         return middle;
    //     else if (key < arr[middle])
    //         return search_binary(key, arr, low, middle - 1);
    //     else return search_binary(key, arr, middle + 1, high);
    // }
    // return -1;

    int middle;
   
    if (low > high) return -1;
    
    middle = (low + high) / 2;
    if (key == arr[middle])
        return middle;
    else if (key < arr[middle])
        return search_binary(key, arr, low, middle - 1);
    else return search_binary(key, arr, middle + 1, high);
    
    return -1;
}

int main(void){
	int arr[] = {2,3,5,7,8,9};
int key;

scanf("%d", &key);
printf("%d\n", search_binary(key, arr, 0, sizeof(arr)/sizeof(int) - 1));
}