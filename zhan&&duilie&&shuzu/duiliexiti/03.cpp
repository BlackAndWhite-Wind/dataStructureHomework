// 用两个栈来实现队列

#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> S1; // 入队栈
    stack<int> S2; // 出队栈

public:
    void enqueue(int value) {
        S1.push(value);
    }

    int dequeue() {
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }

        int dequeuedValue = -1; // 假设队列为空时返回-1，可根据需要修改
        if (!S2.empty()) {
            dequeuedValue = S2.top();
            S2.pop();
        }

        return dequeuedValue;
    }

    bool is_empty() {
        return S1.empty() && S2.empty();
    }
};


int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

    queue.enqueue(4);

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

    return 0;
}