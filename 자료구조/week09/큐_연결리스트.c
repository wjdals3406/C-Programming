//LinkedQueue.c
#include <stdio.h>
#include <malloc.h>
typedef int element; // ����� Ÿ��
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
void print_queue(LinkedQueueType *q)
{
    QueueNode *p;
    for (p= q->front; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}
// ����� ť �׽�Ʈ �Լ�
void main()
{
    LinkedQueueType queue;
    init(&queue); // ť �ʱ�ȭ
    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    return 0;
}