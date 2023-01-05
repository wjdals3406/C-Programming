//원형 큐 코드
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
//초기화함수
void init(QueueType *q)
{
    q->front = q->rear = 0;
}
//공백상태 검출 함수
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

//포화 상태 검출함수 : front랑 rear랑 하나 차이(front가 rear보다 하나 앞선 상태)
int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
//삽입함수
void enqueue(QueueType *q, element item) 
{
    if( is_full(q) )
        error("큐가 포화상태입니다");

    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
    // q->queue[++(q->rear)] = item; -> 선형 큐
}
//삭제함수
element dequeue(QueueType *q)
{
    if( is_empty(q) )
        error("큐가 공백 상태입니다");

    q->front = (q->front+1) % MAX_QUEUE_SIZE; //front 증가 후 데이터 제거
    return q->queue[q->front];
}

// 엿보기 함수
element peek(QueueType *q)
{
    if( is_empty(q) )
        error("큐가 공백상태입니다");
    return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
}
// 주 함수
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