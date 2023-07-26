// 折半查找的递归写法

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

int binary_search(int q[], int l, int r, int x) {
    if (l > r) return -1;
    int mid = (l + r) >> 1;
    if (q[mid] == x) return mid;
    else if (q[mid] > x) return binary_search(q, l, mid - 1, x);
    else return binary_search(q, mid + 1, r, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
