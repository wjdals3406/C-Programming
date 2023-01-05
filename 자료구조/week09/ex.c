#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
    char name[50];
}element;
typedef struct QueueNode { // 큐의 노드의 타입
    element data;
    struct QueueNode *link;
} QueueNode;
typedef struct { // 큐 ADT 구현
    QueueNode *front, *rear;
} LinkedQueueType;

// 초기화 함수
void init(LinkedQueueType *q)
{
    q->front = q->rear = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedQueueType *q)
{
    return (q->front==NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedQueueType *q) // 항상 거짓, 포화상태일때가 없다. 연결리스트로 구현하였으므로
{
    return 0;
}
// 삽입 함수 시간 복잡도 : O(1)
void enqueue(LinkedQueueType *q, element item)
{
    QueueNode *temp=(QueueNode *)malloc(sizeof(QueueNode));
    if(temp == NULL )
        printf("메모리를 할당할 수 없습니다");
    else {
        temp->data = item; // 데이터 저장
        temp->link = NULL; // 링크 필드를 NULL
        if( is_empty(q) ){ // 큐가 공백이면
            q->front = temp;
            q->rear = temp;
        }
        else { // 큐가 공백이 아니면
            q->rear->link = temp; // 순서가 중요
            q->rear = temp;
        }
    }
}
// 삭제 함수
element dequeue(LinkedQueueType *q)
{
    QueueNode *temp = q->front;
    element item;
    if( is_empty(q) ) // 공백상태
        printf("큐가 비어 있읍니다");
    else {
        item = temp->data; // 데이터를 꺼낸다.
        q->front = q->front->link; // front 를 다음노드를 가리키도록 한다.
        if( q->front == NULL ) // 공백 상태
            q->rear = NULL;
        free(temp); // 동적메모리 해제
        return item; // 데이터 반환
    }
}

int get_count(LinkedQueueType *q)
{
    QueueNode *p;
    int num=0;
    for (p= q->front; p != NULL; p = p->link)
        num++;
    return num;
    
}
 
void print_queue(LinkedQueueType *q)
{
    QueueNode *p;
    for (p= q->front; p != NULL; p = p->link)
        printf("%s ", p->data);
    printf("\n");
}

//나의 큐 : q, 상대방 큐: p
void check(LinkedQueueType* q1, LinkedQueueType* q2, element item){
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
    LinkedQueueType manQ; 
    LinkedQueueType womanQ;
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