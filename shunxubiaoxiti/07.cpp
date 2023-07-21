// 将两个有序顺序表合并成一个新的顺序表，并由函数返回结果顺序表

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

int n,m;

SqList merge_list(SqList &A, SqList &B){
    SqList C;
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length){
        if(A.data[i]<=B.data[j]){
            C.data[k++]=A.data[i++];
        }else{
            C.data[k++]=B.data[j++];
        }
    }
    while(i<A.length){
        C.data[k++]=A.data[i++];
    }
    while(j<B.length){
        C.data[k++]=B.data[j++];
    }
    C.length=k;
    return C;
}

int main(){
    SqList A,B,C;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>A.data[i];
    A.length=n;
    for(int i=0;i<m;i++) cin>>B.data[i];
    B.length=m;
    C=merge_list(A,B);
    for(int i=0;i<C.length;i++) cout<<C.data[i]<<" ";
    return 0;
}
