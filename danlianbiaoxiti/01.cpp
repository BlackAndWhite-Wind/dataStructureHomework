// 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N=1e5+10;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

int n,delete_num,a[N];

void delete_x(LinkList &L,int x){
    Lnode *p;
    if(!L) return;
    if(L->data==x){
        p=L;
        L=L->next;
        free(p);
        delete_x(L,x);
    }
    else delete_x(L->next,x);
}

LinkList init_list(int a[],int n){
    // 采用尾插法，读取n个数，建立不带头结点的单链表L
    LinkList L=new Lnode;
    L->next=NULL;
    Lnode *r=L;
    for(int i=0;i<n;i++){
        Lnode *p=new Lnode;
        p->data=a[i];
        p->next=NULL;
        r->next=p;
        r=p;
    }
    return L;
}

int main(){
    cin>>n>>delete_num;
    for(int i=0;i<n;i++) cin>>a[i];
    LinkList L=init_list(a,n);
    delete_x(L,delete_num);
    Lnode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}