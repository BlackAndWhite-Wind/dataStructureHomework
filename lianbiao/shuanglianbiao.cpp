// 双链表

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct Dnode{
    int data;
    struct Dnode *prior,*next;
}Dnode,*Dlinklist;

// 初始化带有头结点的双链表
void init_list(Dlinklist &L){
    L=(Dnode*)malloc(sizeof(Dnode));
    L->prior=NULL;
    L->next=NULL;
}

// 判断双链表是否为空
bool is_empty(Dlinklist L){
    return L->next==NULL;
}

// 在p结点之后插入s结点
bool insert_next_dnode(Dnode *p,Dnode *s){
    if(p==NULL||s==NULL) return false;
    s->next=p->next;
    if(p->next!=NULL) p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}

// 删除p的后继结点q
bool delete_next_dnode(Dnode* p){
    if(!p) return false;
    Dnode *q=p->next;
    if(!q) return false;
    p->next=q->next;
    if(q->next) q->next->prior=p;// q不是最后一个结点
    free(q);
    return true;
}

// 双链表的遍历
void traverse_list(Dlinklist L){
    Dnode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

// 循环释放各个节点的数据
void destory_list(Dlinklist &L){
    while(L->next) delete_next_dnode(L);
    free(L);
    L=NULL;
}