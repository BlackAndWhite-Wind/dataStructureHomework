// 队列的链式存储
#include<iostream>

using namespace std;

typedef struct linknode{
    int data;
    struct linknode *next;
}linknode;

typedef struct{
    linknode *front,*rear;
}linkqueue;


void initQueue1(linkqueue &q){
    // 带头结点的版本
    q.front=q.rear=(linknode *)malloc(sizeof(linknode));
    q.front->next=nullptr;
    // 不带头结点的版本
    // q.front=q.rear=nullptr;
}

bool isEmpty(linkqueue q){
    // 不带头结点
    return q.front==nullptr;
}

void enQueue(linkqueue &q,int x){
    // 带头结点
    linknode *s=(linknode *)malloc(sizeof(linknode));
    s->data=x;
    s->next=nullptr;
    q.rear->next=s;
    q.rear=s;
    // 不带头结点
    /*
        linknode *s=(linknode *)malloc(sizeof(linknode));
        s->data=x;
        s->next=nullptr;
        if(q.front==nullptr){
            q.front=q.rear=s;
        }
        else{
            q.rear->next=s;
            q.rear=s;
        }
    */
}

bool deQueue(linkqueue &q,int &x){
    // 带头结点
    if(isEmpty(q)) return false;
    linknode *p=q.front->next;
    x=p->data;// 保存队头元素
    q.front->next=p->next;// 修改头结点的next指针
    if(q.rear==p){ // 如果是最后一个元素出队
        q.rear=q.front; // 修改rear指针
    }
    free(p);// 释放空间
    return true;
    // 不带头结点
    /*
        if(q.front==nullptr){
            return false;
        }
        linknode *p=q.front;
        x=p->data;
        q.front=q.front->next;
        if(q.front==p){
            p.rear=q.rear=nullptr;
        }
        free(p);
        return true;
    */
}

int main(){
    linkqueue q;
    initQueue1(q);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    int x;
    deQueue(q,x);
    cout<<x<<endl;
    deQueue(q,x);
    cout<<x<<endl;
    deQueue(q,x);
    cout<<x<<endl;
    return 0;
}