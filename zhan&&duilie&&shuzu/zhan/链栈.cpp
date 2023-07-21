#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

// 链栈的代码实现
typedef struct linknode{
    int data;
    struct linknode *next;
}linknode,*LiStack;

// 初始化链栈
void init_listack(LiStack &s){ 
    s=nullptr; 
}

// 判断链栈是否为空
bool listack_is_empty(LiStack s){
    return s==nullptr;
}

// 判断链栈是否已满（不会满，因此直接输出false）
bool listack_is_full(LiStack s){
    return false;
}

// 新元素入栈
bool listack_push(LiStack &s,int x){
    linknode *p = new linknode;
    p->data=x;
    p->next=s;
    s=p;
    return true;
}

// 删除栈顶元素
bool listack_pop(LiStack &s,int &x){
    if(!s) return false;
    x=s->data;
    auto p=s;
    s=s->next;
    delete p;
    return true;
}

// 获取栈顶元素
bool get_top(LiStack &s,int x){
    if(!s) return false;
    x=s->data;
    return true;
}

// 获取链栈的长度
int get_length(LiStack s){
    int cnt=0;
    while(s){
        s=s->next;
        cnt++;
    }
    return cnt;
}

// 销毁链栈
void listack_destory(LiStack &s){
    while(s){
        auto p=s;
        s=s->next;
        delete p;
    }
}

void test_lisatck(){
    LiStack s;
    init_listack(s);
    for(int i=0;i<10;i++) listack_push(s,i);
    int x;
    listack_pop(s,x);
    cout<<x<<endl;
    cout<<get_length(s)<<endl;
    listack_destory(s);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    test_lisatck();
    
    return 0;
}
