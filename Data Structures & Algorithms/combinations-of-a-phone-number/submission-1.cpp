class Solution {
public:
    void backtrack(string &current,int ind,string digits,vector<string> &result,vector<string> &phone){
        if(current.size()==digits.size()){
            result.push_back(current);
            return;
        }
        string letters = phone[digits[ind]-'0'];
        for(char c:letters){
            current.push_back(c);
            backtrack(current,ind+1,digits,result,phone);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> result;
        vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string current="";
        backtrack(current,0,digits,result,phone);
        return result;
    }
};
