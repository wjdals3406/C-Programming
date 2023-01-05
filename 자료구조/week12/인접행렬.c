//������ı׷���.c �ҽ�����
#include <stdio.h>
#include "queue.h"
#define MAX_VERTICES 50
#define TRUE 1;
#define FALSE 0;
int visited[MAX_VERTICES]; // ���������� 0 ���� �ڵ� �ʱ�ȭ
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
void graph_init(GraphType *g) // �׷��� �ʱ�ȭ
{
    int r,c;
    g->n=0;
    for(r=0;r<MAX_VERTICES;r++)
        for(c=0;c<MAX_VERTICES;c++)
            g->adj_mat[r][c]=0;
}
void insert_edge(GraphType *g, int start, int end) // ���� ���� ����
{
    if( start >= g->n || end >= g->n ){
        fprintf(stderr,"�׷���: ���� ��ȣ ����");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
void insert_vertex(GraphType *g, int v) // ���� ���� ����
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "�׷��� ������ ���� �ʰ�");
        return;
    }
    g->n++;
}
/* ���� �켱 Ž��
depth_first_search(v)
v �� �湮�Ǿ��ٰ� ǥ��;
for all u �� (v �� ������ ����) do
 if (u �� ���� �湮���� �ʾ�����)
 then depth_first_search(u)
*/
void dfs_mat(GraphType *g, int v) // ���� �켱 Ž��
{
    int w;
    visited[v] = 1;
    printf("%d ", v);
    for (w = 0; w < g->n; w++)
        if ((g->adj_mat[v][w] == 1) && (visited[w] == 0)) { // w ���� �����̰� w �� ���� �湮���� �ʾ�����
            dfs_mat(g, w); // ��� ȣ��
        }
 }
/* ���� �켱 Ž��
breadth_first_search(v)
v �� �湮�Ǿ��ٰ� ǥ��;
ť Q �� ���� v �� ����;
while (not is_empty(Q)) do
 ť Q ���� ���� w �� ����;
 for all u �� (w �� ������ ����) do
 if (u �� ���� �湮���� �ʾ�����) then u �� �湮�Ǿ��ٰ� ǥ��;
u �� ť Q �� ����;
*/
void bfs_mat(GraphType *g, int v) // ���� �켱 Ž��
{
    int w;
    QueueType q;
    init(&q); /* ť �ʱ�ȭ */
    visited[v] = TRUE; // ���� v �湮 ǥ��
    printf("%d ", v);
    enqueue(&q, v); // ���� ������ ť�� ����
    while(!is_empty(&q)){
        v = dequeue(&q); // ť�� ���� ����
        for(w=0; w<g->n; w++) // ���� ���� Ž��
        if(g->adj_mat[v][w] && !visited[w]){
            visited[w] = TRUE; // �湮 ǥ��
            printf("%d ", w);
            enqueue(&q, w); // �湮�� ������ ť�� ����
        }
    }
}
 void visited_init()
{
    int i;
    for (i = 0; i < MAX_VERTICES; i++)
        visited[i] = 0;
} 

int main(void)
{
    GraphType g;
    graph_init(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_edge(&g, 0, 1);
    insert_edge(&g, 1, 2);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 3, 0);
    insert_edge(&g, 0, 2);
    printf("\n ���� �켱 Ž��\n");
    dfs_mat(&g, 0); printf("\n");
    visited_init();
    dfs_mat(&g, 1); printf("\n");
    visited_init();
    dfs_mat(&g, 2); printf("\n");
    visited_init();
    dfs_mat(&g, 3); printf("\n");
    printf("\n ���� �켱 Ž��\n");
    visited_init();
    bfs_mat(&g, 0); printf("\n");
    visited_init();
    bfs_mat(&g, 1); printf("\n");
    visited_init();
    bfs_mat(&g, 2); printf("\n");
    visited_init();
    bfs_mat(&g, 3); printf("\n")
}