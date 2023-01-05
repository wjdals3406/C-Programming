#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { //���Ÿ��
    element data;
    struct ListNode *link;
} ListNode;

//����ó���Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//��� pre�ڿ� ���ο� ������

ListNode* insert_next(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; //(2)
    p->link = pre->link; //(3)
    pre->link = p; //(4)
    return head; //(5)
}

ListNode* insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; // (2)
    p->link = head; //��� �������� ���� ����//(3)
    head = p; //��� ������ ���� //(4)
    return head; //����� ��������� ��ȯ
}

ListNode* insert_last(ListNode *head, int value)
{
    ListNode *temp = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value;
    p->link = NULL;
    // (2)
    if (head == NULL) //���� ����Ʈ�̸�
        head = p;
    else {
        while (temp->link != 0)
        temp = temp->link;
        temp->link = p;
    }
    return head; //����� ��������� ��ȯ

} 

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete_next(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link; // (2)
    free(removed); // (3)
    return head; // (4)
}
