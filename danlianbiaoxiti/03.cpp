// 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个节点的值。

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;
const int N = 1e5 + 10;

typedef struct Lnode {
	int data;
	struct Lnode *next;
} Lnode, *LinkList;

int n, a[N];

void reverse_print(LinkList L) {
	stack<int> st;;
	Lnode *p = L;
	while (p) {
		st.push(p->data);
		p = p->next;
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

LinkList init_list(int a[], int n) {
	// 创建头节点
	LinkList head = new Lnode;
	head->next = nullptr;

	// 尾插法建立链表
	LinkList tail = head;
	for (int i = 0; i < n; i++) {
		LinkList newNode = new Lnode;
		newNode->data = a[i];
		newNode->next = nullptr;

		tail->next = newNode;
		tail = tail->next;
	}

	return head;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	LinkList L = init_list(a, n);
	reverse_print(L->next);
	return 0;
}
