// 循环链表

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*Linklist;

typedef struct Dnode{
    int data;
    struct Dnode *prior,*next;
}Dnode,*Dlinklist;

// 初始化循环链表
bool init_list(Linklist &L){
    L=(Lnode*)malloc(sizeof(Lnode));
    if(!L) return false;
    L->next=L;
    return true;
}

// 判断循环链表是否为空(单和双)
bool is_empty(Linklist L){
    return L->next==L;
}

// 判断p结点是否为循环链表的表尾结点(单和双)
bool pnode_is_tail(Linklist L,Lnode *p){
    return p->next==L;
}

// 初始化循环双链表
bool init_list(Dlinklist &L){
    L=(Dnode*)malloc(sizeof(Dnode));
    if(!L) return false;
    L->prior=L;
    L->next=L;
    return true;
}