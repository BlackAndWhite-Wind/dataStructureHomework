// 若希望循环队列中的元素都能得到利用，则需要设置一个标志域tag，
// 并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的
// 队列时满还是空，试编写与次结构相对应的入队和出队算法


#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int front,rear,tag;
}SqQueue;

// 初始化队列
void init_queue(SqQueue &q){
    q.front=q.rear=0;
}

// 入队
int enqueue(SqQueue &q,int x){
    if(q.front==q.rear && q.tag==1) return 0;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%N;
    q.tag=1;
    return 1;
}

int dequeue(SqQueue &q,int x){
    if(q.front==q.rear && q.tag==0) return 0;
    x=q.data[q.front];
    q.front=(q.front+1)%N;
    q.tag=0;
    return 1;
}

void test(){
    SqQueue q;
    init_queue(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    int x;
    dequeue(q,x);
    cout<<x<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    test();
    
    return 0;
}
