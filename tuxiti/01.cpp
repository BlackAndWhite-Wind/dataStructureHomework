// 判断一个无向图G是否为一棵树
#include <iostream>
#include <vector>

using namespace std;

// 使用DFS遍历图
bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int parent) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(graph, visited, neighbor, node)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // 存在环
        }
    }
    return false;
}

// 判断图是否为树
bool isTree(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    // 遍历图，从每个节点开始DFS，如果存在环，则不是树
    if (dfs(graph, visited, 0, -1)) {
        return false;
    }

    // 判断是否存在孤立的部分
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m; // n为节点数，m为边数
    cin >> n >> m;
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // 无向图需要双向添加边
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isTree(graph)) {
        cout << "y" << endl;
    } else {
        cout << "n" << endl;
    }

    return 0;
}

