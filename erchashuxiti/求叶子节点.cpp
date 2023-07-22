// 编程求以孩子兄弟表示法存储的森林的叶子节点数

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct node{
    int data;
    struct node *fristchild,*nextsibling; 
}*Tree;

int count(Tree t){
    if(!t) return 0;
    if(!t->fristchild) return 1+count(t->nextsibling);
    return count(t->fristchild)+count(t->nextsibling);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
