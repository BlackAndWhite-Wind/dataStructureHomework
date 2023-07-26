// 判断二叉树是不是平衡二叉树

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
        int get_height(TreeNode *root) {
            if(root==NULL) return 0;
            return max(get_height(root->left),get_height(root->right))+1;
        }

        bool is_balanced(TreeNode *root){
            if(root==NULL) return true;
            int left_height=get_height(root->left);
            int right_height=get_height(root->right);
            int sub_height=left_height-right_height;
            return abs(sub_height)<=1 && is_balanced(root->left) && is_balanced(root->right);
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // 构建一个示例的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    bool isBalanced = solution.is_balanced(root);
    
    if (isBalanced) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    // 清理二叉树，释放内存
    // 注意：在实际应用中，需要根据具体情况设计二叉树节点的释放逻辑
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
