#include<iostream>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int front,rear;
}sqQueue;

void initQueue(sqQueue &q){
    q.front=q.rear=0;
}

void destroyQueue(sqQueue &q){
    q.front=q.rear=0;
}

bool isEmpty(sqQueue q){
    return q.front==q.rear;
}

bool isFull(sqQueue q){
    return (q.rear+1)%N==q.front;
}

bool enQueue(sqQueue &q,int x){
    if(isFull(q)) return false;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%N;
    return true;
}

bool deQueue(sqQueue &q,int &x){
    if(isEmpty(q)) return false;
    x=q.data[q.front];
    q.front=(q.front+1)%N;
    return true;
}

bool getHead(sqQueue q,int &x){
    if(isEmpty(q)) return false;
    x=q.data[q.front];
    return true;
}

int getLength(sqQueue q){
    return (q.rear+N-q.front)%N;
}

int main(){
    int n;
    cin>>n;
    sqQueue q;
    initQueue(q);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        enQueue(q,x);
    }
    cout<<getLength(q)<<endl;
    int x;
    while(!isEmpty(q)){
        deQueue(q,x);
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}