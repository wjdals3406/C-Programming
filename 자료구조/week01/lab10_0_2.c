//����2 LAB10_0_2
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
    struct student *sp = &aStudent; //4) sp�� aStudent�� ����Ű���Ѵ�
    printf("Enter student name: ");
    scanf("%s", sp->name ); //5)
    printf("Enter midterm and final score: ");
    scanf("%d %d", &sp->midterm, &sp->final ); //6)
    printf("\n�̸�\t�߰�\t�б⸻\n");
    printf("%s\t%d\t%d\n", sp->name, sp->midterm, sp->final); //7)
} 

// sizeof(Student)�� ����? 20 + 4 + 4 = 28 ����Ʈ
// Student Ÿ���� �޸𸮸� �����Ͽ� sp�� ����Ű�� �ϴ� ������?
    //student *sp = (student *)malloc(sizeof(student));