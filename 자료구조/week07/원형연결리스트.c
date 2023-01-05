#include <stdio.h>
#include <stdlib.h>
//�������Ḯ��Ʈ�� �ʱ�ȭ�Լ��� ����? -> �׳� ListNode *head = NULL; �̰ǵ�
typedef int element;
typedef struct ListNode { // ��� Ÿ��
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode* head) 
{
    ListNode* p;
    if (head == NULL) return;
    p = head->link;

    while (p != head){
        printf("%d->", p->data);
        p = p->link;
    } 

    printf("%d->", p->data); // ������ ��� ���
    printf("\n");
}
ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link; // (1)
        head->link = node; // (2)
    }
    return head; // ����� ��� �����͸� ��ȯ�Ѵ�.
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); //���� ������ �����Ҷ��� malloc ���
    node->data = data;
    if (head == NULL) {
        head = node; //�ܼ� ���� ����Ʈ�� ��������� �߾���
        node->link = head; //���� ����� ����� ��ũ�� null�� �Ǹ� �ȵ�
    }
    else {
        node->link = head->link; // (1)
        head->link = node; // (2)
        head = node; // (3)
    }
    return head; // ����� ��� �����͸� ��ȯ�Ѵ�.
}
ListNode* delete_first(ListNode* head)
{
    ListNode *removed;
    if (head == NULL) {
        printf("����Ʈ�� ��� ������ ����\n");
        return NULL;
    }
    else if (head == head->link) { // �� �ϳ��� ��尡 ��������
        removed = head; //head�� ��ũ�� head�� ����Ű�� �ؾ���
        head = NULL;
        // head->link = head; �̷��� �ص� head->link = NULL�̱� ������ 
        // �ǹ������� ���� ������� ��������� ��������δ� head�� link�� head�� ����Ŵ 
        free(removed);
    }
    else {
        removed = head->link;
        head->link = removed->link;
        free(removed);
    }
    return head;
}

ListNode* delete_last(ListNode* head)
{
    ListNode* removed = head;
    ListNode* p = head->link;
    if (head == NULL) {
        printf("����Ʈ�� ��� ������ ����\n");
        return NULL;
    }
    else if (head == head->link) { // �� �ϳ��� ��尡 ��������
        removed = head; //head�� ��ũ�� head�� ����Ű�� �ؾ���
        head = NULL;
        // head->link = head; �̷��� �ص� head->link = NULL�̱� ������ 
        // �ǹ������� ���� ������� ��������� ��������δ� head�� link�� head�� ����Ŵ 
        free(removed);
    }
    else {
        while(p->link != head){
            p = p->link;
        }
        p->link = head->link;
        head = p;
        free(removed);
    }
    
    return head;
}

ListNode* search(ListNode* head, element data) //p�� link�� head�� �� ������
{
    ListNode* p = head;
    if (head == NULL) {
        printf("����Ʈ�� �������\n");
        return NULL;
    }
    
    // do {
    //     if (p->data == data)
    //         return p;
    //     p = p->link;
    // } while (p != head);

    p = head->link;
    do {
        if (p->data == data)
            return p;
        p = p -> link;
    }while(p != head->link);
    
    return NULL;
}
int get_size(ListNode* head)
{
    ListNode* p;
    int cnt = 0;
    if (head == NULL) return 0;
    
    p = head->link;
    do {
        cnt++;
        p = p -> link;
    }while(p != head->link);

    return cnt;
}
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
    ListNode *head = NULL;
    // list = 10->20->30->40
    head = insert_last(head, 20);
    print_list(head);
    head = insert_last(head, 30);
    print_list(head);
    head = insert_last(head, 40);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);
    head = delete_first(head);
    print_list(head);
    head = delete_last(head);
    print_list(head);
    printf("%d\n", get_size(head));
    print_list(head);
    head = search(head, 30);
    print_list(head);
    
    return 0;
}
