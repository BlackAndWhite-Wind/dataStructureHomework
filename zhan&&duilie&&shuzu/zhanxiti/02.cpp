// 判断链表是否中心对称

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
const int N = 1e5 + 10;

typedef struct Lnode {
    char data; 
    struct Lnode* next;
} Lnode, * LinkList;

// 判断是否对称
bool judge(LinkList L, int n) {
    stack<char> s; 
    Lnode* p = L->next;
    for (int i = 0; i < n / 2; i++) {
        s.push(p->data);
        p = p->next;
    }
    if (n % 2 == 1) p = p->next;
    while (p) {
        if (p->data == s.top()) {
            s.pop();
            p = p->next;
        }
        else return false;
    }
    return true;
}

// 初始化单链表
void init_linklist(LinkList& L) {
    L = new Lnode;
    L->next = NULL;
}

// 向单链表中添加元素
void add_node(LinkList& L, char val) { 
    Lnode* newNode = new Lnode;
    newNode->data = val;
    newNode->next = L->next;
    L->next = newNode;
}

// 释放单链表的内存
void destroy_linklist(LinkList& L) {
    Lnode* p = L;
    while (p) {
        Lnode* temp = p;
        p = p->next;
        delete temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    char val;
    LinkList L;
    init_linklist(L);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        add_node(L, val);
    }

    cout << "The linked list is " << (judge(L, n) 
    ? "centrally symmetric." 
    : "NOT centrally symmetric.") << endl;


    destroy_linklist(L);

    return 0;
}
