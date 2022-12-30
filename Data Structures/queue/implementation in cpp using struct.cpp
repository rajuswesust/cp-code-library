#include <iostream>
using namespace std;

struct Queue {
    #define MX 100

    int head;
    int tail;
    int a[MX+1];

    Queue() {
        head = tail = 0;
    }

    bool is_empty() {
        return (head == tail);
    }

    void push(int x) {
        if((tail + 1) % (MX + 1) == head) {
            cout << "queue is already full" << endl;
            return;
        }
        a[tail] = x;
        tail = (tail + 1) % (MX+1);
    }

    void pop() {
        if(head == tail) cout << "queue is already empty" << endl;
        head = (head+1)%(MX+1);
    }

    int front() {
        if(head == tail) {
            cout << "queue is already empty" << endl;
            return -1;
        }
        return a[head];
    }
};

void print(struct Queue q) {
    while(!q.is_empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    struct Queue q1, q2;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    print(q1);

    q2 = q1;
    print(q2);

    cout << "front element of q2: " << q2.front() << endl;
    q2.pop();
    cout << "front element of q2: " << q2.front() << endl;
    q2.pop();
    cout << "front element of q2: " << q2.front() << endl;
    q2.pop();
    cout << "front element of q2: " << q2.front() << endl;
}

