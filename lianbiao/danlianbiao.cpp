// 单链表的定义和代码实现

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*LinkList;

// 不带头结点的单链表
bool init_list_without_head(LinkList &L){
	L=nullptr;
	return true;
}

// 带头结点的单链表
bool init_list_with_head(LinkList &L){
	L=(Lnode*)malloc(sizeof(Lnode));
	if(L==nullptr) return false;
	L->next=nullptr;
	return true;
}

bool list_insert_with_head(LinkList &L,int i,int e){
	// 带头节点的单链表插入，i为插入位置，e为插入元素
	if(i<=0) return false;
	Lnode *p;
	p=L;
	int j=0;
	while(p && j<i-1){ // 找到第i-1个节点
		p=p->next;
		j++;
	}
	if(!p) return false;
	Lnode *s=(Lnode*)malloc(sizeof(Lnode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

bool list_insert_without_head(LinkList &L,int i,int e){
	// 不带头节点的单链表插入，i为插入位置，e为插入元素
	if(i<=0) return false;
	if(i==1){
		Lnode *s=(Lnode*)malloc(sizeof(Lnode));
		s->data=e;
		s->next=L;
		L=s;
		return true;
	}
	Lnode *p;
	p=L;
	int j=0;
	while(p && j<i-1){ // 找到第i-1个节点
		p=p->next;
		j++;
	}
	if(!p) return false;
	Lnode *s=(Lnode*)malloc(sizeof(Lnode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

bool insert_next_node(Lnode *p,int e){
	// 在p节点之后插入元素e
	if(!p) return false;
	Lnode *s=(Lnode*)malloc(sizeof(Lnode));
	if(!s) return false;// 内存分配失败
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

bool insert_before_node(Lnode *p,int e){
	// 在p节点之前插入元素e O(1)
	// 相当于在按值查找的时候将e放在了p->data的前面一个，看起来像是实现了前插。
	if(!p) return false;
	Lnode *s=(Lnode*)malloc(sizeof(Lnode));
	if(!s) return false;// 内存分配失败  
	s->next=p->next;// 将p节点之后的节点接到s节点之后
	p->next=s;// 将s节点接到p节点之后
	s->data=p->data;// 将p节点的数据复制到s节点
	p->data=e;// 将e赋值给p节点
	return true;
}

bool list_delete_with_head(LinkList &L,int i,int &e){
	// 带头节点的单链表删除，i为删除位置，e为删除元素
	if(i<=0) return false;
	Lnode *p;
	p=L;
	int j=0;
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	if(!p || !p->next) return false;
	Lnode *q=p->next;
	q->data=e;
	p->next=q->next;
	free(q);
	return true;
}

bool delete_node(Lnode *p){
	if(!p) return false;
	Lnode *q=p->next;
	p->data=q->next->data;
	p->next=q->next;
	free(q);	
	return true;
}

// 单链表的按位查找
Lnode *get_element(LinkList L,int i){
	if(i<0) return nullptr;
	Lnode *p=L;
	int j=0;
	while(p && j<i){
		p=p->next;
		j++;
	}
	return p;
}

// 单链表的按值查找
Lnode *locate_element(LinkList L,int e){
	Lnode *p=L->next;
	while(p && p->data!=e) p=p->next;
	return p;
}

int get_length(LinkList L){
	Lnode *p=L;
	int cnt=0;
	while(p->next){
		p=p->next;
		cnt++;
	}
	return cnt;
}

// 尾插法建立单链表
LinkList tail_insert(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(Lnode));// 创建头结点
	Lnode *s,*r=L;// r始终指向尾结点，开始时指向头结点
	cin>>x;
	while(x!=9999){
		s=(Lnode*)malloc(sizeof(Lnode));
		s->data=x;
		r->next=s;
		r=s;
		cin>>x;
	}
	r->next=nullptr;
	return L;
}

// 头插法建立单链表
LinkList head_insert(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(Lnode));// 创建头结点
	L->next=nullptr;
	Lnode *s;
	cin>>x;
	while(x!=9999){
		s=(Lnode*)malloc(sizeof(Lnode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		cin>>x;
	}
	return L;
}