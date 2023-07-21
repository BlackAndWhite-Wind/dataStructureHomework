#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

void inOrderThread(ThreadTree &p,ThreadTree &pre){
    // 中序遍历，递归实现，二叉树的线索化
    if(p){
        inOrderThread(p->lchild,pre);// 递归左子树线索化
        if(!p->lchild){ // 左子树为空，建立前驱线索
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre && !pre->rchild){ // 建立前驱结点的后继线索
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        inOrderThread(p->rchild,pre); // 递归右子树线索化
    }
}

void createInorderThread(ThreadTree T){
    // 中序遍历二叉树T，并将其中序线索化，T指向头结点
    ThreadTree pre=NULL;
    if(T){
        inOrderThread(T,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

ThreadNode *firstNode(ThreadNode *p){
    // 中序线索二叉树中，找到中序序列下的第一个结点
    while(p->ltag==0) p=p->lchild;
    return p;
}

ThreadNode *nextNode(ThreadNode *p){
    // 中序线索二叉树中，找到中序序列下的p结点的后继结点
    if(p->rtag==0) return firstNode(p->rchild);
    else return p->rchild;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
