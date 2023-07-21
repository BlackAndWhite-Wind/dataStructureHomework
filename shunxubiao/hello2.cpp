#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{ // 定义静态分配顺序表
    int data[N];
    int length;
}SqList;

void initList(SqList &L){ 
    // 初始化顺序表
    for(int i=0;i<N;i++) L.data[i]=0;
    L.length=0;
}

bool listInsert(SqList &L,int i,int element){
    // 在顺序表L的第i个位置插入元素element
    if(i<=0 || i>L.length+1) return false;// 判断i的范围是否有效
    if(L.length>=N) return false;// 判断顺序表是否已满 
    for(int j=L.length;j>=i;j--) {
        // 将第i个位置及其后面的元素后移
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=element;
    L.length++;
    return true;
}

bool listDelete(SqList &L,int i,int element){
    // 删除顺序表L的第i个位置的元素
    if(i<=0 || i>L.length) return false;// 判断i的范围是否有效
    element=L.data[i];
    for(int j=i;j<L.length;j++) L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

int getElem(SqList &L,int i){
    // 获取顺序表L的第i个位置的元素
    if(i<=0 || i>L.length) return -1;// 判断i的范围是否有效
    return L.data[i-1];
}

int locateElem(SqList &L,int element){
    // 获取顺序表中所有元素值为element的位置
    for(int i=0;i<L.length;i++){
        if(L.data[i]==element) return i+1;
    }
    return -1;
}