class MyCircularQueue {
private:
    int size;
    vector<int> v;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()){
            v.push_back(value);
            return true;
        }
        else return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        v.erase(v.begin());
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        else return v.front();
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        else return v.back();
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(v.size() == 0) return true;
        else return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(v.size() == size)
            return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
