// 已知由n（n≥2）个正整数构成的集合A={ak}（0≤k<n）
// 将其划分为两个不相交的子集A1和A2，元素个数分别是n1和n2， A1和A2中元素之和分别为S1和S2。
// 设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

int n,a[N];

int partition(int a[],int le,int ri){
    int temp=a[le];
    while(le<ri){
        while(le<ri && a[ri]>=temp) ri--;
        a[le]=a[ri];
        while(le<ri && a[le]<=temp) le++;
        a[ri]=a[le];
    }
    a[le]=temp;
    return le;
}

void devide(int a[],int n){
    int le=0,ri=n-1;
    while(le<ri){
        int mid=partition(a,le,ri);
        if(mid==n/2) break;
        else if(mid<n/2) le=mid+1;
        else ri=mid-1;
    }
}

void print(int a[],int le,int ri){
    for(int i=le;i<=ri;i++) cout<<a[i]<<" ";
}

int count_sum(int a[],int le,int ri){
    int sum=0;
    for(int i=le;i<=ri;i++) sum+=a[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    devide(a, n);

    int mid = n / 2;
    cout << "Subset A1: ";
    print(a, 0, mid - 1);
    cout << "\nSubset A2: ";
    print(a, mid, n - 1);

    int sum1 = count_sum(a, 0, mid - 1);
    int sum2 = count_sum(a, mid , n - 1);

    cout << "\nSum of Subset A1: " << sum1 << "\nSum of Subset A2: " << sum2 << endl;

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度：O(1)