// Q是一个队列，S是一个空栈，实现将队列Q中的元素逆置的算法

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse(stack<int> &S, queue<int> &Q){
    while(!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
    while(!S.empty()){
        Q.push(S.top());
        S.pop();
    }
}

int main(){
    queue<int> Q;
    stack<int> S;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        Q.push(x);
    }
    reverse(S, Q);
    while(!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }
    return 0;
}