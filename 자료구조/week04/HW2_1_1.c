#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
    char name[50];
}element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

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

int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
//삽입함수
void enqueue(QueueType *q, element item) 
{
    if( is_full(q) ){
        printf("대기자가 꽉찼으니 담기회를 이용하세요.\n");
        return;
    }

    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}
//삭제함수
element dequeue(QueueType *q)
{
    if( is_empty(q) )
        printf("큐가 공백 상태입니다\n");

    q->front = (q->front+1) % MAX_QUEUE_SIZE; //front 증가 후 데이터 제거
    return q->queue[q->front];
}

// 엿보기 함수
element peek(QueueType *q)
{
    if( is_empty(q) )
        printf("큐가 공백상태입니다\n");
    return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
    int rear = q->rear;
    int front = q->front;
    
    //if(q->rear < q->front)
        // return (q->rear + MAX_QUEUE_SIZE - q->front);
    // else
    //     return (q->rear - q->front)

    return ((rear - front ) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
 
void print_queue(QueueType* q) {
	if (is_empty(q)) {
        printf("\n");
		return;
	}
	
    int i = q->front;
    do {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%s ", q->queue[i].name);

    } while (i != q->rear);
    printf("\n");
	
}

//나의 큐 : q, 상대방 큐: p
void check(QueueType* q1, QueueType* q2, element item){
    if(is_full(q1))
        printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용 \n");
    else{
        if(is_empty(q2)){
            printf("아직 대상자가 없습니다. 기다려주십시요. \n");
            enqueue(q1, item);
        }
        else{
            enqueue(q1, item);
            printf("커플이 탄생했습니다! %s과 %s\n", dequeue(q2).name, dequeue(q1).name);
            }
    }
}

int main(void) 
{ 
    QueueType manQ; 
    QueueType womanQ;
    element newPerson; 
    char ch, gen;
    init(&manQ); 
    init(&womanQ); 

    printf("미팅 주선 프로그램입니다.\n");
    printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
    scanf(" %c", &ch); 
    while(ch != 'q'){
        if (ch == 'i'){
            printf("이름을 입력:");
            scanf("%s", newPerson.name); 
            printf("성별을 입력<m or f>:"); 
            scanf(" %c", &gen);
            if (gen == 'm')
                check(&manQ, &womanQ, newPerson);
            else
                check(&womanQ, &manQ, newPerson);
             
        }
        else if (ch == 'c'){
            printf("남성 대기자 %d명: ", get_count(&manQ));
            print_queue(&manQ);
            printf("여성 대기자 %d명: ", get_count(&womanQ));
            print_queue(&womanQ);
        }

        printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
        scanf(" %c", &ch); 
    }
        
}