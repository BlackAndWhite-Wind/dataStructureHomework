#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct node{ // 定义结点类型
    int val;// 结点的值
    struct node *next;// 结点的指针域
}LinkList;// 定义结点类型的别名

LinkList *init(int n){
    auto *head = new LinkList;// 申请一个头结点
    head->val = 1;// 头结点的值为1
    head->next = head;// 头结点的指针域指向自己
    auto p = head;// p指向头结点
    for(int i=2;i <= n;i++){ // 从2开始，依次插入到头结点后面
        auto *q = new LinkList;// 申请一个新结点
        q->val = i;// 新结点的值为i
        q->next = head;// 新结点的指针域指向头结点
        p->next = q;// 头结点的指针域指向新结点
        p = q;// p指向新结点
    }
    return head;// 返回头结点
}

void Josephus(LinkList *head,int n){
    auto p = head;// p指向头结点
    auto q = head;// q指向头结点
    while(p->next != p){ // 当链表中只剩下一个结点时，跳出循环
        for(int i=1;i < n;i++){// 从1开始，依次删除第n个结点
            q = p;// q指向p的前一个结点
            p = p->next;// p指向p的后一个结点
        }
        q->next = p->next;// q的指针域指向p的后一个结点
        cout << p->val << "->";// 输出p的值
        delete p;// 释放p所指向的结点
        p = q->next;// p指向q的后一个结点
    }
    cout << p->val << endl;// 输出最后一个结点的值
    delete p;// 释放p所指向的结点
}

int main(){
    int n,m;// n为结点个数，m为删除第m个结点    
    cin>>n>>m;// 输入n和m
    auto *head = init(n);// 初始化链表
    Josephus(head,m);// 求解约瑟夫环问题
    return 0;
}