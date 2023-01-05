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
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
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
        printf("ť�� ��� �����ϴ�");
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

    printf("���� �ּ� ���α׷��Դϴ�.\n");
    do{
        printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
        scanf("%c", &ch);
        if (ch == 'i')
        {
            printf("�̸��� �Է�:");
            scanf("%s", newPerson.name);
            printf("������ �Է�<m or f>:");
            scanf(" %c", &gen);

            if (gen == 'm'){
                if (is_empty(&womanQ)){
                    printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
                    enqueue(&manQ, newPerson);
                }
                else
                    printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", newPerson.name, dequeue(&womanQ).name);
            }
            else if (gen == 'f'){
                if (is_empty(&manQ)){
                    printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
                    enqueue(&womanQ, newPerson);
                }
                else
                    printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", newPerson.name, dequeue(&manQ).name);
            }
        }
        else if (ch == 'c')
        {
            printf("���� ����� %d��: ", get_count(&manQ));
            print_queue(&manQ);
            printf("\n���� ����� %d��: ", get_count(&womanQ));
            print_queue(&womanQ);
            printf("\n");
        }

    } while(ch != 'q');
}

