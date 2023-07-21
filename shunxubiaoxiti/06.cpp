// 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同

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

bool delete_same(SqList &L){
    if(L.length==0) return false;
    int i=1,j=1;
    while(i<L.length){
        if(L.data[i]!=L.data[i-1]){
            L.data[j]=L.data[i];
            j++;
        }
        i++;
    }
    L.length=j;
    return true;
}

int main(){
    SqList L;
    cin>>n;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    delete_same(L);
    for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";
    return 0;
}