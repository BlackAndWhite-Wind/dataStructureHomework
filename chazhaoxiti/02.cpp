// 设计一个算法，求出一个节点在给定的二叉排序树中的层次

#include <iostream>
#include <queue>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int count_level(BiTree T, int x) {
    if (!T) return -1;
    queue<BiTNode *> q;
    q.push(T);
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            BiTNode *node = q.front();
            q.pop();
            if (node->data == x) return level;
            if (node->lchild) q.push(node->lchild);
            if (node->rchild) q.push(node->rchild);
        }
        level++;
    }
    return -1;
}

int main() {
    // 构建一个示例的二叉排序树
    BiTNode n1 = {4, nullptr, nullptr};
    BiTNode n2 = {2, nullptr, nullptr};
    BiTNode n3 = {6, nullptr, nullptr};
    BiTNode n4 = {1, nullptr, nullptr};
    BiTNode n5 = {3, nullptr, nullptr};
    BiTNode n6 = {5, nullptr, nullptr};
    BiTNode n7 = {7, nullptr, nullptr};

    n1.lchild = &n2;
    n1.rchild = &n3;
    n2.lchild = &n4;
    n2.rchild = &n5;
    n3.lchild = &n6;
    n3.rchild = &n7;

    BiTree root = &n1;

    // 测试节点值为5的层次
    int nodeValue = 5;
    int level = count_level(root, nodeValue);
    cout << "num " << nodeValue << " level: " << level << endl;

    // 测试一个不存在的节点值
    int nonExistingNodeValue = 8;
    level = count_level(root, nonExistingNodeValue);
    cout << "num " << nonExistingNodeValue << " level: " << level << " not exist" << endl;

    return 0;
}
