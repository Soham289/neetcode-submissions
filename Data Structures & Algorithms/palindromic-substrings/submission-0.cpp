class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count=0;
        for (int i = 0; i < n; i++) {           
            for (int j = i; j < n; j++) {       
                string sub = s.substr(i, j - i + 1);
                if(isPalindrome(sub)) count++;
            }
        }
        return count;
    }
};
