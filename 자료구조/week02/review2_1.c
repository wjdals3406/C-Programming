// Review2_1
#include <stdio.h>
#include <stdlib.h>

// 1) typedef���� ����ü Ÿ�� Score ����
typedef struct{
    int midterm;
    int final;
} Score;

void printScore(Score * p) //2)
{
    printf("�߰���� ������ %d\n", p->midterm );
    printf("�б⸻��� ������ %d\n", p->final );
}
Score* biggerScore(Score *p1, Score *p2) //3)
{
    int p1_score = p1->midterm + p1->final;
    int p2_score = p2->midterm + p2->final;
    if (p1_score > p2_score) return p1;
    else return p2;
}
Score* totalScore(Score *p1, Score *p2) //4)
{
    Score *total;
    total = (Score *)malloc(sizeof(Score));
    total->midterm = p1->midterm + p2->midterm;
    total->final = p1->final + p2->final;
    return total;
}
Score *createScore(int m, int f) //5)
{
    Score *p;
    p = (Score *)malloc(sizeof(Score));
    p->midterm = m;
    p->final = f;
    return p;
}