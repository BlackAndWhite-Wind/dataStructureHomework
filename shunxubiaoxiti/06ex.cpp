// 散列表实现无序数组的去重

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10,M=2*N;

int n;
int h[N],e[M],ne[M],idx;

typedef struct{
    int data[N];
    int length;
}SqList;

void insert(int x){
    int k=(x%N+N)%N;
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}

bool find(int x){
    int k=(x%N+N)%N;
    for(int i=h[k];~i;i=ne[i]){
        if(e[i]==x) return true;
    }
    return false;
}

SqList remove_duplicate(SqList &L){
    memset(h,-1,sizeof h);
    idx=0;
    SqList res;
    for(int i=0;i<L.length;i++){
        if(!find(L.data[i])){
            insert(L.data[i]);
            res.data[res.length]=L.data[i];
            res.length++;
        }
    }
    return res;
}

int main(){
    SqList L;
    cin>>n;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    SqList res=remove_duplicate(L);
    cout<<res.length<<endl;
    for(int i=0;i<res.length;i++) cout<<res.data[i]<<" ";
    return 0;
}