// 给定一棵二叉树，判断是否为二叉搜索树
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return true;
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode *root, long int min, long int max) {
        if(!root) return true;
        
        return root->val > min && root->val < max && isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
