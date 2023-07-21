// 如何判断单链表有环

#include <iostream>
#include <cstring>
#include <algorithm>

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
    LinkList tail=head;
    for(int i=0;i<n;i++){
        LinkList newNode = new Lnode;
        newNode->data=a[i];
        newNode->next=nullptr;
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}

bool hasCycle(LinkList head) {
    if(!head || !head->next) return false;
    LinkList slow=head,fast=head->next;
    while(fast && fast->next){
        if(slow==fast) return true;
        slow=slow->next;
        fast=fast->next->next;
    }
    return false; 
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    LinkList head=init_list(a,n);
    cout<<hasCycle(head)<<endl;
    return 0;
}
