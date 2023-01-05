//컴프2 LAB10_0_2
#include <stdio.h>
struct student {
    char name[20];
    int midterm;
    int final;
};

typedef struct student Student;

int main(void)
{
    struct student aStudent;
    struct student *sp = &aStudent; //4) sp가 aStudent를 가르키게한다
    printf("Enter student name: ");
    scanf("%s", sp->name ); //5)
    printf("Enter midterm and final score: ");
    scanf("%d %d", &sp->midterm, &sp->final ); //6)
    printf("\n이름\t중간\t학기말\n");
    printf("%s\t%d\t%d\n", sp->name, sp->midterm, sp->final); //7)
} 

// sizeof(Student)의 값은? 20 + 4 + 4 = 28 바이트
// Student 타입의 메모리를 생성하여 sp가 가르키게 하는 문장은?
    //student *sp = (student *)malloc(sizeof(student));