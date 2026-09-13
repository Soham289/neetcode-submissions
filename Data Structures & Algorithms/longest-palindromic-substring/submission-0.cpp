class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0,maxlen=1;
        for(int i=0;i<n;i++){
            int l=i,r=i; // Odd Length Palindrome
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen = r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            // Even Length Palindrome
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen = r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxlen);
    }
};
