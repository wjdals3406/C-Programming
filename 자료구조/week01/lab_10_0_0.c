//����2 LAB10_0_0
#include <stdio.h>
struct student { // ����ü��
    char name[10];
    int midterm;
    int final;
};

int main(void)
{
    struct student aStudent;
    printf("Enter student name: ");
    scanf("%s", aStudent.name ); //1) name�� �迭�̱⿡ �տ� &�� �ٿ����� �ȵ�
    printf("Enter midterm and final score: ");
    scanf("%d %d", &aStudent.midterm, &aStudent.final ); //2)
    printf("\n�̸�\t�߰�\t�б⸻\n");
    printf("%s\t%d\t%d\n", aStudent.name, aStudent.midterm, aStudent.final ); //3)
} 