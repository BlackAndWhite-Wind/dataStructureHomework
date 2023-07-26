#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

int seq_search(int a[],int n,int x) {
    for(int i=0;i<n;i++) {
        if(a[i]==x) return i;
    }
    return -1;
}

int binary_search(int a[],int n,int x) {
    int l=0,r=n-1;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(a[mid]==x) return mid;
        else if(a[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
