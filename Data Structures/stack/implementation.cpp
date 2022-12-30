#include <iostream>
using namespace std;

#define MX 101

struct Stack {
    int top;
    int data[MX];

    Stack() {
        //cout << "what!" << endl;
        top = -1;
    }
    void push(int item) {
        if(top >= MX) {
            cout << "Stack is full" << endl;
        }
        else {
            top++;
            data[top] = item;
        }
    }
    void pop() {
        if(top == -1) {
            cout << "stack is already empty" << endl;
        }
        else
            top--;
    }
    int peek() {
        if(top == -1)return -1;
        return data[top];
    }
    bool is_empty() {
        return (top == -1);
    }
};

void print(struct Stack s) {
    while(!s.is_empty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
}
int main() {
    struct Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    print(st);
    cout << "top: " << st.peek() << endl;

    st.pop();
    st.pop();
    print(st);

    st.push(1);
    st.push(2);
    print(st);

    struct Stack st2;
    st2.pop();
}
