// 栈的括号匹配

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

string str;
stack<int> S;
unordered_map<char,char> mp={
    {')','('},
    {']','['},
    {'}','{'}
};

bool is_matched(string s){
    for(auto ch:s){
        if(mp.count(ch)){
            if(S.empty()||S.top()!=mp[ch]){
                return false;
            }
            else S.pop();
        }
        else S.push(ch);
    }
    return S.empty();
}

int main(){
    cin>>str;
    cout<<is_matched(str)<<endl;
    return 0;
}