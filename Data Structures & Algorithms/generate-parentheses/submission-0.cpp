class Solution {
public:
    void function(int open,int close,int n,vector<string> &result,string &current){
        if(open==n && close==n){ 
            result.push_back(current);
            return;
        }
        if(open<n){
            current.push_back('(');
            function(open+1,close,n,result,current);
            current.pop_back();
        }
        if(close<open){
            current.push_back(')');
            function(open,close+1,n,result,current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> result;
       string current;
       function(0,0,n,result,current);
       return result; 
    }
};
