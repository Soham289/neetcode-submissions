class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string op : operations) {
            if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1); // restore top1
                st.push(top1 + top2);
            } 
            else if (op == "C") {
                st.pop();
            } 
            else if (op == "D") {
                st.push(st.top() * 2);
            } 
            else { 
                // it's a number
                st.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
