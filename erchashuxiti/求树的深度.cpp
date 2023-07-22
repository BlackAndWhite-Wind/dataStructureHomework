// 以孩子兄弟链表作为存储结构，求树的深度

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

typedef struct node
{
    int data;
    struct node *fristchild, *nextsibling;
}*Tree;

int get_hight(Tree t){
    if(!t) return 0;
    int h1=get_hight(t->fristchild);
    int h2=get_hight(t->nextsibling);
    return max(h1+1,h2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}