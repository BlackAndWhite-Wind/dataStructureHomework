// 设在一个带表头结点的单链表中所有元素结点的数据值无序。
// 试编写一个函数，删除表中所有介于给定的两个值
//（作为函数参数给出）之间的元素的元素（若存在）。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

int n, le, ri, a[N];

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

void range_delete(LinkList &L, int le, int ri) {
	Lnode *p = L, *q = L->next;  
	while (q) {
		if (q->data < ri && q->data > le) {
            // 如果q的值在范围
			p->next = q->next;// 删除q
			free(q);// 释放q
			q = p->next;// q指向下一个
		} else {
			p = q;// p指向q
			q = q->next;// q指向下一个
		}
	}
}

void print_list(LinkList head) {
	LinkList p = head->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	cin >> n >> le >> ri;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
	LinkList L = init_list(a, n);
	range_delete(L, le, ri);
	print_list(L);
	return 0;
}
