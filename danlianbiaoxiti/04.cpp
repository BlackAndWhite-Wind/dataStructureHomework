// 试编写在带头节点的单链表L中删除一个最小值节点的高效算法
// (假设最小值节点是唯一的)。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

typedef struct Lnode {
	int data;
	struct Lnode *next;
} Lnode, *LinkList;

int n, a[N];

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

LinkList delete_min_element(LinkList &L) {
	Lnode *pre = L, *p = pre->next; //pre指向p的前驱
	Lnode *min_pre = pre, *min_p = p; //min_pre指向最小值节点的前驱
	while (p) {
		if (p->data < min_p->data) {
			min_p = p;
			min_pre = pre;
		}
		pre = p;
		p = p->next;
	}
	min_pre->next = min_p->next;
	free(min_p);
	return L;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	LinkList L = init_list(a, n);
	L = delete_min_element(L);
	Lnode *p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}
