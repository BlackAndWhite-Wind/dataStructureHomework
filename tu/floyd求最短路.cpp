#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 210,inf=0x3f3f3f;

int n,m,k,d[N][N];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

void init(){
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=inf;
        }
    }
}


int main()
{
    cin>>n>>m>>k;
    init();
    while(m--)
    {
        int a,b,c;  cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
    }
    
    floyd();
    while(k--)
    {
        int x,y; cin>>x>>y;
        
        int t=d[x][y];
        if (t > inf / 2) puts("impossible");
        else printf("%d\n", t);
    }
    
    return 0;
}
