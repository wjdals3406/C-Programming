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

int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
//�����Լ�
void enqueue(QueueType *q, element item) 
{
    if( is_full(q) ){
        printf("����ڰ� ��á���� ���ȸ�� �̿��ϼ���.\n");
        return;
    }

    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}
//�����Լ�
element dequeue(QueueType *q)
{
    if( is_empty(q) )
        printf("ť�� ���� �����Դϴ�\n");

    q->front = (q->front+1) % MAX_QUEUE_SIZE; //front ���� �� ������ ����
    return q->queue[q->front];
}

// ������ �Լ�
element peek(QueueType *q)
{
    if( is_empty(q) )
        printf("ť�� ��������Դϴ�\n");
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

//���� ť : q, ���� ť: p
void check(QueueType* q1, QueueType* q2, element item){
    if(is_full(q1))
        printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿� \n");
    else{
        if(is_empty(q2)){
            printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�. \n");
            enqueue(q1, item);
        }
        else{
            enqueue(q1, item);
            printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(q2).name, dequeue(q1).name);
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

    printf("���� �ּ� ���α׷��Դϴ�.\n");
    printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
    scanf(" %c", &ch); 
    while(ch != 'q'){
        if (ch == 'i'){
            printf("�̸��� �Է�:");
            scanf("%s", newPerson.name); 
            printf("������ �Է�<m or f>:"); 
            scanf(" %c", &gen);
            if (gen == 'm')
                check(&manQ, &womanQ, newPerson);
            else
                check(&womanQ, &manQ, newPerson);
             
        }
        else if (ch == 'c'){
            printf("���� ����� %d��: ", get_count(&manQ));
            print_queue(&manQ);
            printf("���� ����� %d��: ", get_count(&womanQ));
            print_queue(&womanQ);
        }

        printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
        scanf(" %c", &ch); 
    }
        
}