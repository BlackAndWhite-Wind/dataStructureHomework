#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=100010,M=200010,INF=0x3f3f3f;

int n,m;
int p[N];

struct Edge{
    int a,b,w;
    bool operator < (const Edge &W)const{
        return w<W.w;
    }
}edge[M];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int kruskal(){
    sort(edge,edge+m);
    for(int i=1;i<=n;i++) p[i]=i;
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        a=find(a),b=find(b);
        if(a!=b){
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return INF;
    return res;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge[i]={a,b,w};
    }
    int t=kruskal();
    if(t==INF) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}