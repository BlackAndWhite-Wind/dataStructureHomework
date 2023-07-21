// 给定一个带头结点的单链表，设head为头指针，节点结构为（data，next），
// data为整型元素，next为指针，试写出算法：
//按递增次序输出单链表中各节点的数据元素，
//并释放节点所占的存储空间（要求：不允许使用数组作为辅助空间）

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

int n,a[N];

LinkList init_list(int a[],int n){
    LinkList head = new Lnode;
    head->next=nullptr;

    LinkList tai=head;
    for(int i=0;i<n;i++){
        LinkList newNode =new Lnode;
        newNode->data=a[i];
        newNode->next=nullptr;
        tai->next=newNode;
        tai=newNode;
    }
    return head;
}

void delete_min_onebyone(LinkList &head){
    while(head->next){
        Lnode *p=head,*q=p->next,*o;
        while(q->next){
            if(q->next->data<p->next->data){
                p=q;
            }
            q=q->next;
        }
        cout<<p->next->data<<" ";
        o=p->next;
        p->next=o->next;
        delete o;
    }
    free(head);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    LinkList head=init_list(a,n);
    delete_min_onebyone(head);
    return 0;
}