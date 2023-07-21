// 已知在一维数组A[m+n]中依次存放两个线性表
// (a1,a2,...,am)和(b1,b2,...,bn)。
//试编写一个函数，将数组中两个顺序表的位置互换，
// 即将(b1,b2,...,bn)放在(a1,a2,...,am)的前面。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

void reverse(SqList &A, int left, int right){
    int temp;
    while(left<right){
        temp=A.data[left];
        A.data[left]=A.data[right];
        A.data[right]=temp;       
        left++;
        right--;
    }
}

void reverse_list_a_b(SqList &A, int m, int n){
    reverse(A,0,m+n-1);
    reverse(A,0,n-1);
    reverse(A,n,m+n-1);
}

int main(){
    SqList A;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n+m;i++) cin>>A.data[i];
    A.length=n+m;
    reverse_list_a_b(A,n,m);
    for(int i=0;i<A.length;i++) cout<<A.data[i]<<" ";
    return 0;
}
