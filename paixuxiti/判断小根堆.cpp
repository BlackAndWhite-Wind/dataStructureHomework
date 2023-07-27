#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N=1e5+10;

bool isMinHeap(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; ++i) {
        // Check if the left child is less than the current node
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
            return false;

        // Check if the right child is less than the current node
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Example usage
    std::vector<int> heap = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> not_heap = {3, 1, 2, 5, 4};

    if (isMinHeap(heap)) {
        std::cout << "The given sequence is a min heap." << std::endl;
    } else {
        std::cout << "The given sequence is NOT a min heap." << std::endl;
    }

    if (isMinHeap(not_heap)) {
        std::cout << "The given sequence is a min heap." << std::endl;
    } else {
        std::cout << "The given sequence is NOT a min heap." << std::endl;
    }

    return 0;
}
