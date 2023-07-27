#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N=1e5+10;

// 获取数字x的第d位数字
int getDigit(int x, int d) {
    int base = 1;
    for (int i = 0; i < d - 1; ++i) {
        base *= 10;
    }
    return (x / base) % 10;
}

// LSD基数排序
void radixSort(vector<int>& arr) {
    if (arr.empty())
        return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int digits = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        digits++;
    }

    vector<int> tmpArr(arr.size());
    vector<int> count(10, 0); // 数字0-9的计数数组

    for (int d = 1; d <= digits; ++d) {
        // 初始化计数数组
        fill(count.begin(), count.end(), 0);

        // 统计每个桶中的元素个数
        for (int i = 0; i < arr.size(); ++i) {
            int digit = getDigit(arr[i], d);
            count[digit]++;
        }

        // 计算每个数字在有序序列中的起始位置
        for (int i = 1; i < count.size(); ++i) {
            count[i] += count[i - 1];
        }

        // 将元素从原始数组arr放到临时数组tmpArr中，保持稳定性
        for (int i = arr.size() - 1; i >= 0; --i) {
            int digit = getDigit(arr[i], d);
            tmpArr[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // 将临时数组tmpArr的内容复制回原始数组arr
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = tmpArr[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}