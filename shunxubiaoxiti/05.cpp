// 从顺序表中删除其值在s与t之间(包含s和t,要求s<t)的所有元素。
// 如果s或t不合理或者顺序表为空则显示出错信息并退出运行.

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

bool delete_s_t(SqList &L,int s,int t){
    if(s>=t || L.length==0) return false;
    int cnt=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]<=t && L.data[i]>=s) cnt++;
        else L.data[i-cnt]=L.data[i];
    }
    L.length-=cnt;
    return true;
}

int main(){
    SqList L;
    cin>>n>>s>>t;
    for(int i=0;i<L.length;i++) cin>>L.data[i];
    L.length=n;
    if(delete_s_t(L,s,t)){
        for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";
    }
    else cout<<"error"<<endl;
    return 0;
}