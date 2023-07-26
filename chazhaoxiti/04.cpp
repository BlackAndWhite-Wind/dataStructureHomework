// 求出二叉排序树中最大和最小的节点

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

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
        vector<int> get_min_and_max(TreeNode *root){
            vector<int> res;
            if(!root) return res;
            auto a=root,b=root;
            while(a->left) a=a->left;
            res.push_back(a->val);
            while(b->right) b=b->right;
            res.push_back(b->val);
            return res;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // 构建一个示例的二叉排序树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<int> minAndMax = solution.get_min_and_max(root);

    cout << "Minimum node value: " << minAndMax[0] << endl;
    cout << "Maximum node value: " << minAndMax[1] << endl;

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
