// 找出数组中有一个元素出现的次数超过了数组长度的一半，求出该元素

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

int find(int a[], int n) {
    int cnt=0, res;
    for(int i=0;i<n;i++){
        if(cnt==0){
            res=a[i];
            cnt++;
        }
        else{
            if(a[i]==res) cnt++;
            else cnt--;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a[]={1,2,3,2,2,2,5,4,2};
    cout<<find(a, 9)<<endl;
    
    return 0;
}
