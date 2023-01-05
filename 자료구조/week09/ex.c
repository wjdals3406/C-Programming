#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
    char name[50];
}element;
typedef struct QueueNode { // ť�� ����� Ÿ��
    element data;
    struct QueueNode *link;
} QueueNode;
typedef struct { // ť ADT ����
    QueueNode *front, *rear;
} LinkedQueueType;

// �ʱ�ȭ �Լ�
void init(LinkedQueueType *q)
{
    q->front = q->rear = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType *q)
{
    return (q->front==NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType *q) // �׻� ����, ��ȭ�����϶��� ����. ���Ḯ��Ʈ�� �����Ͽ����Ƿ�
{
    return 0;
}
// ���� �Լ� �ð� ���⵵ : O(1)
void enqueue(LinkedQueueType *q, element item)
{
    QueueNode *temp=(QueueNode *)malloc(sizeof(QueueNode));
    if(temp == NULL )
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
    else {
        temp->data = item; // ������ ����
        temp->link = NULL; // ��ũ �ʵ带 NULL
        if( is_empty(q) ){ // ť�� �����̸�
            q->front = temp;
            q->rear = temp;
        }
        else { // ť�� ������ �ƴϸ�
            q->rear->link = temp; // ������ �߿�
            q->rear = temp;
        }
    }
}
// ���� �Լ�
element dequeue(LinkedQueueType *q)
{
    QueueNode *temp = q->front;
    element item;
    if( is_empty(q) ) // �������
        printf("ť�� ��� �����ϴ�");
    else {
        item = temp->data; // �����͸� ������.
        q->front = q->front->link; // front �� ������带 ����Ű���� �Ѵ�.
        if( q->front == NULL ) // ���� ����
            q->rear = NULL;
        free(temp); // �����޸� ����
        return item; // ������ ��ȯ
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

//���� ť : q, ���� ť: p
void check(LinkedQueueType* q1, LinkedQueueType* q2, element item){
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
    LinkedQueueType manQ; 
    LinkedQueueType womanQ;
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