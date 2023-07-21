
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;
const int N=1e5+10;

class MinStack{
    stack<int> s;
    stack<int> min_s;
public:
    MinStack() {
        min_s.push(INT_MAX);
    }
    void push(int x){
        s.push(x);
        min_s.push(min(min_s.top(),x));
    }

    void pop(){
        s.pop();
        min_s.pop();
    }

    int top(){
        return s.top();
    }

    int getMin(){
        return min_s.top();
    }   
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl;
    minStack.pop();
    cout<<minStack.top()<<endl;
    cout<<minStack.getMin()<<endl;

    
    return 0;
}
