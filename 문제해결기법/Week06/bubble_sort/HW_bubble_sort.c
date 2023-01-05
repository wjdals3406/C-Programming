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

void swap(struct Student *array, int index, int next_index)
{
    struct Student tmp;
    tmp = array[index];
    array[index] = array[next_index];
    array[next_index] = tmp;
}

void bubble_sort(struct Student *array, int n, int num){
    int i, j;
    struct Student tmp;

    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if( num == 1){
                if(array[j].korean < array[j+1].korean){
                    swap(array, j, j+1);
                }
               
            }
            else if(num == 2){
                if(array[j].english < array[j+1].english){
                    swap(array, j, j+1);
                }
            }
            else if(num == 3){
                if(array[j].math < array[j+1].math){
                    swap(array, j, j+1);
                }
            }
            else if(num == 4){
                if(array[j].id > array[j+1].id){
                    swap(array, j, j+1);
                }
            }
        }
    }
}

// void bubble_sort(struct Student *array, int n, int num){
//     int i, j;
//     struct Student tmp;

//     if (num == 1){
//         for(i=0; i<n-1; i++){
//             for(j=n-1; j>i; j--){
//                 if(array[j].korean > array[j-1].korean){
//                     swap(array, j, j-1);
//                 }
//             }
//         }
//     }

//     else if (num == 2){
//         for(i=0; i<n-1; i++){
//             for(j=n-1; j>i; j--){
//                 if(array[j].math > array[j-1].math){
//                     swap(array, j, j-1);
//                 }
//             }
//         }
//     }

//     else if (num == 3){
//         for(i=0; i<n-1; i++){
//             for(j=n-1; j>i; j--){
//                 if(array[j].english > array[j-1].english){
//                     swap(array, j, j-1);
//                 }
//             }
//         }
//     }

//     else if (num==4){
//         for(i=0; i<n-1; i++){
//             for(j=0; j<n-i-1; j++){
//                 if(array[j].id > array[j+1].id)
//                     swap(array, j, j+1);
//             }
//         }
//     }
    
// }

int main(void)
{
    int n, i, num;
    struct Student *student;
    srand(time(NULL));

    printf("�л� ���� �Է��ϼ��� : ");
    scanf("%d", &n);
    
    student = (struct Student*) malloc(sizeof(struct Student) * n);
        
    for(i=0; i<n; i++){
        student[i].id = i+1;
        student[i].korean = rand() % 101;
        student[i].english = rand() % 101;
        student[i].math = rand() % 101;
    }

    print_array(student, n);

    printf("���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> : ");
    scanf("%d", &num);
    while(num != 0){
        bubble_sort(student, n, num);
        print_array(student, n);
        printf("���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> : ");
        scanf("%d", &num);
    }
    
    free(student);
}