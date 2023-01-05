#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { //노드타입
    element data;
    struct ListNode *link;
} ListNode;

//오류처리함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//노드 pre뒤에 새로운 노드삽입

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
    p->link = head; //헤드 포인터의 값을 복사//(3)
    head = p; //헤드 포인터 변경 //(4)
    return head; //변경된 헤드포인터 반환
}

ListNode* insert_last(ListNode *head, int value)
{
    ListNode *temp = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value;
    p->link = NULL;
    // (2)
    if (head == NULL) //공백 리스트이면
        head = p;
    else {
        while (temp->link != 0)
        temp = temp->link;
        temp->link = p;
    }
    return head; //변경된 헤드포인터 반환

} 

// pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete_next(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link; // (2)
    free(removed); // (3)
    return head; // (4)
}
