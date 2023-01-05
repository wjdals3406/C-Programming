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


int partition(struct Student *A, int p, int r, int num){
    int i, j;
    struct Student t;
   
     i = p-1;

    for( j=p; j<r; j++){ 
        if( num == 1){
            if(A[j].korean > A[r].korean){
                i++;
                swap(A, i, j);
        }
            
        }
        else if(num == 2){
            if(A[j].math > A[r].math){
                i++;
                swap(A, i, j);
            }
        }
        else if(num == 3){
            if(A[j].english > A[r].english){
                i++;
                swap(A, i, j);
            }
        }
        else if(num == 4){
                
            if(A[j].id < A[r].id){
                i++;
                swap(A, i, j);
            }
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
 }

void quick_sort(struct Student *A, int p, int r, int num){
    int q;
    if(p<r){ 
        q = partition(A, p, r, num);
        quick_sort(A, p, q-1, num);
        quick_sort(A, q+1, r, num);
    }
}


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
        quick_sort(student, 0, n-1, num);
        print_array(student, n);
        printf("���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> : ");
        scanf("%d", &num);
    }
    
    free(student);
}