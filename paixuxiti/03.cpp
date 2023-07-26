// 找出数组中第k小元素

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=1e5+10;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIdx = partition(arr, low, high);
        if (pivotIdx - low == k - 1)
            return arr[pivotIdx];
        else if (pivotIdx - low > k - 1)
            return quickSelect(arr, low, pivotIdx - 1, k);
        else
            return quickSelect(arr, pivotIdx + 1, high, k - pivotIdx + low - 1);
    }
    return -1; // k 超出数组大小范围
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    int kthSmallest = quickSelect(arr, 0, n - 1, k);
    if (kthSmallest != -1)
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    else
        cout << "Invalid value of k." << endl;

    return 0;
}
