//���� ť �ڵ�
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4
typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}
//�ʱ�ȭ�Լ�
void init(QueueType *q)
{
    q->front = q->rear = 0;
}
//������� ���� �Լ�
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

//��ȭ ���� �����Լ� : front�� rear�� �ϳ� ����(front�� rear���� �ϳ� �ռ� ����)
int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
//�����Լ�
void enqueue(QueueType *q, element item) 
{
    if( is_full(q) )
        error("ť�� ��ȭ�����Դϴ�");

    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
    // q->queue[++(q->rear)] = item; -> ���� ť
}
//�����Լ�
element dequeue(QueueType *q)
{
    if( is_empty(q) )
        error("ť�� ���� �����Դϴ�");

    q->front = (q->front+1) % MAX_QUEUE_SIZE; //front ���� �� ������ ����
    return q->queue[q->front];
}

// ������ �Լ�
element peek(QueueType *q)
{
    if( is_empty(q) )
        error("ť�� ��������Դϴ�");
    return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
}
// �� �Լ�
void main()
{
    QueueType q;
    init(&q);
    printf("front=%d rear=%d\n",q.front, q.rear);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("dequeue()=%d\n",dequeue(&q));
    enqueue(&q, 4);
    // printf("dequeue()=%d\n",dequeue(&q));
    // printf("dequeue()=%d\n",dequeue(&q));
    printf("front=%d rear=%d\n",q.front, q.rear);
} 