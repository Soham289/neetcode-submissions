class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l=0,r=n-1;
        while(l<r){
            while(l<r && !isalnum(s[l])) ++l;
            while(l<r && !isalnum(s[r])) --r;
            if(l<r){
                char cl = std::tolower(s[l]);
                char cr = std::tolower(s[r]);
                if(cl!=cr) return false;
                ++l;
                --r;
            }
        }
        return true;
    }
};