class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      for(int i=0;i<tokens.size();i++){
        string c = tokens[i];
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            int result;
            if (tokens[i] == "+") result = first + second;
            else if (tokens[i] == "-") result = first - second;
            else if (tokens[i] == "*") result = first * second;
            else result = first / second;
            st.push(result);
        }
        else{
            st.push(stoi(tokens[i]));
        }
      }
      int result = st.top();
      return result;  
    }
};
