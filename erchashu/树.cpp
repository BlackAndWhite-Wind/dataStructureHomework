// 树的双亲表示法的存储结构

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data, parent;
}PTNode;

typedef struct{
    PTNode nodes[N];
    int n;
}PTree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
