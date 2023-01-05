#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // ��� Ÿ��
    element data;
    struct ListNode *link;
} ListNode;
// ���� ó�� �Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
// ��� pre �ڿ� ���ο� ��� ����, �߰��� ��� ����
ListNode* insert_next(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; //(2)
    p->link = pre->link; //(3)
    pre->link = p; //(4)
    return head; //(5)
}
//�ð����⵵ : O(1)
ListNode* insert_first(ListNode *head, int value) //�ܼ����Ḯ��Ʈ���� head�� �Ǿ��� ��带 ����Ŵ
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; // (2)
    // p->link = NULL; //�Ƚᵵ ��
    p->link = head; // ��� �������� ���� ���� //(3)
    head = p; // ��� ������ ���� //(4)
    return head; // ����� ��� ������ ��ȯ
}
//�ð����⵵ : O(n)
ListNode* insert_last(ListNode *head, int value)
{
    ListNode *temp = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value;
    p->link = NULL;
    // (2)
    if (head == NULL) // ���� ����Ʈ�̸�
        head = p;
    else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = p;
    }
    return head; // ����� ��� ������ ��ȯ
}

ListNode* delete_next(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link; // (2)
    free(removed); // (3)
    return head; // (4)
}
ListNode* delete_first(ListNode *head)
{
    ListNode *removed;
    if (head == NULL) error("������ �׸��� ����");
    removed = head; // (1) �������� ���Կ��� : head�� ������ �ִ� �ּҸ� removed�� ���´�
    head = removed->link; // (2) removed �Ⱦ��� �׳� head = head->link�ϸ� �ȵ�??
    free(removed); // (3) 
    return head; // (4)
}
ListNode* delete_last(ListNode *head)
{
    // ��尡 �ϳ��� temp��� �ʿ� ����
    ListNode *temp = head;
    ListNode *prevTemp;
    ListNode *removed;
    if (head == NULL) error("������ �׸��� ����");
    if (temp->link == NULL) { // �ϳ��� ���
        removed = temp->link;
        temp->link = NULL;
        free(removed);
        return NULL;
    }
    else { // �� �̻��� ��� / prevTemp�� temp�� ����
        while (temp->link != NULL) {
            prevTemp = temp;
            temp = temp->link;
        }
        removed = temp;
        prevTemp->link = NULL;
        free(removed);
        return head; // �״��
    }
}
void print_list(ListNode *head)
{
    ListNode *p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode *search(ListNode *head, int x) //Ư������ ��ġ�� �ڸ� ã�ư�
{
    ListNode *p;
    p = head;
    while( p != NULL ){
        if( p->data == x ) return p; // Ž�� ����
        p = p->link;
    }
    return NULL; // Ž�� ������ ��� NULL ��ȯ
}
ListNode *concat(ListNode *head1, ListNode *head2)//head1 �ڿ� head2�� �հ� ���� ��
{
    ListNode *p;
    if( head1 == NULL ) return head2;
    else if( head2 == NULL ) return head1;
    else {
        p = head1;
        while( p->link != NULL )
            p = p->link;
        p->link = head2;
        return head1;
    }
}
ListNode *reverse(ListNode *head) // ������ / �տ������� p�� ������ r�� ����
{
    // ��ȸ �����ͷ� p, q, r�� ���
    ListNode *p, *q, *r;
    p = head; // p�� �������� ���� ����Ʈ
    q = NULL; // q�� �������� ���� ���
    while (p != NULL){
        r = q; // r�� �������� �� ����Ʈ. r�� q, q�� p�� ���ʷ� ���󰣴�.
        q = p ;
        p = p->link ;//�̵�
        q->link =r; // q�� ��ũ ������ �ٲ۴�.
    }
    return q; // q�� �������� �� ����Ʈ�� ��� ������
    //head �ѹ� ����غ���
}

int main(void)
{
    ListNode *head1 = NULL, *head2;
    int i;
    for (i = 0; i < 5; i++) {
        head1 = insert_last(head1, i * 10);
        print_list(head1);
    }
    head2 = reverse(head1);
    print_list(head2);
    head2 = insert_pos(head2, 1, 99);
    print_list(head2);
    head2 = delete_last(head2);
    print_list(head2);
    head1 = NULL;
    head1 = insert_first(head1, 100);
    head1 = insert_first(head1, 200);
    print_list(head1);
    head1 = concat(head1, head2);
    print_list(head1);
}