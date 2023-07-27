#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

// 交换排序
// 1. 冒泡排序 
void bubble_sort(int a[],int n){
    bool flag;
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                flag=true;
            }
        }
    }
    if(!flag) return;
}

// 2. 快速排序
void quick_sort(int a[],int l,int r){
    if(l>=r) return;
    int i=l-1,j=r+1,x=a[l+r>>1];
    while(i<j){
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}

// 选择排序
// 1. 简单选择排序
void select_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int _min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[_min]) _min=j;
        }
        if(_min!=i) swap(a[i],a[_min]);// 一共移动3次元素
    }
}

// 2. 堆排序（这里以大根堆为例子）
void build_max_heap(int a[],int len){
    for(int i=len/2;i>0;i--) down(a,i,len);// 从i=[len/2]-1，反复调整堆
}

void down(int a[],int k,int len){
    a[0]=a[k];
    for(int i=2*k;i<=len;i*=2){
        if(i<len && a[i]<a[i+1]) i++;
        if(a[0]>=a[i]) break;
        else{
            a[k]=a[i];
            k=i;
        }
    }
    a[k]=a[0];
}

void heap_sort(int a[],int n){
    build_max_heap(a,n);
    for(int i=n;i>1;i--){
        swap(a[1],a[i]);
        down(a,1,i-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}

