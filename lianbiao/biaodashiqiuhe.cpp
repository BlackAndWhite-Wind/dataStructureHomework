// 栈求后缀表达式

#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
string str;

int evalRPN(string str){ // 逆波兰表达式求值
    for(auto &ch:str){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            auto a=stk.top(); stk.pop();
            auto b=stk.top(); stk.pop();
            if(ch=='+') stk.push(b+a);
            else if(ch=='-') stk.push(b-a);
            else if(ch=='*') stk.push(b*a);
            else stk.push(b/a);
        }
        else stk.push(ch-'0');
    }
    return stk.top();
}

int main(){
    cin>>str;
    cout<<evalRPN(str)<<endl;
    return 0;
}