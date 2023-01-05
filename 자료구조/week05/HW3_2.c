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
ListNode* insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p->data = value; // (2)
    p->link = NULL; //�Ƚᵵ ��
    p->link = head; // ��� �������� ���� ���� //(3)
    // head = p; // ��� ������ ���� //(4)
    // return head; // ����� ��� ������ ��ȯ
    return p;
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
ListNode* delete_last(ListNode* head)
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
void print_list(ListNode* head)
{
    ListNode *p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode* search(ListNode *head, int x) //Ư������ ��ġ�� �ڸ� ã�ư�
{
    ListNode *p;
    p = head;
    while( p != NULL ){
        if( p->data == x ) return p; // Ž�� ����
        p = p->link;
    }
    return NULL; // Ž�� ������ ��� NULL ��ȯ
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
    // ��ȸ �����ͷ� p, q, r�� ���
    ListNode *p, *q, *r;
    p = head; // p�� �������� ���� ����Ʈ
    q = NULL; // q�� �������� ���� ���
    while (p != NULL){
        r = q; // r�� �������� �� ����Ʈ. r�� q, q�� p�� ���ʷ� ���󰣴�.
        q = p ;
        p = p->link ;
        q->link =r; // q�� ��ũ ������ �ٲ۴�.
    }
    printf("head ���\n");
    print_list(head);
    return q; // q�� �������� �� ����Ʈ�� ��� ������
}

int is_in_list(ListNode *head, element item){//item �� ����Ʈ�� ������ 1 �� �ƴϸ� 0 �� ��ȯ
    if (search(head, item) != NULL)
        return 1;
    return 0;
}
    
int get_length(ListNode *head){//�ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ
    
    ListNode *p = head; //(1)
    int cnt = 0;

    while (p != NULL){
        cnt++;
        p = p->link;
    }
    return cnt; 
}

int get_total(ListNode *head) {//�ܼ����Ḯ��Ʈ�� ��� ������ ���� ���� ���� ��ȯ
    ListNode *p = head; 
    int total = 0;
 
    while (p != NULL){
        total += p->data;
        p = p->link;
    }
    return total; 
}

element get_entry(ListNode *head, int pos){//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data�� ��ȯ
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
    if (head == NULL) error("������ �׸��� ����");

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

// pos ��ġ�� ��带 ����
ListNode* delete_pos(ListNode *head, int pos){
    // ��尡 �ϳ��� temp��� �ʿ� ����
    ListNode *p = head;
    ListNode *pre = NULL;
    ListNode *removed;
    int cnt = 0;
    if (head == NULL) error("������ �׸��� ����");
    
    for(int i=0; i<pos; i++){
        pre = p;
        p = p->link;
    }
    removed = p;
    pre->link = removed->link;
    free(removed);
    return head; // �״��
}

//pos ��ġ�� value �� ���� ��带 �߰�
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
    //list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�.
    list1 = insert_first(list1, 10);
    list1 = insert_first(list1, 20);
    list1 = insert_first(list1, 30);
    // list1�� ���
    printf("list1 = ");
    print_list(list1);
    //list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->10->
    list1 = delete_first(list1);
    printf("list1 = ");
    print_list(list1);
    //list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�.
    list2 = insert_first(list2, 11);
    list2 = insert_first(list2, 22);
    list2 = insert_first(list2, 33);
    list2 = insert_first(list2, 44);
    // list2�� ���
    printf("list2 = ");
    print_list(list2);
    // list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33->
    list2 = delete_last(list2);
    // list2�� ���
    printf("list2 = ");
    print_list(list2);
    //list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����.
    list3 = reverse(list2);
    //list3�� ����Ѵ�.
    printf("list3 = ");
    print_list(list3);
    
    // list1 = 20->10->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�.
    list1 = concat(list1, list3);
    printf("list1 = ");
    print_list(list1);

    //(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ����
    printf("���� �����ϸ� 1, �ƴϸ� 0: ���� %d\n", is_in_list(list1, 11));
    printf("��� ����: %d\n", get_length(list1));
    printf("�հ�: %d\n", get_total(list1));
    printf("�ε��� %d�� �ִ� ������ ��ȯ: %d\n", 2, get_entry(list1,2));
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