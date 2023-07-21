// 在带头节点的单链表L中，删除所有值为x的节点，并释放其空间。
// 假设值为x的节点不唯一，试编写算法实现上述操作。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

int n,delete_num,a[N];

void delete_x(LinkList &L,int x){
    Lnode *p=L->next,*pre=L,*q;
    while(p){
        if(p->data==x){
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else{
            pre=p;
            p=p->next;
        }
    }
}

LinkList init_list(int a[],int n){
    // 尾插法建立带头结点的单链表
    LinkList L=(Lnode*)malloc(sizeof(Lnode));
    L->next=nullptr;
    Lnode *r=L;
    for(int i=0;i<n;i++){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        p->data=a[i];
        p->next=nullptr;
        r->next=p;
        r=p;
    }
    return L;
}

int main(){
    cin>>n>>delete_num;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    LinkList L=init_list(a,n);
    delete_x(L,delete_num);
    Lnode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}
