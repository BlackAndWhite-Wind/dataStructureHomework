// 设I为入栈，O为出栈，判断给定的出栈序列是否合法

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

bool judge(string str){
    int cnt=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='I') cnt++;
        else cnt--;
        if(cnt<0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s; cin>>s;
    cout<<(judge(s)?"YES":"NO")<<endl;
    
    return 0;
}
