class MyQueue {
public:
    vector<int> q;
    MyQueue() {
        
    }
    
    void push(int x) {
        q.insert(q.begin(),x);
    }
    
    int pop() {
        int n = q.size();
        int x = q[n-1];
        q.pop_back();
        return x;
    }
    
    int peek() {
        int n = q.size();
        return q[n-1];
    }
    
    bool empty() {
        int n = q.size();
        return n==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */