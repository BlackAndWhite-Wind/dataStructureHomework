#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

typedef struct {
    int data[N];
    int length;
} SqList;

void find_min_distance(SqList& A, SqList& B, SqList& C) {
    int sa = A.length, sb = B.length, sc = C.length;
    int i = 0, j = 0, k = 0;
    int dis;
    int d_min = INF;
    int i_min, j_min, k_min;
    while (i < sa && j < sb && k < sc) {
        dis = abs(A.data[i] - B.data[j]) + abs(B.data[j] - C.data[k]) + abs(C.data[k] - A.data[i]);
        if (dis < d_min) {
            d_min = dis;
            i_min = i;
            j_min = j;
            k_min = k;
        }
        if (A.data[i] == min({ A.data[i], B.data[j], C.data[k] }))
            i++;
        else if (B.data[j] == min({ A.data[i], B.data[j], C.data[k] }))
            j++;
        else
            k++;
    }
    cout << "Minimum Distance: " << d_min << endl;
    cout << "i: " << i_min << ", j: " << j_min << ", k: " << k_min << endl;
}

int main() {
    SqList A, B, C;
    int lena, lenb, lenc;
    cin >> lena >> lenb >> lenc;
    for (int i = 0; i < lena; i++)
        cin >> A.data[i];
    for (int i = 0; i < lenb; i++)
        cin >> B.data[i];
    for (int i = 0; i < lenc; i++)
        cin >> C.data[i];
    A.length = lena;
    B.length = lenb;
    C.length = lenc;
    find_min_distance(A, B, C);
    return 0;
}
