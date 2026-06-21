#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> mn;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        if (mn.empty()) {
            mn.push(val);
        } else {
            mn.push(min(val, mn.top()));
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            mn.pop();
        }
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return st.top();
    }

    int getMin() {
        if (mn.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return mn.top();
    }
};

int main() {
    MinStack obj;

    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << "Minimum: " << obj.getMin() << endl;

    obj.pop();

    cout << "Top: " << obj.top() << endl;
    cout << "Minimum: " << obj.getMin() << endl;

    return 0;
}