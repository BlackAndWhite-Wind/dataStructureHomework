#include<iostream>

using namespace std;
const int N=1e5+10;

typedef struct linknode{
    int data;
    struct linknode *next;
}linknode,*liStack;// 定义链栈

void initStack(liStack &s){
    s=nullptr;
}

bool push(liStack &s,int x){
    linknode *p=new linknode;
    p->data=x;
    p->next=s;
    s=p;// 修改栈顶指针为p
    return true;
}

bool pop(liStack &s,int &x){
    if(!s) return false;
    x=s->data;
    auto p=s;
    s=s->next;
    delete p;
    return true;
}

bool getTop(liStack s,int &x){
    if(!s) return false;
    x=s->data;
    return true;
}

bool stackEmpty(liStack s){
    return s==nullptr;
}

int getLength(liStack s){
    int len=0;
    while(s){
        len++;
        s=s->next;
    }
    return len;
}

void stackDestroy(liStack &s){
    while(s){
        auto p=s;
        s=s->next;
        delete p;
    }
}

int main(){
    liStack s;
    initStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    cout<<getLength(s)<<endl;
    int x;
    while(!stackEmpty(s)){
        pop(s,x);
        cout<<x<<endl;
    }
    return 0;
}