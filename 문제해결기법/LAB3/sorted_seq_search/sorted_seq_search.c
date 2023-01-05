#include <stdio.h>
int list[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
int sorted_seq_search(int key, int low, int high)
{
    int i;
    for(i = low; i <= high; i++)
    {
        if (list[i] == key){
            return i;
        }
    }
    return -1;
}

int main(void){
	int value;
	int keyIndex;

	scanf("%d", &value);
	keyIndex = sorted_seq_search(value, 0, 9);
	printf("%d", keyIndex);
}