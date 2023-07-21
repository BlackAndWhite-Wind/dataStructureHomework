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

LinkList create_list_odd_even(LinkList &head){
    int i=0;
    LinkList B=new Lnode;
    B->next=nullptr;
    Lnode *a=head,*b=B,*p;
    p=head->next;
    head->next=nullptr;
    while(p){
        i++;
        if(i%2==0){
            b->next=p;
            b=p;
        }
        else{
            a->next=p;
            a=p;
        }
        p=p->next;
    }
    a->next=nullptr;
    b->next=nullptr;
    return B;
}