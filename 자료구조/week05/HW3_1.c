#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 5 // 리스트의 최대크기
typedef int element; // 항목의 정의
typedef struct {
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
}
// 리스트 초기화 함수
void init(ArrayListType *L)
{
    L->size=0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L)
{
    // if(L->size==0) return 1;
    // else return 0;
    return (L->size==0);
}

// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 0을 반환
int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType *L, int pos) //시간복잡도:O(1)
{
    //pos이 가지는 범위 : 0 ~ L->size-1
    if(pos<0 || pos>=L->size) 
        error("위치 오류");
    return L->array[pos];
} 

// 리스트 출력
void print_list(ArrayListType *L)
{
    int i;
    for (i = 0; i<L->size; i++)
        printf("%d->", L->array[i]);
    printf("리스트끝\n");
}
void insert_last(ArrayListType *L, element item)
{
    if( L->size >= MAX_LIST_SIZE ) { 
        error("리스트가 오버플로우");
    }
    L->array[L->size++] = item;
}
void insert(ArrayListType *L, int pos, element item) 
{
    if (is_full(L)) error("리스트가 오버플로우");
    if (!is_full(L)) {
        for (int i = (L->size - 1); i >= pos; i--)
            L->array[i + 1] = L->array[i]; //데이터 이동
        L->array[pos] = item;//데이터 삽입
        L->size++;
    }
}

element delete(ArrayListType *L, int pos)
{
    element item;
    if (pos<0 || pos >= L->size && !is_empty(L))
        error("위치 오류");
    item = L->array[pos];
    for (int i = pos; i<(L->size - 1); i++)
        L->array[i] = L->array[i + 1];
    L->size--;
    return item;
}

void clear(ArrayListType *L) {
    init(L);
}

void insert_first(ArrayListType *L, element item) {
    if (is_full(L)) error("리스트가 오버플로우");
    if (!is_full(L)) {
        for (int i = (L->size - 1); i >= 0; i--)
            L->array[i + 1] = L->array[i]; //데이터 이동
        L->array[0] = item;//데이터 삽입
        L->size++;
    }
}

int get_length(ArrayListType *L) {
    return L->size;
}

void replace(ArrayListType *L, int pos, element item) {
    if (pos>=0 && pos < L->size)
        L->array[pos] = item;
    else printf("위치 오류\n");
}

int is_in_list(ArrayListType *L, element item) {
    for(int i=0; i<L->size; i++){
        if (L->array[i] == item) return 1;
    }
    return 0;
}

void delete_by_key(ArrayListType *L, element key){
    for(int i=0; i<L->size; i++){
        if (L->array[i] == key){
            delete(L,i);
            return;
        }
    }
   printf("삭제하려는 key값 %d는 리스트에 없습니다\n", key);
}


int main(void)
{
    ArrayListType list1;
    init(&list1);
    insert(&list1, 0, 20);
    insert(&list1, 0, 10); print_list(&list1);
    clear(&list1); print_list(&list1);
    insert_last(&list1, 90); print_list(&list1);
    insert(&list1, 0, 30);
    insert(&list1, 0, 20);
    insert(&list1, 0, 10); print_list(&list1);
    delete(&list1, 2); print_list(&list1);
    printf("\n-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");
    insert_first(&list1, 9); print_list(&list1);
    insert_last(&list1, 99); print_list(&list1);

    // 현재 리스트가 꽉 찬(크기 5개) 상태이므로 한 항목을 더 추가하면 "리스트 오버플로우"을 출력한다. 
    insert_first(&list1, 1); print_list(&list1);

    printf("길이는 %d\n", get_length(&list1));
    printf("3번째 데이타는 %d\n", get_entry(&list1, 2));
    replace(&list1, 3, 40); print_list(&list1);
    printf("20은 리스트에 %s\n", is_in_list(&list1, 20) ? "있습니다" : "없습니다");
    printf("22는 리스트에 %s\n", is_in_list(&list1, 22) ? "있습니다" : "없습니다");
    delete_by_key(&list1, 20); print_list(&list1);
    delete_by_key(&list1, 22); print_list(&list1);
}