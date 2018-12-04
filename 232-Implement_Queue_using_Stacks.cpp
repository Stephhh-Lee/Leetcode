class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                int n = in.top();
                out.push(n);
                in.pop();
            }
        }
        int n = out.top();
        out.pop();
        return n;
    }

    /** Get the front element. */
    int peek() {
        if(out.empty()){
            while(!in.empty()){
                int n = in.top();
                out.push(n);
                in.pop();
            }
        }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(out.empty() && in.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
