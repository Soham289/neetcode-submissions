class MyStack {
public:
    vector<int> st;
    MyStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
    }
    
    int pop() {
       int n = st.size();
       int x = st[n-1];
       st.pop_back();
       return x;
    }
    
    int top() {
        int n = st.size();
        return st[n-1];
    }
    
    bool empty() {
        int n = st.size();
        return n==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */