#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;

int ne[N];

vector<int> kmp(string s, string p) { // kmp求所有匹配位置
    // p是模式串，s是主串
    int n = s.size(), m = p.size();
    s = ' ' + s, p = ' ' + p; // 为了方便计算，下标从1开始
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    vector<int> matches; // 用于存储所有匹配的位置
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
            matches.push_back(i - j); // 将匹配位置添加到数组中
            j = ne[j];
        }
    }
    return matches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s >> p;
    vector<int> matches = kmp(s, p);

    if (matches.empty()) {
        cout << -1 << endl;
    } else {
        for (int i : matches) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
