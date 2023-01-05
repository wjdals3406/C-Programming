#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 // ����Ʈ�� �ִ�ũ��
//get_length = L->size
typedef int element; // �׸��� ����
typedef struct {
    element array[MAX_LIST_SIZE]; // �迭 ����
    int size; // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

// ���� ó�� �Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1); //���α׷� ����
}
// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType *L)
{
    L->size=0;
}

// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType *L)
{
    // if(L->size==0) return 1;
    // else return 0;
    return (L->size==0);
}

// ����Ʈ�� ���� �� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType *L, int pos) //�ð����⵵:O(1)
{
    //pos�� ������ ���� : 0 ~ L->size-1
    if(pos<0 || pos>=L->size) 
        error("��ġ ����");
    return L->array[pos];
} 

// ����Ʈ ���
void print_list(ArrayListType *L)
{
    int i;
    for (i = 0; i<L->size; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}
void insert_last(ArrayListType *L, element item) //���� add_rear�� ���� ��
{
    if( L->size >= MAX_LIST_SIZE ) { // if(is_full())�� ���� �ǹ�
        error("����Ʈ �����÷ο�");
    }
    L->array[L->size++] = item;
    //���ο� �����Ͱ� ���Ե� ��ġ = L->size
    //0~L->size-1���� ���� ä���� ���� -> L->size�� ���� ä���� ��, L->size ����
}
void insert(ArrayListType *L, int pos, element item) //�ð����⵵:O(n)
{
    //������ �����Ϸ��� �����ϴ� ���ؿ��� �ڿ� �ִ� �����͵� �ϳ��� �ڷ� �̵���Ŵ
    // (L->size-1)���� pos���� �ڿ������� ��ĭ�� �̵�
    if (!is_full(L) && (pos>=0) && (pos<L->size)) {
        for (int i = (L->size - 1); i >= pos; i--)
            L->array[i + 1] = L->array[i]; //������ �̵�
        L->array[pos] = item;//������ ����
        L->size++;
    }
}

element delete(ArrayListType *L, int pos)
{
    element item;
    if (pos<0 || pos >= L->size && !is_empty(L))
        error("��ġ ����");
    item = L->array[pos];
    for (int i = pos; i<(L->size - 1); i++)
        L->array[i] = L->array[i + 1];
    L->size--;
    return item;
}

int main(void)
{
    // ArrayListType�� �������� �����ϰ� ArrayListType��
    // ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
    ArrayListType list;
    init(&list);
    insert(&list, 0, 10); print_list(&list); // 0��° ��ġ�� 10 �߰�
    insert(&list, 0, 20); print_list(&list); // 0��° ��ġ�� 20 �߰�
    insert(&list, 0, 30); print_list(&list); // 0��° ��ġ�� 30 �߰�
    insert_last(&list, 40); print_list(&list); // �� ���� 40 �߰�
    delete(&list, 0); print_list(&list); // 0��° �׸� ����
    return 0;
} 