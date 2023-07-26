// 荷兰国旗问题

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N=1e5+10;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int le=0,ri=n-1,i=0;
        while(i<=ri){
            if(nums[i]==0){
                swap(nums[i],nums[le]);
                le++,i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[ri]);
                ri--;
            }
            else i++;
        }
    }
};
// 0-j-1: 0
// j-i-1: 1
// k+1-n-1: 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Solution s;
    vector<int> nums={2,0,2,1,1,0};
    s.sortColors(nums);
    for(auto i:nums) cout<<i<<" ";
    
    return 0;
}
