//순환호출과 스택 사용 없이 이진트리 구현하기
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    int is_thread; // 단말인지 비단말인지 구별 / 후속자를 사용한 노드인지 아닌지를 결정
} TreeNode;
// is_thread True : 후속자 지정해줘야 함 -> 이거로 인해서 right의 값이 자식노드인지 아니면 후속자인지를 알게됨
// is_thread False : 후속자 지정해주지 않아도 됨
//          7
//      3       6
//    1   2   4   5
//
TreeNode n9 = { 9, NULL, NULL, 1 };
TreeNode n10 = { 10, NULL, NULL, 0 };
TreeNode n1 = { 1, NULL, NULL, 1 }; // 단말 / n1이 단말노드라 어디로 가야하는지 알려줘야 함
TreeNode n2 = { 2, NULL, NULL, 1 }; // 단말 
TreeNode n3 = { 3, &n1, &n2, 0 };
TreeNode n4 = { 4, NULL, NULL, 1 }; // 단말
TreeNode n5 = { 5, &n9, &n10, 0 }; // 단말이지만 중위 순회의 마지막 노드이므로 0으로
TreeNode n6 = { 6, &n4, &n5, 0 };
TreeNode n7 = { 7, &n3, &n6, 0 };
TreeNode *e = &n7;

// 먼저 중위순회 순서대로 쭉 내려가되, 리프노드의 오른쪽 노드의 is_thread를 확인하여 연결된 곳이 있으면 그곳으로 감
//p의 중위 후속 노드를 리턴한다. / 중위 후속자를 찾아줌
TreeNode *find_thread_successor(TreeNode *p)
{
    TreeNode *q = p->right; 

    if (q == NULL || p->is_thread == TRUE) //1, 3번 / q는 후속자
        return q; //후속자 return

    //오른쪽 노드로 왔는데,왼쪽 child가 있으면 왼쪽으로 따라 내려감
    while (q->left != NULL) q = q->left;
    return q;
}
void thread_inorder(TreeNode *t)
{
    TreeNode *q;
    q = t;
    // 일단 중위 순회의 첫 노드로 이동
    while (q->left) q = q->left; // 제일 왼쪽 child로 쭉 내려감
    do
    {
        printf("%d ", q->data);
        q = find_thread_successor(q);
    } while (q);
}
void main()
{
// 단말 노드의 오른쪽 링크에 중위 후속 노드를 연결한다
    n1.right = &n3; //점선 화살표로 연결된 노드
    n2.right = &n7; 
    n4.right = &n6;
    n9.right = &n5;
    thread_inorder(e);
} 