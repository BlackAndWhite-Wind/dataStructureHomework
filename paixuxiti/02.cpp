// 已知线性表按顺序存储。设计将所有的奇数移动到所有偶数前面的算法。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

void move_element(int a[],int n){
    int le=0,ri=n-1;
    while(le<ri){
        while(le<ri && a[le]%2==1) le++;
        while(le<ri && a[ri]%2==0) ri--;
        if(le<ri) swap(a[le],a[ri]);
        le++,ri--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int a[N];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    move_element(a, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
