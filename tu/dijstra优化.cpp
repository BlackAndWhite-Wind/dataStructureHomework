#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10,M=N;

int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        int distance=t.first;
        int ver=t.second;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}


int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--){
        int x,y,z; cin>>x>>y>>z;
        add(x,y,z);
    }
    cout<<dijkstra()<<endl;
}

