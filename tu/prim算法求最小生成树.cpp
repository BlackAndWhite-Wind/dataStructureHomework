#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=510,INF = 0x3f3f3f3f;

int path[N][N],dist[N],vis[N],pre[N];
int n,m;

int prim(){
    memset(dist,0x3f,sizeof(dist));
    int res=0;
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && (t==-1 || dist[j]<dist[t])) t=j;
        }
        if(i && dist[t]==INF) return INF;
        if(i) res+=dist[t];
        
        vis[t]=true;
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],path[t][j]);
    }
    return res;
}

int main()
{
    memset(path,0x3f,sizeof(path));
    cin>>n>>m;
    while(m--)
    {
        int a,b,w;  cin>>a>>b>>w;
        path[a][b]=path[b][a]=min(path[a][b],w);
    }
    
    int t=prim();
    if(t==INF) puts("impossible");
    else cout<<t<<endl;
    
    return 0;
}

