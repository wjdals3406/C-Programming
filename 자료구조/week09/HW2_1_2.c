#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
} element;

typedef struct QueueNode {
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkedQueueType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
}

void init(LinkedQueueType *q)
{
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType *q)
{
    return (q->front==NULL);
}

int is_full(LinkedQueueType *q) 
{
    return 0;
}

void enqueue(LinkedQueueType *q, element item)
{
    QueueNode *temp=(QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL )
        printf("메모리를 할당할 수 없습니다");
    else {
        temp->data = item; 
        temp->link = NULL; 
        if( is_empty(q) ){ 
            q->front = temp;
            q->rear = temp;
        }
        else { 
            q->rear->link = temp; 
            q->rear = temp;
        }
    }
}

element dequeue(LinkedQueueType *q)
{
    QueueNode *temp = q->front;
    element item;
    if( is_empty(q) )
        printf("큐가 비어 있읍니다");
    else {
        item = temp->data; 
        q->front = q->front->link; 
        if( q->front == NULL ) 
            q->rear = NULL;
        free(temp); 
        return item; 
    }
}

void print_queue(LinkedQueueType *q)
{
    QueueNode *p;
    for (p= q->front; p != NULL; p = p->link)
        printf("%s ", p->data.name);
}

int get_count(LinkedQueueType *q)
{
    QueueNode *p;
    int cnt = 0;
    for (p= q->front; p != NULL; p = p->link){
        cnt++;
    }
    return cnt;
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
    do{
        printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
        scanf("%c", &ch);
        if (ch == 'i')
        {
            printf("이름을 입력:");
            scanf("%s", newPerson.name);
            printf("성별을 입력<m or f>:");
            scanf(" %c", &gen);

            if (gen == 'm'){
                if (is_empty(&womanQ)){
                    printf("아직 대상자가 없습니다. 기다려주십시오.\n");
                    enqueue(&manQ, newPerson);
                }
                else
                    printf("커플이 탄생했습니다! %s과 %s\n", newPerson.name, dequeue(&womanQ).name);
            }
            else if (gen == 'f'){
                if (is_empty(&manQ)){
                    printf("아직 대상자가 없습니다. 기다려주십시오.\n");
                    enqueue(&womanQ, newPerson);
                }
                else
                    printf("커플이 탄생했습니다! %s과 %s\n", newPerson.name, dequeue(&manQ).name);
            }
        }
        else if (ch == 'c')
        {
            printf("남성 대기자 %d명: ", get_count(&manQ));
            print_queue(&manQ);
            printf("\n여성 대기자 %d명: ", get_count(&womanQ));
            print_queue(&womanQ);
            printf("\n");
        }

    } while(ch != 'q');
}

