// 顺序表的实现（静态&动态）
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;
const int N=1e5+10;

typedef struct { // 顺序表的定义（静态分配）
    int a[N];
    int length;
}SqList;

typedef struct { // 顺序表的定义（动态分配）
    int *a;
    int length;
    int maxSize;
}SqList2;

void initList(SqList &L){ // 初始化顺序表
    for(int i=0;i<N;i++) L.a[i]=0;
    L.length=0;
}

void initList(SqList2 &L){
    L.a=(int *)malloc(N*sizeof(int));
    L.length=0;
    L.maxSize=N;
}

void increateSize(SqList2 &L,int len){
    int *p=L.a;
    L.a=(int *)malloc((L.maxSize+len)*sizeof(int));
    for(int i=0;i<L.length;i++) L.a[i]=p[i];
    L.maxSize+=len;
    free(p);
}

int main(){
    SqList L;
    initList(L);
    for(int i=0;i<N;i++) printf("%d ",L.a[i]);
    return 0;
}