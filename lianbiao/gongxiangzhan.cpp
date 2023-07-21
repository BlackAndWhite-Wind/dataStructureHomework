#include<iostream>

using namespace std;
const int N=100010;

typedef struct{
    int data[N];
    int top0,top1;//top0为栈0的栈顶，top1为栈1的栈顶
    // top0从下往上依次递增，top1从上往下依次递减
}shStack;// 共享栈（两个栈共享一片空间）

void initStack(shStack &s){
    s.top0=-1;//栈0的栈顶
    s.top1=N;//栈1的栈顶
}

bool stackEmpty(shStack s){
    return s.top0==-1 && s.top1==N;
}

bool stackFull(shStack s){
    return s.top0+1==s.top1;
}

bool push0(shStack &s,int x){// 入栈0
    if(stackFull(s)) return false;
    s.data[++s.top0]=x;
    return true;
}

bool push1(shStack &s,int x){// 入栈1
    if(stackFull(s)) return false;
    s.data[--s.top1]=x;
    return true;
}

bool pop0(shStack &s,int &x){// 出栈0
    if(s.top0==-1) return false;
    x=s.data[s.top0--];
    return true;
}

bool pop1(shStack &s,int &x){// 出栈1
    if(s.top1==N) return false;
    x=s.data[s.top1++];
    return true;
}

bool getTop0(shStack s,int &x){// 取栈0的栈顶元素
    if(s.top0==-1) return false;
    x=s.data[s.top0];
    return true;
}

bool getTop1(shStack s,int &x){// 取栈1的栈顶元素
    if(s.top1==N) return false;
    x=s.data[s.top1];
    return true;
}

void stackDestory(shStack &s){
    s.top0=-1;
    s.top1=N;
}

int main(){
    shStack s;
    initStack(s);
    push0(s,1);
    push0(s,2);
    push0(s,3);
    push1(s,4);
    push1(s,5);
    push1(s,6);
    int x;
    pop0(s,x);
    cout<<x<<endl;
    pop1(s,x);
    cout<<x<<endl;
    getTop0(s,x);
    cout<<x<<endl;
    getTop1(s,x);
    cout<<x<<endl;
    stackDestory(s);
    return 0;
}