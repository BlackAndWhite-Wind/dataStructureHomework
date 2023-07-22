// 实现二叉树的从下往上，从右往左的层次遍历算法

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;
const int N=1e5+10;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void traversal(TreeNode *root){
    queue<TreeNode*> q;
    stack<TreeNode*> st;
    q.push(root);
    while(!q.empty()){
        auto temp=q.front(); q.pop();
        st.push(temp);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    while(!st.empty()){
        auto t=st.top(); st.pop();
        cout<<t->val<<" ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(7);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(4);
    traversal(root);
    
    return 0;
}