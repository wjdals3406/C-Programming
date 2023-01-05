#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode *link;
} ListNode;
// 오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
// 노드 pre 뒤에 새로운 노드 삽입, 중간에 노드 삽입
ListNode* insert_next(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; //(2)
    p->link = pre->link; //(3)
    pre->link = p; //(4)
    return head; //(5)
}
//시간복잡도 : O(1)
ListNode* insert_first(ListNode *head, int value) //단순연결리스트에서 head는 맨앞의 노드를 가리킴
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; // (2)
    // p->link = NULL; //안써도 됨
    p->link = head; // 헤드 포인터의 값을 복사 //(3)
    head = p; // 헤드 포인터 변경 //(4)
    return head; // 변경된 헤드 포인터 반환
}
//시간복잡도 : O(n)
ListNode* insert_last(ListNode *head, int value)
{
    ListNode *temp = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value;
    p->link = NULL;
    // (2)
    if (head == NULL) // 공백 리스트이면
        head = p;
    else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = p;
    }
    return head; // 변경된 헤드 포인터 반환
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
    if (head == NULL) error("삭제할 항목이 없음");
    removed = head; // (1) 포인터의 대입연산 : head가 가지고 있는 주소를 removed가 갖는다
    head = removed->link; // (2) removed 안쓰고 그냥 head = head->link하면 안됨??
    free(removed); // (3) 
    return head; // (4)
}
ListNode* delete_last(ListNode *head)
{
    // 노드가 하나면 temp사용 필요 없음
    ListNode *temp = head;
    ListNode *prevTemp;
    ListNode *removed;
    if (head == NULL) error("삭제할 항목이 없음");
    if (temp->link == NULL) { // 하나의 노드
        removed = temp->link;
        temp->link = NULL;
        free(removed);
        return NULL;
    }
    else { // 둘 이상의 노드 / prevTemp는 temp를 따라감
        while (temp->link != NULL) {
            prevTemp = temp;
            temp = temp->link;
        }
        removed = temp;
        prevTemp->link = NULL;
        free(removed);
        return head; // 그대로
    }
}
void print_list(ListNode *head)
{
    ListNode *p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode *search(ListNode *head, int x) //특정값이 위치한 자리 찾아감
{
    ListNode *p;
    p = head;
    while( p != NULL ){
        if( p->data == x ) return p; // 탐색 성공
        p = p->link;
    }
    return NULL; // 탐색 실패일 경우 NULL 반환
}
ListNode *concat(ListNode *head1, ListNode *head2)//head1 뒤에 head2를 잇고 싶을 때
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
ListNode *reverse(ListNode *head) // 뒤집기 / 앞에서부터 p를 뒤집고 r에 연결
{
    // 순회 포인터로 p, q, r을 사용
    ListNode *p, *q, *r;
    p = head; // p는 역순으로 만들 리스트
    q = NULL; // q는 역순으로 만들 노드
    while (p != NULL){
        r = q; // r은 역순으로 된 리스트. r은 q, q는 p를 차례로 따라간다.
        q = p ;
        p = p->link ;//이동
        q->link =r; // q의 링크 방향을 바꾼다.
    }
    return q; // q는 역순으로 된 리스트의 헤드 포인터
    //head 한번 출력해보기
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