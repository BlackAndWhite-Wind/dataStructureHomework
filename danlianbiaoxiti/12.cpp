// 单链表的去重
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10,M=2*N;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

int n,a[N];
int h[N],e[M],ne[M],idx;

void insert(int x){
    int k=(x%N+N)%N;
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

bool find(int x){
    int k=(x%N+N)%N;
    for(int i=h[k];~i;i=ne[i]){
        if(e[i]==x) return true;
    }
    return false;
}

LinkList init_list(int a[],int n){
    LinkList head = new Lnode;
    head->next=nullptr;
    LinkList tail=head;
    for(int i=0;i<n;i++){
        LinkList newNode = new Lnode;
        newNode->data=a[i];
        newNode->next=nullptr;
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}

LinkList delete_duplicates(LinkList head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    memset(h, -1, sizeof(h));
    LinkList current = head;
    LinkList prev = nullptr;

    while (current) {
        int x = current->data;
        int k = (x % N + N) % N;

        if (find(x)) {
            // 如果当前节点的值已经出现过，则删除该节点
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            // 如果当前节点的值未出现过，则添加到哈希表中，并继续遍历下一个节点
            insert(x);
            prev = current;
            current = current->next;
        }
    }

    return head;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    LinkList head = init_list(a, n);
    head = delete_duplicates(head);

    // 输出去重后的链表内容
    LinkList p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    // 释放链表的内存
    LinkList temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
