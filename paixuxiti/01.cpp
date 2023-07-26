//编写双向冒泡排序算法，在正反两个方向交替进行扫描
//第一趟将关键字最大的记录放在最后位置，第二趟将关键字最小的记录放在最前位置

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

void bubble_sort(int a[],int n){
    int le=0,ri=n-1;
    bool flag=true;
    while(flag && le<ri){
        flag=false;
        for(int i=le;i<ri;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                flag=true;
            }
        }
        ri--;
        for(int i=ri;i>le;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                flag=true;
            }
        }
        le++;
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

    bubble_sort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

