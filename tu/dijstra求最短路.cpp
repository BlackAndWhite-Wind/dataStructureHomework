#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=510;

int n,m;
int path[N][N],dist[N];
bool vis[N];

int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] &&(t==-1 || dist[t]>dist[j])){
                t=j;
            }
        }
        vis[t]=true;
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],dist[t]+path[t][j]);
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin>>n>>m;
    memset(path,0x3f,sizeof(path));
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        path[x][y]=min(path[x][y],z);
    }
    cout<<dijkstra()<<endl;
    return 0;
}