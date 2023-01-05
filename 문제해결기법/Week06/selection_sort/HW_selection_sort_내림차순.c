#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
    int id;
    int korean, english, math;
};

void print_array(struct Student *student, int n){
    for(int i=0; i<n; i++){
        printf("�й� : %d\t", student[i].id);
        printf("���� : %d\t", student[i].english);
        printf("���� : %d\t", student[i].math);
        printf("���� : %d \n", student[i].korean);
    }
    printf("\n");
}

void selection_sort(struct Student *array, int n){
    int i, j, max_idx;
    struct Student tmp;

    for(i=0; i<n-1; i++){
        max_idx = i;
        for(j=i; j<n; j++){
            if(array[max_idx].korean < array[j].korean){
                max_idx = j;
            }
        }
        tmp = array[max_idx];
        array[max_idx] = array[i];
        array[i] = tmp;
    }
} 

// void selection_sort(struct Student *array, int n){
//     int i, j, min, min_idx;
//     struct Student tmp;

//     for(i=0; i<n-1; i++){
//         min_idx = 0;
//         for(j=1; j<n-i; j++){
//             if(array[min_idx].korean > array[j].korean){
//                 min_idx = j;
//             }
//         }
//         tmp = array[min_idx];
//         array[min_idx] = array[n-i-1];
//         array[n-i-1] = tmp;
//     }
// }

int main(void)
{
    int n, i;
    struct Student *student;
    srand(time(NULL));

    printf("�л��� : ");
    scanf("%d", &n);
    
    student = (struct Student*) malloc(sizeof(struct Student) * n);
        
    for(i=0; i<n; i++){
        student[i].id = i+1;
        student[i].korean = rand() % 101;
        student[i].english = rand() % 101;
        student[i].math = rand() % 101;
    }

    print_array(student, n);
    printf("<���ļ���>\n");
    selection_sort(student, n);
    print_array(student, n);

    free(student);
}