// 写出二叉树的后序遍历的非递归算法

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;
const int N=1e5+10;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> postOrder(TreeNode *root){
    stack<TreeNode*> st;
    vector<int> res;
    TreeNode *prev=nullptr;
    while(root || !st.empty()){
        if(root){
            st.push(root);
            root=root->right;
        }
        else{
            auto temp=st.top();
            if(temp->left && temp->left!=prev){
                root=temp->left;
            }
            else{
                res.push_back(temp->val);
                prev=temp;
                st.pop();
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
