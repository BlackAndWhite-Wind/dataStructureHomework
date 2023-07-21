//从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素。
//若s或t不合理或顺序表为空，则显示出错信息并退出运行

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

int n,s,t;

bool delete_element_between_s_t(SqList &L,int s,int t){
    if(s>=t || L.length==0) return false;
    int i,j;
    for(i=0;i<L.length && L.data[i]<s;i++){
        if(i>=L.length) return false;
    }
    for(j=i;j<L.length && L.data[j]<=t;j++);
    for(;j<L.length;i++,j++) L.data[i]=L.data[j];
    L.length=i;
    return true;    
}

int main(){
    SqList L;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    if(delete_element_between_s_t(L,s,t)){
        for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";\
    }
    else cout<<"error"<<endl;
    return 0;
}