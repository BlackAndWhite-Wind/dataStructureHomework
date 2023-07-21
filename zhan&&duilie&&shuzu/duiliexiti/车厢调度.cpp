// 火车调度站的入口处有n节硬座和软座车厢，分别有H和S表示，等待调度
// 试编写算法，将这n节车厢调整为有序的出站次序，
// 使得所有的软座车箱被调整到硬座车厢之前

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

stack<char> S;

void train_arrange(string s){
    int i=0;
    while(i<s.length()){
        if(s[i]=='S') cout<<s[i];
        else S.push(s[i]);
        i++;
    }
    while(!S.empty()){
        cout<<S.top();
        S.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    train_arrange(s);

    return 0;
}
