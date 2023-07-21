// 给定两个单链表，编写算法找出两个链表的公共结点。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

int n, m, a[N];

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

LinkList get_common_node(LinkList &L1, LinkList &L2) {
	LinkList p = L1->next, q = L2->next;
	while (p && q) {
		if (p->data == q->data) return p;
		else if (p->data < q->data) p = p->next;
		else q = q->next;
	}
	return nullptr;
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
	LinkList L1 = init_list(a, n);
	cin >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	LinkList L2 = init_list(a, n);

	LinkList common_node = get_common_node(L1, L2);
	if (common_node) {
		cout << common_node->data << " ";
		print_list(common_node);
	} else cout << "NULL" << endl;
	return 0;
}
