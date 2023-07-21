// 线性表(a1,a2,a3,...an)中的元素递增有序且按顺序存储于计算机内。
// 要求设计一算法完成用最少时间在表中查找数值为x的元素，
// 若找到将其与后继元素位置相交换，
// 若找不到将其插入表中并使表中元素仍递增有序。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

int find(SqList &L,int x){
    int le=0,ri=L.length-1,mid;
    while(le<=ri){
        mid=le+ri>>1;
        if(L.data[mid]<x) le=mid+1;
        else if(L.data[mid]>x) ri=mid-1;
        else return mid;
    }
    return -1;
}

void insert(SqList &L,int x){
    int i;
    for(int i=L.length-1;i>=0;i--){
        if(L.data[i]>x) L.data[i+1]=L.data[i];
        else break;
    }
    L.data[i+1]=x;
    L.length++;
}

void swap(SqList &L,int i){
    int temp;
    temp=L.data[i];
    L.data[i]=L.data[i+1];
    L.data[i+1]=temp;
}

void find_insert_swap(SqList &L,int x){
    int i=find(L,x);
    if(i!=-1) swap(L,i);
    else insert(L,x); 
}

int main(){
    SqList L;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    cin>>x;
    find_insert_swap(L,x);
    for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";
    return 0;
}