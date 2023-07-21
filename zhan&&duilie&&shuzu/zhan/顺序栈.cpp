#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

// 顺序栈的代码实现
typedef struct {
    int data[N];
    int top;
}SqStack;

// 初始化顺序栈
void init_stack(SqStack &s) {
    s.top=-1;
}

// 判断栈是否为空
bool sqstack_is_empty(SqStack s){
    return s.top==-1;
}

// 判断栈是否已满
bool sqstack_is_full(SqStack s){
    return s.top==N-1;
}

// 新元素入栈
bool sqstack_push(SqStack &s,int x){
    if(sqstack_is_full(s)) return false;
    s.data[++s.top]=x;
    return true;
}

// 出栈操作
bool sqstack_pop(SqStack &s,int &x){
    if(sqstack_is_empty(s)) return false;
    x=s.data[s.top--];
    return true;
}

// 读取栈顶元素
bool get_top(SqStack s,int &x){
    if(sqstack_is_empty(s)) return false;
    x=s.data[s.top];
    return true;
}

void test_sqstack(){
    SqStack s;
    init_stack(s);
    for(int i=0;i<20;i++) sqstack_push(s,i);
    while(!sqstack_is_empty(s)){
        int x;
        sqstack_pop(s,x);
        cout<<x<<" ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    test_sqstack();

    return 0;
}
