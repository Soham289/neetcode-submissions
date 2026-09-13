class Solution {
public:
    void backtrack(const string& digits,const vector<string>& phone, int index,string& current, vector<string>& result){
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = phone[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, phone, index + 1, current, result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        vector<string> result;
        string current;
        vector<string> phone = {"","","abc", "def", "ghi", "jkl","mno", "pqrs","tuv","wxyz"};
        backtrack(digits, phone, 0, current, result);
        return result; 
    }
};
