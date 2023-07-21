// 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)。

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

LinkList list_reverse(LinkList &L) {
	Lnode *pre, *p = L->next, *q = p->next;
	p->next = nullptr;
	while (q) {
		pre = p;
		p = q;
		q = q->next;
		p->next = pre;
	}
	L->next = p;
	return L;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	LinkList L = init_list(a, n);
	list_reverse(L);
	Lnode *p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}
