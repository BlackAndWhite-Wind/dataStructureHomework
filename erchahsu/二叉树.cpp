// 二叉树的存储

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;
const int N=1e5+10;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        return left == nullptr ? right : (right == nullptr ?  left : root);
    }

    void preOrder(TreeNode* root) { // 前序遍历
        if(root == nullptr) return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode* root) { // 中序遍历
        if(root == nullptr) return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }

    void postOrder(TreeNode* root) { // 后序遍历
        if(root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

    void preOrderWithStack(TreeNode* root) { // 前序遍历非递归
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p != nullptr || !st.empty()) {
            while(p != nullptr) {
                cout << p->val << " ";
                st.push(p);
                p = p->left;
            }
            if(!st.empty()) {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
    }

    void inOrderWithStack(TreeNode* root) { // 中序遍历非递归
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p != nullptr || !st.empty()) {
            while(p != nullptr) {
                st.push(p);
                p = p->left;
            }
            if(!st.empty()) {
                p = st.top();
                cout << p->val << " ";
                st.pop();
                p = p->right;
            }
        }
    }

    void postOrderWithStack(TreeNode* root) { // 后序遍历非递归
        stack<TreeNode*> st;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while(p != nullptr || !st.empty()) {
            while(p != nullptr) {
                st.push(p);
                p = p->left;
            }
            if(!st.empty()) {
                p = st.top();
                if(p->right == nullptr || p->right == pre) {
                    cout << p->val << " ";
                    st.pop();
                    pre = p;
                    p = nullptr;
                } else {
                    p = p->right;
                }
            }
        }
    }

    void levelOrder(TreeNode* root) { // 层序遍历
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            cout << p->val << " ";
            if(p->left != nullptr) q.push(p->left);
            if(p->right != nullptr) q.push(p->right);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    
    return 0;
}
