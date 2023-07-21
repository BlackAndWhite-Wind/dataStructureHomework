//对长度为n的顺序表L，编写一个时间复杂度为 O(n)、空间复杂度为 O(1)的算法。
//该算法删除线性表中所有值为 x的数据元素。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

int n,x;

void delete_x_element(SqList &L,int &x){
    int cnt=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[cnt++]=L.data[i];
        }
    }
    L.length=cnt;
}

int main(){
    SqList L;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    delete_x_element(L,x);
    for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";
    return 0;
}