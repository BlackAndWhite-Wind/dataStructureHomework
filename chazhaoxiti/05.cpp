// 设计一个算法，从大到小输出二叉排序树中所有值不小于k的关键字。

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

class Solution{
    public:
        void print(TreeNode *root,int k){
            if(!root) return;
            if(root->right) print(root->right,k);
            if(root->val>=k) cout<<root->val<<" ";
            if(root->left) (root->left,k);
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 构建一个示例的二叉排序树
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    int k = 5;
    Solution solution;
    cout << "Values in the binary search tree not less than " << k << ": ";
    solution.print(root, k);
    cout << endl;

    // 清理二叉树，释放内存
    // 注意：在实际应用中，需要根据具体情况设计二叉树节点的释放逻辑
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

