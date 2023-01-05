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
        printf("학번 : %d\t", student[i].id);
        printf("영어 : %d\t", student[i].english);
        printf("수학 : %d\t", student[i].math);
        printf("국어 : %d \n", student[i].korean);
    }
    printf("\n");
}

int partition(struct Student *A, int p, int r){
    int i, j;
    struct Student t;
   
     i = p-1;

    for( j=p; j<r; j++){ 
        if(A[j].korean > A[r].korean){
            i++;
            //swap A[i] & A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
 }

void quick_sort(struct Student *A, int p, int r){
    int q;
    if(p<r){ 
        q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}


int main(void)
{
    int n, i;
    struct Student *student;
    srand(time(NULL));
    

    printf("학생수 : ");
    scanf("%d", &n);
    
    student = (struct Student*) malloc(sizeof(struct Student) * n);
        
    for(i=0; i<n; i++){
        student[i].id = i+1;
        student[i].korean = rand() % 101;
        student[i].english = rand() % 101;
        student[i].math = rand() % 101;
    }

    print_array(student, n);
    printf("<정렬수행>\n");
    quick_sort(student, 0, n-1);
    print_array(student, n);

    free(student);
}