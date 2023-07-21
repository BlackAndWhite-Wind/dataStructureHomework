#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;
const int N=1e5+10;

stack<int> num;
stack<char> op;
unordered_map<char,int> pr{{'+',1},{'-',1},{'*',2},{'/',2}};

void eval(){
    int a=num.top(); num.pop();
    int b=num.top(); num.pop();
    char c=op.top(); op.pop();
    int res;
    if(c=='+') res=b+a;
    else if(c=='-') res=b-a;
    else if(c=='*') res=b*a;
    else res=b/a;
    num.push(res);
}


int calculate(string s){
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(isdigit(c)){
            int x=0,j=i;
            while(j<s.size() && isdigit(s[j])){
                x=x*10+s[j]-'0';
                j++;
            }
            i=j-1;
            num.push(x);
        }
        else if(c=='(') op.push(c);
        else if(c==')'){
            while(op.top()!='(') eval();
            op.pop();
        }
        else {
            while(op.size() && op.top()!='(' && pr[op.top()]>=pr[c]) eval();
            op.push(c);
        }
    }
    while(op.size()) eval();
    return num.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s; cin>>s;
    cout<<calculate(s)<<endl;
    
    return 0;
}

