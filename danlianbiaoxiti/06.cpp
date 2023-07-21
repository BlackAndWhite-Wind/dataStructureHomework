// 有一个带头结点的单链表L，设计一个算法使其元素递增有序排列。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;    
const int N = 1e5 + 10;

int n, a[N];

typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

LinkList init_list(int a[], int n) {
    LinkList head = new Lnode;
    head->next = nullptr;

    LinkList tail = head;
    for (int i = 0; i < n; i++) {
        LinkList newNode = new Lnode;
        newNode->data = a[i];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

LinkList insert_sort(LinkList head){
    if(!head || !head->next) return head;

    LinkList sorted_head = new Lnode;
    sorted_head->next = nullptr;

    LinkList p = head->next;
    while(p){
        LinkList q = p;
        p = p->next;

        LinkList t = sorted_head;
        while(t->next && t->next->data < q->data) t=t->next;

        q->next = t->next;
        t->next = q;
    }
    return sorted_head;
}

void print_list(LinkList head) {
    LinkList p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    LinkList head = init_list(a, n);
    LinkList sorted_head = insert_sort(head);
    print_list(sorted_head);
    return 0;
}