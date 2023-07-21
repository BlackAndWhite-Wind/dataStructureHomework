#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

// 队列的链式实现
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

// 初始化链队列
void init_linkqueue(LinkQueue &q){
    // 初始的时候，front和rear均指向头节点
    q.front=q.rear=new LinkNode;
    q.front->next=nullptr;

    //q.front=q.rear=nullptr;不带头结点
}

// 判断队列是否为空
bool is_linkqueue_empty(LinkQueue &q){
    return q.front==q.rear;
    // return q.front==nullptr;不带头结点
}

// 入队
void enqueue(LinkQueue &q,int x){
    LinkNode *s=new LinkNode;
    s->data=x;
    s->next=nullptr;
    q.rear->next=s;
    q.rear=s;
}

// 出队
bool dequeue(LinkQueue &q,int x){
    if(is_linkqueue_empty(q)) return false;
    LinkNode *p=q.front->next;
    x=p->data;
    q.front->next=p->next;
    if(q.rear==p) q.rear=q.front;
    delete p;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
