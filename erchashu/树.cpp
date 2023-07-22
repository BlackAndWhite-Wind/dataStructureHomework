

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

// 树的双亲表示法的存储结构
typedef struct{
    int data, parent;
}PTNode;

typedef struct{
    PTNode nodes[N];
    int n;
}PTree;


// 树的孩子表示法的存储结构
struct CTNode{
    int child;
    struct CTNode *next;
};
typedef struct {
    int data;
    struct CTNode *firstchild;
}CTBox;
typedef struct {
    CTBox nodes[N];
    int n;
    int root;
}CTree;


// 孩子兄弟表示法（纯链式）
typedef struct CSNode{
    int data;// 数据域
    struct CSNode *firstchild, *nextsibling;// 第一个孩子和右兄弟指针
}CSNode, *CSTree;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
