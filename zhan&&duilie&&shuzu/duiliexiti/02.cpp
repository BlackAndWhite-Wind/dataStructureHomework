// Q是一个队列，S是一个空栈，实现将队列Q中的元素逆置的算法

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse_elemnet(stack<int> &S, queue<int> &Q){
    while(!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
    while(!S.empty()){
        Q.push(S.top());
        S.pop();
    }
}

void test(){
    queue<int> Q;
    stack<int> S;
    for(int i=0;i<10;i++) Q.push(i);
    reverse_elemnet(S,Q);
    while(!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    test();
    return 0;
}