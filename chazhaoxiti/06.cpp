// 编写一个递归算法，在一棵有n个节点，随机建立的二叉排序树中查找第k小元素,1<=k<=n,并返回该元素的指针。
// 要求算法的平均时间复杂度为O(logn)。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    TreeNode* findKthSmallest(TreeNode* root, int k) {
        if (!root) return NULL;

        int left_count = countNodes(root->left);

        if (left_count == k - 1) {
            return root; // 找到第k小元素，返回指针
        } else if (left_count >= k) {
            return findKthSmallest(root->left, k); // 在左子树中继续查找第k小元素
        } else {
            return findKthSmallest(root->right, k - left_count - 1); // 在右子树中查找第(k-left_count-1)小元素
        }
    }
};

int main() {
    // 构建一个示例的二叉排序树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution solution;
    int k = 3;
    TreeNode* kthSmallest = solution.findKthSmallest(root, k);
    if (kthSmallest) {
        cout << "The " << k << "th smallest element is: " << kthSmallest->val << endl;
    } else {
        cout << "The " << k << "th smallest element does not exist in the binary search tree." << endl;
    }

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
