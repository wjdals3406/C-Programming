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
ListNode* insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; // (2)
    p->link = NULL; //안써도 됨
    p->link = head; // 헤드 포인터의 값을 복사 //(3)
    // head = p; // 헤드 포인터 변경 //(4)
    // return head; // 변경된 헤드 포인터 반환
    return p;
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
ListNode* delete_last(ListNode* head)
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
void print_list(ListNode* head)
{
    ListNode *p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode* search(ListNode *head, int x) //특정값이 위치한 자리 찾아감
{
    ListNode *p;
    p = head;
    while( p != NULL ){
        if( p->data == x ) return p; // 탐색 성공
        p = p->link;
    }
    return NULL; // 탐색 실패일 경우 NULL 반환
}
ListNode* concat(ListNode *head1, ListNode *head2)
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

ListNode *reverse(ListNode *head)
{
    // 순회 포인터로 p, q, r을 사용
    ListNode *p, *q, *r;
    p = head; // p는 역순으로 만들 리스트
    q = NULL; // q는 역순으로 만들 노드
    while (p != NULL){
        r = q; // r은 역순으로 된 리스트. r은 q, q는 p를 차례로 따라간다.
        q = p ;
        p = p->link ;
        q->link =r; // q의 링크 방향을 바꾼다.
    }
    printf("head 출력\n");
    print_list(head);
    return q; // q는 역순으로 된 리스트의 헤드 포인터
}

int is_in_list(ListNode *head, element item){//item 이 리스트에 있으면 1 을 아니면 0 을 반환
    if (search(head, item) != NULL)
        return 1;
    return 0;
}
    
int get_length(ListNode *head){//단순 연결 리스트에 존재하는 노드의 수를 반환
    
    ListNode *p = head; //(1)
    int cnt = 0;

    while (p != NULL){
        cnt++;
        p = p->link;
    }
    return cnt; 
}

int get_total(ListNode *head) {//단순연결리스트의 모든 데이터 값을 더한 합을 반환
    ListNode *p = head; 
    int total = 0;
 
    while (p != NULL){
        total += p->data;
        p = p->link;
    }
    return total; 
}

element get_entry(ListNode *head, int pos){//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data를 반환
    ListNode *p = head;
    int i;
    if (pos >= 0 || pos < get_length(head)) {
        for(i=0; i<pos; i++)
            p = p->link;
    }
    return p->data;
}

ListNode* delete_by_key(ListNode *head, int key){
    ListNode *p = head;
    ListNode *pre = NULL;
    ListNode *removed;
    if (head == NULL) error("삭제할 항목이 없음");

    while(p != NULL){
        if (p->data == key){
            removed = p;
            pre->link = removed->link;
            free(removed);
            return head;
        }
        pre = p;
        p = p->link;
    }
}

// pos 위치의 노드를 삭제
ListNode* delete_pos(ListNode *head, int pos){
    // 노드가 하나면 temp사용 필요 없음
    ListNode *p = head;
    ListNode *pre = NULL;
    ListNode *removed;
    int cnt = 0;
    if (head == NULL) error("삭제할 항목이 없음");
    
    for(int i=0; i<pos; i++){
        pre = p;
        p = p->link;
    }
    removed = p;
    pre->link = removed->link;
    free(removed);
    return head; // 그대로
}

//pos 위치에 value 를 갖는 노드를 추가
ListNode* insert_pos(ListNode *head, int pos, element value){
    ListNode *p = head;
    ListNode *pre = NULL;
    ListNode *insert = (ListNode *)malloc(sizeof(ListNode));
    insert->data = value;
    insert->link = NULL;

    if(pos==0) 
        head = insert_first(head, value);
    else{
        for(int i=0; i<pos; i++){
            pre = p;
            p = p->link;
        }
        insert->link = pre->link;
        pre->link = insert;
    }
   
    return head;
}

int main(void)
{
    ListNode *list1 = NULL, *list2 = NULL, *list3;
    //list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
    list1 = insert_first(list1, 10);
    list1 = insert_first(list1, 20);
    list1 = insert_first(list1, 30);
    // list1을 출력
    printf("list1 = ");
    print_list(list1);
    //list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10->
    list1 = delete_first(list1);
    printf("list1 = ");
    print_list(list1);
    //list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다.
    list2 = insert_first(list2, 11);
    list2 = insert_first(list2, 22);
    list2 = insert_first(list2, 33);
    list2 = insert_first(list2, 44);
    // list2를 출력
    printf("list2 = ");
    print_list(list2);
    // list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
    list2 = delete_last(list2);
    // list2를 출력
    printf("list2 = ");
    print_list(list2);
    //list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
    list3 = reverse(list2);
    //list3를 출력한다.
    printf("list3 = ");
    print_list(list3);
    
    // list1 = 20->10->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
    list1 = concat(list1, list3);
    printf("list1 = ");
    print_list(list1);

    //(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자
    printf("값이 존재하면 1, 아니면 0: 답은 %d\n", is_in_list(list1, 11));
    printf("노드 길이: %d\n", get_length(list1));
    printf("합계: %d\n", get_total(list1));
    printf("인덱스 %d에 있는 데이터 반환: %d\n", 2, get_entry(list1,2));
    list1 = delete_by_key(list1, 33);
    printf("list1 = ");
    print_list(list1);
    list1 = insert_pos(list1, 1, 50); 
    printf("list1 = ");
    print_list(list1);
    list1 = delete_pos(list1, 1);
    printf("list1 = ");
    print_list(list1);
}