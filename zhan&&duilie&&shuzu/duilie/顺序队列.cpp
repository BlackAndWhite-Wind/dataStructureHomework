#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

// 顺序队列的代码实现
typedef struct{
    int data[N];
    int front,rear;
}SqQueue;

// 初始化队列
void init_queue(SqQueue &q){
    q.front=q.rear=0;
}

// 判断队列是否为空
bool is_queue_empty(SqQueue q){
    return q.rear==q.front;
}

// 判断队列是否已满
bool is_queue_full(SqQueue q){
    return (q.rear+1)%N==q.front;
}

// 入队
bool en_queue(SqQueue &q,int x){
    if(is_queue_full(q)) return false;
    q.data[q.rear]=x;// 新的元素插入队尾
    q.rear=(q.rear+1)%N;// 队尾指针+1取模
    return true;
}

// 出队
bool de_queue(SqQueue &q,int &x){
    if(is_queue_empty(q)) return false;
    x=q.data[q.front];// 队头元素出队
    q.front=(q.front+1)%N;// 队头指针+1取模
    return true;
}

// 获取队头元素
bool get_head(SqQueue q,int &x){
    if(is_queue_empty(q)) return false;
    x=q.data[q.front];
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
