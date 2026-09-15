class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                int l1=l+1,r1=r;
                int l2=l,r2=r-1;
                while(l1<r1 && s[l1]==s[r1]){
                    l1++;
                    r1--;
                }
                if(l1>=r1) return true;
                while(l2<r2 && s[l2]==s[r2]){
                    l2++;
                    r2--;
                }
                if(l2>=r2) return true;
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};