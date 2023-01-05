//컴프2 LAB10_0_0
#include <stdio.h>
struct student { // 구조체명
    char name[10];
    int midterm;
    int final;
};

int main(void)
{
    struct student aStudent;
    printf("Enter student name: ");
    scanf("%s", aStudent.name ); //1) name은 배열이기에 앞에 &가 붙여지면 안됨
    printf("Enter midterm and final score: ");
    scanf("%d %d", &aStudent.midterm, &aStudent.final ); //2)
    printf("\n이름\t중간\t학기말\n");
    printf("%s\t%d\t%d\n", aStudent.name, aStudent.midterm, aStudent.final ); //3)
} 