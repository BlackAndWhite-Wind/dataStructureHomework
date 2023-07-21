// 设计一个高效的算法，将顺序表所有元素逆置，要求算法的空间复杂度为O(1)。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

int n;

void reverse_list(SqList &L){
    int temp;
    for(int i=0;i<L.length/2;i++){
        temp=L.data[i];
        L.data[i]=L.data[L.length-i-1];
        L.data[L.length-i-1]=temp;
    }
}

int main(){
    SqList L;
    cin>>n;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    reverse_list(L);
    for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";
    return 0;
}