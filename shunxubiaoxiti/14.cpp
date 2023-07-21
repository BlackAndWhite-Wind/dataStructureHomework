// 定义三元组(a,b,c)的距离D=|a-b|+|b-c|+|c-a|，求距离最大的三元组。

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

typedef struct {
	int data[N];
	int length;
} SqList;

int lena, lenb, lenc;

int find_min_distance(SqList& A, SqList& B, SqList& C, int &min_i, int &min_j, int &min_k) {
	int sa = A.length, sb = B.length, sc = C.length;
	int i = 0, j = 0, k = 0;
	int dis;
	int d_min = INF;
	min_i = 0, min_j = 0, min_k = 0;
	while (i < sa && j < sb && k < sc) {
		dis = abs(A.data[i] - B.data[j]) + abs(B.data[j] - C.data[k]) + abs(C.data[k] - A.data[i]);
		if (dis < d_min) {
			d_min = dis;
			min_i = i;
			min_j = j;
			min_k = k;
		}
		if (A.data[i] == min({ A.data[i], B.data[j], C.data[k] }))
			i++;
		else if (B.data[j] == min({ A.data[i], B.data[j], C.data[k] }))
			j++;
		else
			k++;
	}
	return d_min;
}

int main() {
	SqList A, B, C;
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
	int min_i,min_j,min_k;
	int res=find_min_distance(A,B,C,min_i,min_j,min_k);
	cout<<"min distance: "<<res<<endl;
	cout<<"(i,j,k): "<<min_i<<" "<<min_j<<" "<<min_k<<endl;
	cout<<"(a,b,c): "<<A.data[min_i]<<" "<<B.data[min_j]<<" "<<C.data[min_k]<<endl;
	return 0;
}
