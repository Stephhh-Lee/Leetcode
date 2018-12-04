class MinStack {
private:
    int iMim = INT_MAX;
    stack<int> smin;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if(smin.empty()) smin.push(x);
        else{
            iMim = min(smin.top(), x);
            smin.push(iMim);
        }
    }

    void pop() {
        s.pop();
        smin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
