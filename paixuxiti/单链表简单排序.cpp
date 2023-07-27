#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* findMinNode(ListNode* prev) {
    ListNode* minNode = prev->next;
    ListNode* prevMin = prev;
    ListNode* current = prev->next->next;

    while (current) {
        if (current->val < minNode->val) {
            minNode = current;
            prevMin = prev;
        }
        prev = current;
        current = current->next;
    }

    return minNode;
}

ListNode* selectionSort(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* sortedTail = &dummy;
    while (sortedTail->next) {
        ListNode* minNode = findMinNode(sortedTail);
        ListNode* prevMin = findMinNode(sortedTail->next);
        if (minNode == prevMin) break; // If the minNode is already at the right position, we break.
        
        prevMin->next = minNode->next;
        minNode->next = sortedTail->next;
        sortedTail->next = minNode;
        sortedTail = minNode;
    }

    return dummy.next;
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int i = 0; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to convert a linked list to an array
int* linkedListToArray(ListNode* head, int& size) {
    int* arr = nullptr;
    ListNode* current = head;
    size = 0;

    while (current) {
        size++;
        current = current->next;
    }

    if (size > 0) {
        arr = new int[size];
        current = head;
        int index = 0;
        while (current) {
            arr[index++] = current->val;
            current = current->next;
        }
    }

    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {4, 2, 7, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* linkedList = createLinkedList(arr, size);

    ListNode* sortedLinkedList = selectionSort(linkedList);

    int sortedSize;
    int* sortedArray = linkedListToArray(sortedLinkedList, sortedSize);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < sortedSize; ++i) {
        std::cout << sortedArray[i] << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete[] sortedArray;
    while (sortedLinkedList) {
        ListNode* temp = sortedLinkedList;
        sortedLinkedList = sortedLinkedList->next;
        delete temp;
    }

    return 0;
}
