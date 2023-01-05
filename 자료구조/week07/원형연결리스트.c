#include <stdio.h>
#include <stdlib.h>
//원형연결리스트는 초기화함수가 없나? -> 그냥 ListNode *head = NULL; 이건듯
typedef int element;
typedef struct ListNode { // 노드 타입
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

    printf("%d->", p->data); // 마지막 노드 출력
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
    return head; // 변경된 헤드 포인터를 반환한다.
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); //새로 데이터 삽입할때만 malloc 사용
    node->data = data;
    if (head == NULL) {
        head = node; //단순 연결 리스트는 여기까지만 했었음
        node->link = head; //새로 생기는 노드의 링크가 null이 되면 안됨
    }
    else {
        node->link = head->link; // (1)
        head->link = node; // (2)
        head = node; // (3)
    }
    return head; // 변경된 헤드 포인터를 반환한다.
}
ListNode* delete_first(ListNode* head)
{
    ListNode *removed;
    if (head == NULL) {
        printf("리스트가 비어 삭제를 못함\n");
        return NULL;
    }
    else if (head == head->link) { // 즉 하나의 노드가 남았을때
        removed = head; //head의 링크가 head를 가리키게 해야함
        head = NULL;
        // head->link = head; 이렇게 해도 head->link = NULL이기 때문에 
        // 의미적으로 보면 여기까지 써야하지만 결론적으로는 head의 link가 head를 가리킴 
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
        printf("리스트가 비어 삭제를 못함\n");
        return NULL;
    }
    else if (head == head->link) { // 즉 하나의 노드가 남았을때
        removed = head; //head의 링크가 head를 가리키게 해야함
        head = NULL;
        // head->link = head; 이렇게 해도 head->link = NULL이기 때문에 
        // 의미적으로 보면 여기까지 써야하지만 결론적으로는 head의 link가 head를 가리킴 
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

ListNode* search(ListNode* head, element data) //p의 link가 head가 될 때까지
{
    ListNode* p = head;
    if (head == NULL) {
        printf("리스트가 비어있음\n");
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
// 원형 연결 리스트 테스트 프로그램
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
